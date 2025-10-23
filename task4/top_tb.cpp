#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);

    // Instantiate the top-level module
    Vtop *top = new Vtop;

    // Open the VCD file for waveform generation
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    // Initialize simulation variables
    bool clk = 0;
    bool rst = 0;
    bool en = 0;
    uint8_t v = 100; // Preload value for the counter

    // Simulation loop
    for (int i = 0; i < 1000; i++)
    {
        // Toggle clock
        clk = !clk;
        top->clk = clk;

        // Apply reset at the start
        rst = (i < 10); // Assert reset for the first 10 cycles
        top->rst = rst;

        // Enable the counter after reset
        if (i == 10)
        {
            en = 1; // Enable counter after reset
        }
        top->en = en;

        // Set the preload value
        top->v = v;

        // Evaluate the model
        top->eval();

        // Dump VCD
        tfp->dump(i);

        // Simulate some time (e.g., clock period)
        if (i == 100)
        {
            v = 123; // Change preload value for test
        }
    }

    // Close the VCD file
    tfp->close();

    // Clean up
    delete top;
    delete tfp;

    return 0;
}
