#!/bin/bash
set -e
verilator --cc --exe --build -j 0 -Wall -Wno-fatal --coverage-line \
  --top-module tt_um_micro \
  ../../src/tt_um_micro.v ../../src/cpu_core.v ../../src/uart.v \
  sim_main.cpp

./obj_dir/Vtt_um_micro
verilator_coverage --annotate annotated_logs coverage.dat
echo "Coverage generated in annotated_logs/"
