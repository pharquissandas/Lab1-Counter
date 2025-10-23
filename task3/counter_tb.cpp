#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" // Vbuddy helper functions

int main(int argc, char **argv)
{
    int i, clk;
    Verilated::commandArgs(argc, argv);
    Vcounter *top = new Vcounter;

    // Enable waveform dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    // Initialize Vbuddy
    if (vbdOpen() != 1)
        return -1;
    vbdHeader("Task 3: Vbuddy Parameter & One-Shot Mode");
    vbdSetMode(1); // enable one-shot mode for flag

    // Reset signals
    top->clk = 0;
    top->rst = 1;
    top->sw = 0;

    // Simulation loop
    for (i = 0; i < 500; i++)
    {
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        // Release reset after a few cycles
        top->rst = (i < 2);

        // Get Vbuddy inputs
        top->v = vbdValue(); // get value from rotary encoder
        top->sw = vbdFlag(); // one-shot flag for load/single-step

        // Plot counter value on TFT
        vbdPlot(int(top->count), 0, 255);

        if (Verilated::gotFinish())
            break;
    }

    vbdClose();
    tfp->close();
    delete top;
    return 0;
}
