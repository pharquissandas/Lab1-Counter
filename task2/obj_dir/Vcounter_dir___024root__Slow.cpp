// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_dir.h for the primary calling header

#include "verilated.h"

#include "Vcounter_dir__Syms.h"
#include "Vcounter_dir___024root.h"

void Vcounter_dir___024root___ctor_var_reset(Vcounter_dir___024root* vlSelf);

Vcounter_dir___024root::Vcounter_dir___024root(Vcounter_dir__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcounter_dir___024root___ctor_var_reset(this);
}

void Vcounter_dir___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcounter_dir___024root::~Vcounter_dir___024root() {
}
