module counter_dir #(
    parameter WIDTH = 8
)(
    input logic clk, // count
    input logic rst, // asyncronous reset
    input logic en, // counting direction: 1=up, 0=down
    output logic [WIDTH-1:0] count // counter output
);

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            count <= {WIDTH{1'b0}};               // reset
        else if (en)
            count <= count + {{WIDTH-1{1'b0}},1'b1}; // count up
        else
            count <= count - {{WIDTH-1{1'b0}},1'b1}; // count down
    end
endmodule
