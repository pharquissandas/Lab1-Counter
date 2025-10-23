#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" // Vbuddy interface functions

int main(int argc, char **argv, char **env)
{
    int i, clk;

    Verilated::commandArgs(argc, argv);
    // Create top module instance
    Vcounter *top = new Vcounter;

    // Enable VCD tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    // Initialize Vbuddy
    if (vbdOpen() != 1)
        return -1;
    vbdHeader("Lab 1: Counter");

    // Initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // Run simulation
    for (i = 0; i < 300; i++)
    {
        // Toggle clock and dump VCD
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk); // time in ps
            top->clk = !top->clk;
            top->eval();
        }

        // ----- Vbuddy Output -----

        // Option 1: Display on 7-segment
        // vbdHex(4, (int(top->count) >> 16) & 0xF);
        // vbdHex(3, (int(top->count) >> 8) & 0xF);
        // vbdHex(2, (int(top->count) >> 4) & 0xF);
        // vbdHex(1, int(top->count) & 0xF);
        vbdCycle(i + 1);

        // Option 2: Plot on TFT instead of 7-segment
        // Uncomment the next line and comment out the vbdHex lines above
        vbdPlot(int(top->count), 0, 255);

        // ----- End Vbuddy Output -----

        // Control enable signal with push-button flag
        top->en = vbdFlag(); // enable counter or toggle direction

        // Optional reset logic
        top->rst = (i < 2) | (i == 15);

        if (Verilated::gotFinish())
            exit(0);
    }

    // Close Vbuddy and VCD
    vbdClose();
    tfp->close();
    delete top;
    return 0;
}
