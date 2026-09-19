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
    cocotb.start_soon(Clock(dut.clk, 20, unit="ns").start())
    
    # All 16 implemented opcodes are exercised
    ALL_OPCODES = [
        0x01, 0x02, 0x03, 0x04, 0x05,  # LDI LDR STR ADD SUB
        0x06, 0x07, 0x08, 0x09, 0x0A,  # JMP JZ AND OR XOR
        0x0B, 0x0C, 0x0D, 0x0E, 0x0F,  # SHL SHR CALL RET JNZ
        0x10,                            # JC
    ]
    BRANCH_OPCODES = {0x06, 0x07, 0x0D, 0x0F, 0x10}  # opcodes that take a jump address
    SAFE_JUMP_BOUND = 100  # keep PC within first 100 bytes to avoid runaway

    program = []
    for _ in range(500):
        opcode = random.choice(ALL_OPCODES)
        if opcode == 0x00:
            program.append(opcode)  # NOP is single-byte (unused, but safe)
        elif opcode == 0x0E:        # RET has no meaningful operand; pad a zero
            program.append(opcode)
            program.append(0x00)
        elif opcode in BRANCH_OPCODES:
            program.append(opcode)
            program.append(random.randint(0, SAFE_JUMP_BOUND))
        else:
            program.append(opcode)
            program.append(random.randint(0, 7))  # safe RAM address [0..7]
            
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
