import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ClockCycles, Timer

BAUD_CONFIGS = [
    (434,  20.0, 115200, 5.0), # 50 MHz
    ( 87, 100.0, 115200, 5.0), # 10 MHz
    (5208, 20.0,   9600, 5.0), # 50 MHz -> 9600 baud
]

async def reset_dut(dut, period_ns):
    dut.ena.value    = 1
    dut.ui_in.value  = 0
    dut.uio_in.value = 0
    dut.rst_n.value  = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value  = 1
    await ClockCycles(dut.clk, 2)

async def memory_model(dut, program):
    while True:
        await Timer(1, "ns")
        try:
            pc = int(dut.uo_out.value)
            dut.ui_in.value = program[pc] if pc < len(program) else 0
        except ValueError:
            dut.ui_in.value = 0

async def measure_start_bit_cycles(dut, timeout=20000):
    for _ in range(timeout):
        await RisingEdge(dut.clk)
        if ((int(dut.uio_out.value) >> 5) & 1) == 0:
            break
    else:
        raise AssertionError("TX start bit not detected")
    count = 0
    for _ in range(15000):
        await RisingEdge(dut.clk)
        count += 1
        if ((int(dut.uio_out.value) >> 5) & 1) == 1:
            break
    return count

@cocotb.test()
async def test_baud_50mhz_115200_default(dut):
    """Test 50MHz default clock/baud from reset"""
    div, period_ns, target, tol = BAUD_CONFIGS[0]
    cocotb.start_soon(Clock(dut.clk, period_ns, unit="ns").start())
    
    prog = [
        0x01, 0x55,     # LDI 0x55
        0x03, 0x24,     # STR 0x24 (TX)
        0x00, 0x00      # NOP
    ]
    cocotb.start_soon(memory_model(dut, prog))
    await reset_dut(dut, period_ns)
    
    await ClockCycles(dut.clk, 1)
    cycles = await measure_start_bit_cycles(dut)
    baud = 1.0 / (cycles * period_ns * 1e-9)
    err  = abs(baud - target) / target * 100
    dut._log.info(f"50 MHz default: {cycles} cyc, {baud:.0f} baud, err={err:.2f}%")
    assert abs(cycles - div) <= 2 and err < tol, f"FAIL: div={cycles}, err={err:.2f}%"

@cocotb.test()
async def test_baud_10mhz_115200(dut):
    """Test 10MHz clock targeting 115200 baud"""
    div, period_ns, target, tol = BAUD_CONFIGS[1]
    cocotb.start_soon(Clock(dut.clk, period_ns, unit="ns").start())
    
    div_low = div & 0xFF
    div_high = (div >> 8) & 0xFF
    prog = [
        0x01, div_low,  # LDI div_low
        0x03, 0x28,     # STR 0x28
        0x01, div_high, # LDI div_high
        0x03, 0x29,     # STR 0x29
        0x01, 0x55,     # LDI 0x55
        0x03, 0x24,     # STR 0x24
        0x00, 0x00      # NOP
    ]
    cocotb.start_soon(memory_model(dut, prog))
    await reset_dut(dut, period_ns)
    
    await ClockCycles(dut.clk, 1)
    cycles = await measure_start_bit_cycles(dut)
    baud = 1.0 / (cycles * period_ns * 1e-9)
    err  = abs(baud - target) / target * 100
    dut._log.info(f"10 MHz custom: {cycles} cyc, {baud:.0f} baud, err={err:.2f}%")
    assert abs(cycles - div) <= 2 and err < tol, f"FAIL: div={cycles}, err={err:.2f}%"

@cocotb.test()
async def test_baud_50mhz_9600(dut):
    """Test 50MHz clock targeting 9600 baud"""
    div, period_ns, target, tol = BAUD_CONFIGS[2]
    cocotb.start_soon(Clock(dut.clk, period_ns, unit="ns").start())
    
    div_low = div & 0xFF
    div_high = (div >> 8) & 0xFF
    prog = [
        0x01, div_low,  # LDI div_low
        0x03, 0x28,     # STR 0x28
        0x01, div_high, # LDI div_high
        0x03, 0x29,     # STR 0x29
        0x01, 0x55,     # LDI 0x55
        0x03, 0x24,     # STR 0x24
        0x00, 0x00      # NOP
    ]
    cocotb.start_soon(memory_model(dut, prog))
    await reset_dut(dut, period_ns)
    
    await ClockCycles(dut.clk, 1)
    cycles = await measure_start_bit_cycles(dut, timeout=20000)
    baud = 1.0 / (cycles * period_ns * 1e-9)
    err  = abs(baud - target) / target * 100
    dut._log.info(f"50 MHz 9600 baud: {cycles} cyc, {baud:.0f} baud, err={err:.2f}%")
    assert abs(cycles - div) <= 2 and err < tol, f"FAIL: div={cycles}, err={err:.2f}%"
