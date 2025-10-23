// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcounter_dir.h for the primary calling header

#ifndef VERILATED_VCOUNTER_DIR___024ROOT_H_
#define VERILATED_VCOUNTER_DIR___024ROOT_H_  // guard

#include "verilated.h"

class Vcounter_dir__Syms;

class Vcounter_dir___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(count,7,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;

    // INTERNAL VARIABLES
    Vcounter_dir__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcounter_dir___024root(Vcounter_dir__Syms* symsp, const char* name);
    ~Vcounter_dir___024root();
    VL_UNCOPYABLE(Vcounter_dir___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
