import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles

async def reset(dut):
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 0
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)

@cocotb.test()
async def test_io(dut):
    """Test memory-mapped GPIO (direction and data)"""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    program = [
        0x01, 0x3F, # 00: LDI 0x3F (All 6 GPIO pins = 1)
        0x03, 0x21, # 02: STR 0x21 (Write to GPIO_DIR, set all to output)
        0x01, 0x2A, # 04: LDI 0x2A (Pattern 101010)
        0x03, 0x20, # 06: STR 0x20 (Write to GPIO_OUT)
        0x02, 0x20, # 08: LDR 0x20 (Read from GPIO_IN)
    ]
    
    async def memory_model():
        while True:
            from cocotb.triggers import Timer
            await Timer(1, 'ns')
            try:
                pc = int(dut.uo_out.value)
                if pc < len(program):
                    dut.ui_in.value = program[pc]
                else:
                    dut.ui_in.value = 0
            except ValueError:
                pass
                
    cocotb.start_soon(memory_model())
    await reset(dut)
    
    # Drive some inputs on the GPIO pins
    dut.uio_in.value = 0x15 # Pattern 010101
    
    await ClockCycles(dut.clk, 40)
    
    # Verify GPIO output pins are driven according to the pattern
    # uio_out has TX on bit 7, 0 on bit 6, GPIO on 5:0
    uio_out_val = int(dut.uio_out.value) & 0x3F
    assert uio_out_val == 0x2A, f"GPIO Out failed, got {hex(uio_out_val)}"
    
    # Verify Direction
    uio_oe_val = int(dut.uio_oe.value) & 0x3F
    assert uio_oe_val == 0x3F, "GPIO Dir failed"
    
    dut._log.info("IO test passed successfully!")
