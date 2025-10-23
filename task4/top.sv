module top #(
  parameter WIDTH = 8
)(
  // Interface signals
  input  logic             clk,      // Clock
  input  logic             rst,      // Reset
  input  logic             en,       // Enable
  input  logic [WIDTH-1:0] v,        // Value to preload
  output logic [11:0]      bcd       // BCD output (3 digits)
);

  logic [WIDTH-1:0] count;  // Interconnect wire for counter output

  // Instantiate the counter module
  counter myCounter (
    .clk (clk),
    .rst (rst),
    .ld (en),  // Enable signal connects to ld (load)
    .v (v),    // Value to preload
    .count (count)  // Counter output
  );

  // Instantiate the bin2bcd (binary to BCD) module
  bin2bcd myDecoder (
    .x (count),  // Input binary value
    .BCD (bcd)   // Output BCD
  );

endmodule
