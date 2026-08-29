import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles

async def reset(dut):
    dut.ena.value = 1
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)

@cocotb.test()
async def test_func_design(dut):
    """End-to-end application: Calculate sum of numbers 1 to 5 and store to RAM"""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    
    # Assembly logic:
    # RAM[0] = Sum (initially 0)
    # RAM[1] = Counter (initially 5)
    # Loop:
    # LDR RAM[1]
    # JZ End
    # ADD RAM[0]
    # STR RAM[0]
    # LDR RAM[1]
    # SUB Immediate 1
    # STR RAM[1]
    # JMP Loop
    
    program = [
        # Init RAM[0] = 0
        0x01, 0x00, # LDI 0
        0x03, 0x00, # STR 0x00
        # Init RAM[1] = 5
        0x01, 0x05, # LDI 5
        0x03, 0x01, # STR 0x01
        
        # Loop start (Address 0x08)
        0x02, 0x01, # LDR 0x01 (Load counter)
        0x07, 0x16, # JZ 0x16 (If counter == 0, jump to end)
        
        0x04, 0x00, # ADD 0x00 (Add sum)
        0x03, 0x00, # STR 0x00 (Store new sum)
        
        0x02, 0x01, # LDR 0x01 (Load counter)
        0x05, 0xFF, # SUB (Wait, our SUB subtracts from RAM. We don't have SUB IMM)
        # Ah, we need a constant 1 in RAM.
        # Let's rewrite program
    ]
    
    # Revised program:
    # RAM[0] = Sum (0)
    # RAM[1] = Counter (5)
    # RAM[2] = Constant (1)
    program = [
        0x01, 0x00, 0x03, 0x00, # Init Sum = 0
        0x01, 0x05, 0x03, 0x01, # Init Counter = 5
        0x01, 0x01, 0x03, 0x02, # Init Const = 1
        
        # Loop (0x0C)
        0x02, 0x01, # LDR Counter
        0x07, 0x1A, # JZ End (0x1A)
        
        0x04, 0x00, # ADD Sum
        0x03, 0x00, # STR Sum
        
        0x02, 0x01, # LDR Counter
        0x05, 0x02, # SUB Const (1)
        0x03, 0x01, # STR Counter
        
        0x06, 0x0C, # JMP Loop
        
        # End (0x1A)
        0x06, 0x1A  # Infinite loop
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
    
    await ClockCycles(dut.clk, 300)
    
    # 5 + 4 + 3 + 2 + 1 = 15 (0x0F)
    sum_result = int(dut.core.ram[0].value)
    assert sum_result == 0x0F, f"Functional test failed, expected 15, got {sum_result}"
    
    dut._log.info("Functional Design Test (Sum 1..5) passed perfectly!")
