//==============================================================
// Lab 1 - Task 3 : Vbuddy parameter & flag (one-shot mode)
//==============================================================
// Step 1: Loadable counter
// Pressing the Vbuddy switch loads the counter with Vbuddy's parameter value.
//==============================================================

module counter #(
  parameter WIDTH = 8
)(
  input  logic             clk,      // clock
  input  logic             rst,      // reset
  input  logic             sw,   // load trigger from Vbuddy flag
  input  logic [WIDTH-1:0] v,        // value to preload from Vbuddy
  output logic [WIDTH-1:0] count     // count output
);

  // STEP 1: Loadable counter (ACTIVE)
  always_ff @(posedge clk) begin
    if (rst)
      count <= {WIDTH{1'b0}};        // reset to zero
    else if (sw)
      count <= v;                    // load Vbuddy parameter value
    else
      count <= count + 1'b1;         // normal counting
  end

  //==============================================================
  // STEP 2: Single-step counter (COMMENTED OUT)
  //--------------------------------------------------------------
  // Uncomment this block and comment out the above one
  // to make the counter increment **only** when the Vbuddy switch is pressed.
  //--------------------------------------------------------------
  /*
  always_ff @(posedge clk) begin
    if (rst)
      count <= {WIDTH{1'b0}};
    else if (sw)
      count <= count + 1'b1;         // increment only when pressed
  end
  */
  //==============================================================

endmodule

