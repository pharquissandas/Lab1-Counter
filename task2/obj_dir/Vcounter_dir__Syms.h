// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCOUNTER_DIR__SYMS_H_
#define VERILATED_VCOUNTER_DIR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcounter_dir.h"

// INCLUDE MODULE CLASSES
#include "Vcounter_dir___024root.h"

// SYMS CLASS (contains all model state)
class Vcounter_dir__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcounter_dir* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcounter_dir___024root         TOP;

    // CONSTRUCTORS
    Vcounter_dir__Syms(VerilatedContext* contextp, const char* namep, Vcounter_dir* modelp);
    ~Vcounter_dir__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
