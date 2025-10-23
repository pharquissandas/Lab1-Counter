// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcounter_dir.h"
#include "Vcounter_dir__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcounter_dir::Vcounter_dir(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcounter_dir__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcounter_dir::Vcounter_dir(const char* _vcname__)
    : Vcounter_dir(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcounter_dir::~Vcounter_dir() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcounter_dir___024root___eval_initial(Vcounter_dir___024root* vlSelf);
void Vcounter_dir___024root___eval_settle(Vcounter_dir___024root* vlSelf);
void Vcounter_dir___024root___eval(Vcounter_dir___024root* vlSelf);
#ifdef VL_DEBUG
void Vcounter_dir___024root___eval_debug_assertions(Vcounter_dir___024root* vlSelf);
#endif  // VL_DEBUG
void Vcounter_dir___024root___final(Vcounter_dir___024root* vlSelf);

static void _eval_initial_loop(Vcounter_dir__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcounter_dir___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcounter_dir___024root___eval_settle(&(vlSymsp->TOP));
        Vcounter_dir___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcounter_dir::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcounter_dir::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcounter_dir___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcounter_dir___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcounter_dir::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcounter_dir::final() {
    Vcounter_dir___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcounter_dir::hierName() const { return vlSymsp->name(); }
const char* Vcounter_dir::modelName() const { return "Vcounter_dir"; }
unsigned Vcounter_dir::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcounter_dir::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcounter_dir___024root__trace_init_top(Vcounter_dir___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter_dir___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcounter_dir___024root*>(voidSelf);
    Vcounter_dir__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcounter_dir___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcounter_dir___024root__trace_register(Vcounter_dir___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcounter_dir::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcounter_dir___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
