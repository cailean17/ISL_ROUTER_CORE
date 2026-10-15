`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/17/2026 03:21:00 PM
// Design Name: 
// Module Name: crossbar_arbiter
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

// Necesarry Top Module Wrapper to drive interface signals for DV
module top_crossbar_arbiter #(parameter int NUM_LINKS = 4)(
    input clk,
    input reset
);
reg [NUM_LINKS-1: 0] request_matrix;
l3_buffer_if l3_buffers[NUM_LINKS]();
link_adapter_tx_if link_adapter_egress();
reg grant_active;
reg [$clog2(NUM_LINKS)-1: 0] granted_idx;

crossbar_arbiter #(
    .NUM_LINKS(NUM_LINKS)
 ) crossbar_arbiter (
    .clk                (clk),
    .reset              (reset),
    .request_matrix     (request_matrix),
    .l3_buffers         (l3_buffers),
    .link_adapter_egress(link_adapter_egress),
    .grant_active       (grant_active),
    .granted_idx        (granted_idx)
);


endmodule