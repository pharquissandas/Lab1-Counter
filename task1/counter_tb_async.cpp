#include "Vcounter_async.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    // Create instance of the top module
    Vcounter_async *top = new Vcounter_async;

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("Vcounter_async.vcd"); // Output waveform file

    // Initialize simulation inputs
    top->clk = 0;
    top->rst = 1; // Start with reset asserted
    top->en = 0;

    // Main simulation loop
    for (int i = 0; i < 200; i++)
    {
        // Toggle clock
        top->clk = !top->clk;

        // Deassert reset after a few cycles
        if (i == 4)
            top->rst = 0;

        // Enable counting
        if (i == 5)
            top->en = 1;

        // Mid-simulation async reset pulse
        if (i == 50)
            top->rst = 1;
        if (i == 55)
            top->rst = 0;

        // Evaluate model
        top->eval();

        // Dump signals to VCD
        tfp->dump(i * 10);
    }

    // Finalize simulation
    top->final();
    tfp->close();
    delete top;

    return 0;
}