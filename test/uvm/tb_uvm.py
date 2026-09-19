import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles

# A minimal UVM-like structure using standard Cocotb
class Driver:
    def __init__(self, dut):
        self.dut = dut
        self.program = [0x01, 0xAA, 0x03, 0x24] # LDI 0xAA, STR 0x24 (UART TX)
        
    async def run(self):
        from cocotb.triggers import Timer
        while True:
            await Timer(1, "ns")
            try:
                pc = int(self.dut.uo_out.value)
                if pc < len(self.program):
                    self.dut.ui_in.value = self.program[pc]
                else:
                    self.dut.ui_in.value = 0
            except ValueError:
                self.dut.ui_in.value = 0

class Monitor:
    def __init__(self, dut):
        self.dut = dut
        self.transactions = []
        
    async def run(self):
        while True:
            await RisingEdge(self.dut.clk)
            try:
                if int(self.dut.core.tx_start.value) == 1:
                    self.transactions.append(int(self.dut.core.acc.value))
            except ValueError:
                pass

class Scoreboard:
    def check(self, transactions):
        expected = [0xAA]
        assert transactions == expected, f"Scoreboard mismatch! Got {transactions}, expected {expected}"

@cocotb.test()
async def test_uvm(dut):
    """Small UVM-like test environment"""
    cocotb.start_soon(Clock(dut.clk, 20, unit="ns").start())
    
    driver = Driver(dut)
    monitor = Monitor(dut)
    scoreboard = Scoreboard()
    
    cocotb.start_soon(driver.run())
    cocotb.start_soon(monitor.run())
    
    dut.ena.value = 1
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    
    await ClockCycles(dut.clk, 100)
    
    scoreboard.check(monitor.transactions)
    dut._log.info("UVM-style test passed!")
