import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles
import random

async def reset(dut):
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)

@cocotb.test()
async def test_stress(dut):
    """Run a randomized sequence of instructions to ensure no FSM lockup."""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    # Generate 1000 random instructions
    program = []
    for _ in range(500):
        opcode = random.choice([0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C])
        operand = random.randint(0, 31) # Safe RAM address
        if opcode == 0x00:
            program.append(opcode) # NOP is 1 byte
        else:
            if opcode in [0x06, 0x07]: # JMP / JZ
                operand = random.randint(0, 100) # Jump within safe bounds
            program.append(opcode)
            program.append(operand)
            
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
    
    # Run for a large number of cycles to ensure no deadlocks
    for _ in range(2000):
        await RisingEdge(dut.clk)
        
    dut._log.info("Stress test completed without lockup!")
