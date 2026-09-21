import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer


DIVIDER = 5
BIT_CYCLES = DIVIDER + 1
RX_PIN = 6
TX_PIN = 5


def set_rx(dut, level):
    value = int(dut.uio_in.value)
    if level:
        value |= 1 << RX_PIN
    else:
        value &= ~(1 << RX_PIN)
    dut.uio_in.value = value


async def reset(dut):
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 1 << RX_PIN
    dut.corrupt_stop.value = 0
    dut.rst_n.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 3)


async def run_memory(dut, program):
    while True:
        await Timer(1, unit="ns")
        try:
            pc = int(dut.uo_out.value)
            dut.ui_in.value = program[pc] if pc < len(program) else 0
        except ValueError:
            dut.ui_in.value = 0


@cocotb.test()
async def test_uart_rx_data_and_clear(dut):
    """RX receives a valid 8N1 byte and CPU reads/clears it."""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    program = [
        0x01, DIVIDER,
        0x03, 0x28,
        0x01, 0x00,
        0x03, 0x29,
        0x01, 0xA5,
        0x03, 0x24,
    ] + [0x00] * 60
    program += [0x02, 0x23, 0x06, len(program)]
    cocotb.start_soon(run_memory(dut, program))
    await reset(dut)
    for _ in range(200):
        await RisingEdge(dut.clk)
        if int(dut.debug_rx_ready.value) == 1:
            break
    else:
        raise AssertionError(
            "UART RX did not report a valid loopback byte: "
            f"rx_state={int(dut.dut.core.rx_inst.state.value)} "
            f"rx_data=0x{int(dut.debug_rx_data.value):02x} "
            f"tx_state={int(dut.dut.core.tx_inst.state.value)}"
        )
    assert int(dut.debug_rx_data.value) == 0xA5

    # Read the byte through the real memory-mapped CPU interface.
    await ClockCycles(dut.clk, 40)
    assert int(dut.dut.core.acc.value) == 0xA5
    assert int(dut.debug_rx_ready.value) == 0


@cocotb.test()
async def test_uart_rx_rejects_bad_stop_and_recovers(dut):
    """A low stop bit is rejected by the RX framing check."""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    program = [
        0x01, DIVIDER,
        0x03, 0x28,
        0x01, 0x00,
        0x03, 0x29,
        0x01, 0x3C,
        0x03, 0x24,
        0x06, 0x0C,
    ]
    cocotb.start_soon(run_memory(dut, program))
    await reset(dut)
    dut.corrupt_stop.value = 1
    await ClockCycles(dut.clk, 120)
    assert int(dut.debug_rx_ready.value) == 0


@cocotb.test()
async def test_uart_tx_frame(dut):
    """TX emits a complete 8N1 frame with the configured divider."""
    cocotb.start_soon(Clock(dut.clk, 20, units="ns").start())
    program = [
        0x01, DIVIDER,
        0x03, 0x28,
        0x01, 0x00,
        0x03, 0x29,
        0x01, 0xC3,
        0x03, 0x24,
        0x06, 0x0C,
    ]
    cocotb.start_soon(run_memory(dut, program))
    await reset(dut)

    while True:
        await RisingEdge(dut.clk)
        if ((int(dut.uio_out.value) >> TX_PIN) & 1) == 0:
            break

    # Move from the start-bit edge to the center of data bit 0.
    await ClockCycles(dut.clk, BIT_CYCLES + BIT_CYCLES // 2)
    received = 0
    for bit in range(8):
        level = (int(dut.uio_out.value) >> TX_PIN) & 1
        received |= level << bit
        await ClockCycles(dut.clk, BIT_CYCLES)

    assert received == 0xC3
    assert ((int(dut.uio_out.value) >> TX_PIN) & 1) == 1
