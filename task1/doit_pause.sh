#!/bin/bash
verilator -Wall --cc --trace counter.sv --exe counter_tb_pause.cpp
make -j -C obj_dir/ -f Vcounter.mk Vcounter
obj_dir/Vcounter