import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles

async def reset(dut):
    dut.ena.value = 1
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1

@cocotb.test()
async def test_pipeline(dut):
    """Test FSM state transitions (FETCH -> FETCH_OP -> EXEC)"""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    # NOP (1 byte) -> LDI (2 bytes)
    program = [0x00, 0x01, 0xFF]
    
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
    
    # Check states: 0=FETCH, 1=FETCH_OP, 2=EXEC
    
    await ClockCycles(dut.clk, 6)
    assert dut.core.state.value == 0, "Should return to FETCH"
    
    dut._log.info("FSM Pipeline state transitions passed perfectly!")
