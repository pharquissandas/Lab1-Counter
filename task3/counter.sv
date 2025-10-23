module counter #(
  parameter WIDTH = 8
)(
  // interface signals
  input  logic             clk,      // clock
  input  logic             rst,      // reset
  input  logic             switch,   // load counter from data
  input  logic [WIDTH-1:0] v,        // value to preload
  output logic [WIDTH-1:0] count     // count output
);

// Internal logic for load control
logic ld;

// Counter logic
always_ff @ (posedge clk) begin
    if (rst) count <= {WIDTH{1'b0}};
    else if (ld) count <= v;
    else count <= count + 1'b1
end

// Control ld signal based on switch press for loading counter
always_ff @ (posedge clk) begin
        if (switch) begin
        // If switch is pressed, assert the ld signal to load the counter with v
            ld <= 1'b1;
    end else begin
        ld <= 1'b0;
    end
end
endmodule
