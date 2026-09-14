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
async def test_isa(dut):
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    program = [
        0x01, 0x42, # 00: LDI 0x42
        0x03, 0x00, # 02: STR at addr 0x00 (RAM[0] = 0x42)
        0x01, 0x0F, # 04: LDI 0x0F 
        0x03, 0x01, # 06: STR at addr 0x01 (RAM[1] = 0x0F)
        0x01, 0x02, # 08: LDI 0x02 
        0x03, 0x02, # 0A: STR at addr 0x02 (RAM[2] = 0x02)
        
        0x01, 0xFF, # 0C: LDI 0xFF
        0x08, 0x00, # 0E: AND RAM[0] (0xFF & 0x42 = 0x42)
        0x09, 0x01, # 10: OR RAM[1]  (0x42 | 0x0F = 0x4F)
        0x0A, 0x00, # 12: XOR RAM[0] (0x4F ^ 0x42 = 0x0D)
        
        0x0B, 0x02, # 14: SHL by RAM[2] (0x0D << 2 = 0x34)
        0x0C, 0x02, # 16: SHR by RAM[2] (0x34 >> 2 = 0x0D)
        
        0x04, 0x00, # 18: ADD RAM[0] (0x0D + 0x42 = 0x4F)
        0x05, 0x01, # 1A: SUB RAM[1] (0x4F - 0x0F = 0x40)
        
        0x02, 0x00, # 1C: LDR RAM[0] (ACC = 0x42)
        
        0x01, 0x00, # 1E: LDI 0x00
        0x07, 0x24, # 20: JZ 0x24 (Jump to 0x24)
        0x06, 0x00, # 22: JMP 0x00 (Should be skipped)
        0x01, 0xFF, # 24: LDI 0xFF (At 0x24)
        0x00        # 26: NOP
    ]
    
    async def memory_model():
        while True:
            await Timer(1, "ns")
            try:
                pc = int(dut.uo_out.value)
                if pc < len(program):
                    dut.ui_in.value = program[pc]
                else:
                    dut.ui_in.value = 0
            except ValueError:
                dut.ui_in.value = 0
                
    cocotb.start_soon(memory_model())
    await reset(dut)
    
    from cocotb_coverage.coverage import CoverPoint, coverage_db
    
    @CoverPoint("top.opcode", vname="opcode", bins=list(range(13)))
    def sample_opcode(opcode):
        pass

    for _ in range(70):
        await RisingEdge(dut.clk)
        sample_opcode(int(dut.core.ir.value))
        
    await ClockCycles(dut.clk, 10)
    
    assert dut.core.acc.value == 0xFF, f"ACC is {dut.core.acc.value}, expected 0xFF"
    coverage_db.export_to_xml(filename="functional_coverage.xml")
    dut._log.info("ISA test passed successfully with coverage!")
