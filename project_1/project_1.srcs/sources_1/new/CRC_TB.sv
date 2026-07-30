`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2026 08:27:27 PM
// Design Name: 
// Module Name: CRC_TB
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`define ASSERT(CONDITION, MESSAGE) if ((CONDITION)==1'b1); else begin $error MESSAGE; end
module CRC_TB();

localparam TEST_MESSAGE_SIZE_BITS = 32;
localparam CRC_BIT_SLICE_SIZE_BITS = 8;
localparam POLY_SIZE_BITS = 32;
localparam TEST_RUNS = 100; 

reg clk = 1;
always #1 clk = ~clk;
reg reset;

reg [TEST_MESSAGE_SIZE_BITS-1: 0] TEST_VECTOR [TEST_RUNS-1: 0];
reg [POLY_SIZE_BITS-1: 0] SOLUTION_VECTOR [TEST_RUNS-1:0];

initial begin
    $readmemh("CRC_TEST_VECTOR.mem", TEST_VECTOR);
    $readmemh("CRC_RESULT_VECTOR.mem", SOLUTION_VECTOR);
end
 
reg [POLY_SIZE_BITS-1: 0] CRC;
reg [TEST_MESSAGE_SIZE_BITS-1: 0] CURRENT_TEST;
reg [POLY_SIZE_BITS-1: 0] CURRENT_SOLUTION;
integer i;
integer j;
integer pass;
reg crc_enable;
CRC DUT(CURRENT_TEST[CRC_BIT_SLICE_SIZE_BITS-1:0], reset, crc_enable, clk, CRC);
wire [POLY_SIZE_BITS-1: 0] CRC_FINAL = CRC ^ {POLY_SIZE_BITS{1'b1}}; // IEE 802.3 Final XOR Standard

initial begin
    $display("CRC TEST BENCH ACTIVE");
    j = 0; 
    pass = 0;
    reset = 1;
    @(negedge clk);
    @(negedge clk);
    reset = 0;
    CURRENT_TEST = TEST_VECTOR[0];
    CURRENT_SOLUTION = SOLUTION_VECTOR[0];
    crc_enable = 1;
    for(i = 0; i < (TEST_RUNS * (TEST_MESSAGE_SIZE_BITS / CRC_BIT_SLICE_SIZE_BITS)); i += 1) begin
        @(negedge clk);
        if(j == 3) begin
            j = 0;
            `ASSERT(CRC_FINAL == CURRENT_SOLUTION, ("CRC incorrect: expected %0h, got %0h", CURRENT_SOLUTION, CRC_FINAL));
            CURRENT_TEST = TEST_VECTOR[(i / (TEST_MESSAGE_SIZE_BITS/CRC_BIT_SLICE_SIZE_BITS)) + 1];
            reset = 1;
            if(CRC_FINAL == CURRENT_SOLUTION) begin
                pass += 1;
            end
            @(negedge clk);
            @(negedge clk);
            reset = 0;
            CURRENT_SOLUTION = SOLUTION_VECTOR[(i / (TEST_MESSAGE_SIZE_BITS/CRC_BIT_SLICE_SIZE_BITS)) + 1];
        end else begin
            j += 1; 
            CURRENT_TEST >>= 8;
        end
    end 
    $display("ALL TESTS COMPLETE");
    $display("PASSED: %d, FAILED: %d", pass, TEST_RUNS - pass);
    $finish;
end
endmodule
