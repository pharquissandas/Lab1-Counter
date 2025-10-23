#include "Vcounter_dir.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" // Vbuddy helper functions

int main(int argc, char **argv)
{
    int i, clk;

    Verilated::commandArgs(argc, argv);
    Vcounter_dir *top = new Vcounter_dir;

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter_dir.vcd");

    // Initialize Vbuddy
    if (vbdOpen() != 1)
        return -1;
    vbdHeader("Counter Direction Challenge");

    // Initialize inputs
    top->clk = 0;
    top->rst = 1;
    top->en = 1; // initial counting up

    // Simulation loop
    for (i = 0; i < 500; i++)
    {
        // Toggle clock and dump waveform
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        // Control counting direction with Vbuddy push-button
        top->en = vbdFlag(); // 1 = up, 0 = down

        // TFT plotting
        vbdPlot(int(top->count), 0, 255); // shows counter value on TFT

        // Optional asynchronous reset
        top->rst = (i < 2) | (i == 250);

        if (Verilated::gotFinish())
            exit(0);
    }

    // Close Vbuddy and VCD
    vbdClose();
    tfp->close();
    delete top;
    return 0;
}
