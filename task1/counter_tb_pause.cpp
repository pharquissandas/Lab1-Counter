#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
    Verilated::commandArgs(argc, argv);

    // initialize top module
    Vcounter *top = new Vcounter;

    // initialize trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("Vcounter_pause.vcd");

    // initialize simulation inputs
    int clk = 0;
    int pause_count = 0;

    top->rst = 1;
    top->en = 0;
    top->clk = 0;

    // run simulation for many half-cycles
    for (int i = 0; i < 200; i++)
    {
        // toggle clock
        clk = !clk;
        top->clk = clk;

        // release reset and enable after a few cycles
        if (i == 4)
            top->rst = 0;
        if (i == 5)
            top->en = 1;

        // evaluate model and dump trace
        top->eval();
        tfp->dump(i * 10);

        // pause logic on rising edge only
        if (clk == 1)
        {
            unsigned int cur_count = (unsigned int)top->count;

            if (cur_count == 0x09 && pause_count == 0)
            {
                pause_count = 3; // pause for 3 rising edges
                top->en = 0;
            }

            if (pause_count > 0)
            {
                pause_count--;
                if (pause_count == 0)
                {
                    top->en = 1; // resume counting
                }
            }
        }
    }

    // finalize simulation
    top->final();
    tfp->close();
    delete top;

    return 0;
}
