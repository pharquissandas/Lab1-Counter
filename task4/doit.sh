#!/bin/bash

# Run Verilator to compile the design
verilator --cc top.sv counter.sv bin2bcd.sv --trace --exe top_tb.cpp

# Build the simulation model
make -C obj_dir -j -f Vtop.mk Vtop

# Run the simulation
./obj_dir/Vtop
