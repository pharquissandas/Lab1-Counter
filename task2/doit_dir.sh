#!/bin/bash

# Ensure task folder exists (optional)
mkdir -p task_dir

# Step 1: Translate Verilog to C++ and link testbench
verilator -Wall --cc --trace counter_dir.sv --exe counter_dir_tb.cpp vbuddy.cpp

# Step 2: Build executable using Verilator-generated Makefile
make -j -C obj_dir/ -f Vcounter_dir.mk Vcounter_dir

# Step 3: Run simulation
./obj_dir/Vcounter_dir

echo "Simulation complete. TFT displays counter, push-button toggles direction."
