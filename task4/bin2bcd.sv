module bin2bcd (
  input  logic [7:0] x,     // 8-bit binary input
  output logic [11:0] BCD    // 12-bit BCD output (3 digits)
);

  logic [3:0] ones;         // Ones digit
  logic [3:0] tens;         // Tens digit
  logic [3:0] hundreds;     // Hundreds digit

  always_comb begin
    // Initialize BCD digits
    ones = x % 10;          // Get ones digit
    tens = (x / 10) % 10;   // Get tens digit
    hundreds = x / 100;     // Get hundreds digit
    BCD = {hundreds, tens, ones};  // Combine into 12-bit BCD
  end

endmodule
