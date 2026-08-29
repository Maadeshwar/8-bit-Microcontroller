SIM ?= icarus
TOPLEVEL_LANG ?= verilog
VERILOG_SOURCES += $(PWD)/../../src/tt_um_micro.v
VERILOG_SOURCES += $(PWD)/../../src/cpu_core.v
VERILOG_SOURCES += $(PWD)/../../src/uart.v
TOPLEVEL = tt_um_micro
MODULE = tb_isa

# Maximize log output
export COCOTB_LOG_LEVEL = DEBUG

# Export PATH so cocotb-config works
export PATH := $(HOME)/.local/bin:$(PATH)

include $(shell PATH="$(HOME)/.local/bin:$(PATH)" cocotb-config --makefiles)/Makefile.sim
