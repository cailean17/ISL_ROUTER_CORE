# Makefile
# Get the absolute path of the parent directory (my_project)
PROJECT_ROOT = $(abspath ..)

# Append the project root to the Python path environment variable
export PYTHONPATH := $(PROJECT_ROOT):$(PYTHONPATH)
# defaults
SIM ?= verilator
EXTRA_ARGS += --trace --trace-fst --trace-structs
TOPLEVEL_LANG ?= verilog
COMPILE_ARGS += -Wno-fatal
EXTRA_ARGS += --coverage

RTL_ROOT = ../../RTL

VERILOG_SOURCES += $(RTL_ROOT)/packets_and_frames.sv
VERILOG_SOURCES += $(RTL_ROOT)/CRC.sv
VERILOG_SOURCES += $(RTL_ROOT)/link_adapter_tx.sv
# use VHDL_SOURCES for VHDL files

# COCOTB_TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
COCOTB_TOPLEVEL = link_adapter_tx

# COCOTB_TEST_MODULES is the basename of the Python test file(s)
COCOTB_TEST_MODULES = link_adapter_tx_coco_tb

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim
