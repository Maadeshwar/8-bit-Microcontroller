import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer

async def reset(dut):
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 0
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)

@cocotb.test()
async def test_peripheral(dut):
    """Test UART TX and Hardware Timer"""
    # 50MHz clock -> 20ns
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    # 1. Reset Timer
    # 2. Wait some cycles
    # 3. Read Timer
    # 4. Transmit 'A' (0x41) over UART
    program = [
        0x03, 0x22, # 00: STR 0x22 (Reset Timer)
        0x00,       # 02: NOP
        0x00,       # 03: NOP
        0x00,       # 04: NOP
        0x02, 0x22, # 05: LDR 0x22 (Read Timer into ACC)
        0x01, 0x41, # 07: LDI 0x41 ('A')
        0x03, 0x24, # 09: STR 0x24 (Send over UART)
        0x06, 0x0B, # 0B: JMP to self
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
    
    # Monitor UART TX pin (uio_out[7])
    # Wait for start bit (goes low)
    while True:
        await RisingEdge(dut.clk)
        if (int(dut.uio_out.value) & 0x20) == 0:
            break
            
    dut._log.info("UART Start bit detected!")
    
    # Baud rate is 115200 at 50MHz => 434 clocks per bit
    # Wait half a bit period to sample in the middle
    await ClockCycles(dut.clk, 217)
    
    # Read 8 data bits
    rx_byte = 0
    for i in range(8):
        await ClockCycles(dut.clk, 434)
        bit = (int(dut.uio_out.value) & 0x20) >> 5
        rx_byte |= (bit << i)
        
    dut._log.info(f"Received UART byte: {hex(rx_byte)}")
    assert rx_byte == 0x41, f"UART TX failed! Expected 0x41, got {hex(rx_byte)}"
    
    dut._log.info("Peripheral test passed!")

@cocotb.test()
async def test_pwm(dut):
    '''Test PWM Output'''
    cocotb.start_soon(Clock(dut.clk, 20, units='ns').start())
    
    # Write 0x04 (4) to PWM_DUTY (0x26)
    program = [
        0x01, 0x04, # LDI 0x04
        0x03, 0x26, # STR 0x26
        0x06, 0x04  # JMP self
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
    
    # Wait for PWM duty to be set
    await ClockCycles(dut.clk, 20)
    
    # PWM counter is 4-bit, so it rolls over every 16 cycles. (Over 256 cycles, it repeats 16 times)
    # Measure how many cycles uio_out[7] is high over 256 cycles.
    high_cycles = 0
    for _ in range(256):
        await RisingEdge(dut.clk)
        if (int(dut.uio_out.value) & 0x80) != 0:
            high_cycles += 1
            
    dut._log.info(f'PWM High Cycles: {high_cycles}')
    assert high_cycles == 4, f'PWM failed! Expected 64 high cycles, got {high_cycles}'

