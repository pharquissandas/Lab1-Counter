// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcounter_async.h"
#include "Vcounter_async__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcounter_async::Vcounter_async(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcounter_async__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcounter_async::Vcounter_async(const char* _vcname__)
    : Vcounter_async(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcounter_async::~Vcounter_async() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcounter_async___024root___eval_initial(Vcounter_async___024root* vlSelf);
void Vcounter_async___024root___eval_settle(Vcounter_async___024root* vlSelf);
void Vcounter_async___024root___eval(Vcounter_async___024root* vlSelf);
#ifdef VL_DEBUG
void Vcounter_async___024root___eval_debug_assertions(Vcounter_async___024root* vlSelf);
#endif  // VL_DEBUG
void Vcounter_async___024root___final(Vcounter_async___024root* vlSelf);

static void _eval_initial_loop(Vcounter_async__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcounter_async___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcounter_async___024root___eval_settle(&(vlSymsp->TOP));
        Vcounter_async___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcounter_async::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcounter_async::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcounter_async___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcounter_async___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcounter_async::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcounter_async::final() {
    Vcounter_async___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcounter_async::hierName() const { return vlSymsp->name(); }
const char* Vcounter_async::modelName() const { return "Vcounter_async"; }
unsigned Vcounter_async::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcounter_async::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcounter_async___024root__trace_init_top(Vcounter_async___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter_async___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcounter_async___024root*>(voidSelf);
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcounter_async___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcounter_async___024root__trace_register(Vcounter_async___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcounter_async::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcounter_async___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
