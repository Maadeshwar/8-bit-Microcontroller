import os

template = """
ifneq ($(GATES),yes)
VERILOG_SOURCES += ../../src/tt_um_micro.v
VERILOG_SOURCES += ../../src/cpu_core.v
VERILOG_SOURCES += ../../src/uart.v
else
COMPILE_ARGS    += -DGL_TEST
COMPILE_ARGS    += -DFUNCTIONAL
COMPILE_ARGS    += -DUSE_POWER_PINS
COMPILE_ARGS    += -DSIM
COMPILE_ARGS    += -DUNIT_DELAY=\#1
VERILOG_SOURCES += $(PDK_ROOT)/sky130A/libs.ref/sky130_fd_sc_hd/verilog/primitives.v
VERILOG_SOURCES += $(PDK_ROOT)/sky130A/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v
VERILOG_SOURCES += ../gate_level_netlist.v
endif
"""

for root, dirs, files in os.walk('test'):
    if 'Makefile' in files and root != 'test':
        filepath = os.path.join(root, 'Makefile')
        with open(filepath, 'r') as f:
            content = f.read()
        
        old_block = "VERILOG_SOURCES += ../../src/tt_um_micro.v\nVERILOG_SOURCES += ../../src/cpu_core.v\nVERILOG_SOURCES += ../../src/uart.v"
        if old_block in content:
            new_content = content.replace(old_block, template.strip())
            with open(filepath, 'w') as f:
                f.write(new_content)
            print(f'Patched {filepath}')
