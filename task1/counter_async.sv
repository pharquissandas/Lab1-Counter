module counter_async #(
    parameter WIDTH = 8             // Counter bit width
)(
    input  logic clk,               // Clock
    input  logic rst,               // Asynchronous reset (active high)
    input  logic en,                // Enable counting
    output logic [WIDTH-1:0] count  // Counter output
);

    // Asynchronous reset: triggers on posedge clk or posedge rst
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            count <= {WIDTH{1'b0}};                 // Immediate reset to 0
        else
            count <= count + {{WIDTH-1{1'b0}}, en}; // Increment by 1 if en=1
    end

endmodule