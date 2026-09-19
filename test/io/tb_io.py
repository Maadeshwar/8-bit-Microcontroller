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
    cocotb.start_soon(Clock(dut.clk, 20, unit="ns").start())
    
    # gpio_out and gpio_dir are 5-bit registers (uio[4:0]).
    # uio[5] = UART TX (always output, idle-high), uio[6] = UART RX (always input),
    # uio[7] = PWM (always output). GPIO is only uio[4:0].
    program = [
        0x01, 0x1F, # 00: LDI 0x1F (set all 5 GPIO pins to output)
        0x03, 0x21, # 02: STR 0x21 (GPIO_DIR = 0x1F)
        0x01, 0x15, # 04: LDI 0x15 (5-bit pattern 10101 on GPIO)
        0x03, 0x20, # 06: STR 0x20 (GPIO_OUT = 0x15)
        0x02, 0x20, # 08: LDR 0x20 (Read GPIO_IN into ACC)
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

    dut.uio_in.value = 0x0A  # Complementary pattern 01010 on GPIO inputs

    await ClockCycles(dut.clk, 40)

    # uio[4:0] are GPIO - check against the 5-bit pattern written (0x15)
    gpio_out_bits = int(dut.uio_out.value) & 0x1F
    assert gpio_out_bits == 0x15, f"GPIO output bits [4:0] failed: got {hex(gpio_out_bits)}, expected 0x15"

    # uio_oe[4:0] must all be 1 (GPIO_DIR = 0x1F, all output)
    gpio_oe_bits = int(dut.uio_oe.value) & 0x1F
    assert gpio_oe_bits == 0x1F, f"GPIO direction bits [4:0] failed: got {hex(gpio_oe_bits)}, expected 0x1F"

    # uio_oe[5] (UART TX) is hardwired output regardless of GPIO_DIR
    uart_tx_oe = (int(dut.uio_oe.value) >> 5) & 0x1
    assert uart_tx_oe == 1, "UART TX output enable must always be 1"

    # uio_oe[6] (UART RX) is hardwired input regardless of GPIO_DIR
    uart_rx_oe = (int(dut.uio_oe.value) >> 6) & 0x1
    assert uart_rx_oe == 0, "UART RX output enable must always be 0"

    # uio_oe[7] (PWM) is hardwired output regardless of GPIO_DIR
    pwm_oe = (int(dut.uio_oe.value) >> 7) & 0x1
    assert pwm_oe == 1, "PWM output enable must always be 1"

    dut._log.info("IO test passed successfully!")
