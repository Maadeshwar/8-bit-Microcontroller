SIM ?= icarus
TOPLEVEL_LANG ?= verilog
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
VERILOG_SOURCES += $(PDK_ROOT)/ihp-sg13g2/libs.ref/sg13g2_io/verilog/sg13g2_io.v
VERILOG_SOURCES += $(PDK_ROOT)/ihp-sg13g2/libs.ref/sg13g2_stdcell/verilog/sg13g2_stdcell.v
VERILOG_SOURCES += ../gate_level_netlist.v
endif
TOPLEVEL = tt_um_micro
MODULE = tb_func_design

# Maximize log output
export COCOTB_LOG_LEVEL = DEBUG

# Export PATH so cocotb-config works
export PATH := $(HOME)/.local/bin:$(PATH)

include $(shell PATH="$(HOME)/.local/bin:$(PATH)" cocotb-config --makefiles)/Makefile.sim
