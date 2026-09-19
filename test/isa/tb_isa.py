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
    cocotb.start_soon(Clock(dut.clk, 20, unit="ns").start())

    program = [
        0x01, 0x42, # 00: LDI 0x42
        0x03, 0x00, # 02: STR RAM[0] = 0x42
        0x01, 0x0F, # 04: LDI 0x0F
        0x03, 0x01, # 06: STR RAM[1] = 0x0F
        0x01, 0x02, # 08: LDI 0x02
        0x03, 0x02, # 0A: STR RAM[2] = 0x02

        0x01, 0xFF, # 0C: LDI 0xFF
        0x08, 0x00, # 0E: AND RAM[0] (0xFF & 0x42 = 0x42)
        0x09, 0x01, # 10: OR  RAM[1] (0x42 | 0x0F = 0x4F)
        0x0A, 0x00, # 12: XOR RAM[0] (0x4F ^ 0x42 = 0x0D)

        0x0B, 0x02, # 14: SHL by RAM[2] (0x0D << 2 = 0x34)
        0x0C, 0x02, # 16: SHR by RAM[2] (0x34 >> 2 = 0x0D)

        0x04, 0x00, # 18: ADD RAM[0] (0x0D + 0x42 = 0x4F)
        0x05, 0x01, # 1A: SUB RAM[1] (0x4F - 0x0F = 0x40)

        0x02, 0x00, # 1C: LDR RAM[0] (ACC = 0x42)

        0x01, 0x00, # 1E: LDI 0x00        -> flag_z=1
        0x07, 0x24, # 20: JZ  0x24        -> jumps (flag_z=1)
        0x06, 0x00, # 22: JMP 0x00        (skipped)
        0x01, 0xFF, # 24: LDI 0xFF        -> flag_z=0

        0x0D, 0x2A, # 26: CALL 0x2A      -> ret_addr=0x28, jump to subroutine
        0x06, 0x2E, # 28: JMP 0x2E       (after RET returns here, skip to flag tests)

        0x01, 0xAA, # 2A: LDI 0xAA       (subroutine body)
        0x0E, 0x00, # 2C: RET            -> pc = ret_addr = 0x28

        # --- Flag tests: JC and JNZ ---
        # 0x01 + 0xFF = 0x100 -> acc=0x00, carry=1, zero=1
        0x01, 0x01, # 2E: LDI 0x01
        0x03, 0x03, # 30: STR RAM[3] = 0x01
        0x01, 0xFF, # 32: LDI 0xFF
        0x04, 0x03, # 34: ADD RAM[3]     -> acc=0x00, flag_c=1, flag_z=1
        0x10, 0x3A, # 36: JC  0x3A      -> jumps (flag_c=1)
        0x06, 0x00, # 38: JMP 0x00       (skipped)

        0x01, 0x05, # 3A: LDI 0x05      -> flag_z=0
        0x0F, 0x40, # 3C: JNZ 0x40      -> jumps (flag_z=0)
        0x06, 0x00, # 3E: JMP 0x00       (skipped)

        0x01, 0xBB, # 40: LDI 0xBB      -> final value
        0x00,       # 42: NOP
    ]

    async def memory_model():
        while True:
            await Timer(1, "ns")
            try:
                pc = int(dut.uo_out.value)
                dut.ui_in.value = program[pc] if pc < len(program) else 0
            except ValueError:
                dut.ui_in.value = 0

    cocotb.start_soon(memory_model())
    await reset(dut)

    import os
    is_gl = os.environ.get("GATES") == "yes"

    try:
        from cocotb_coverage.coverage import CoverPoint, coverage_db
        _coverage_available = True
    except ImportError:
        _coverage_available = False

    if not is_gl and _coverage_available:
        @CoverPoint("top.opcode", vname="opcode", bins=list(range(17)))
        def sample_opcode(opcode):
            pass
    else:
        def sample_opcode(opcode):
            pass

    for _ in range(140):
        await RisingEdge(dut.clk)
        if not is_gl:
            sample_opcode(int(dut.core.ir.value))

    await ClockCycles(dut.clk, 10)

    if not is_gl:
        assert dut.core.acc.value == 0xBB, f"ACC is {hex(int(dut.core.acc.value))}, expected 0xBB"
        assert dut.core.flag_c.value == 0, f"flag_c should be 0 after LDI, got {dut.core.flag_c.value}"
        assert dut.core.flag_z.value == 0, f"flag_z should be 0 after LDI 0xBB, got {dut.core.flag_z.value}"
        if _coverage_available:
            coverage_db.export_to_xml(filename="functional_coverage.xml")
    dut._log.info("ISA test passed successfully!")

