`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/17/2026 03:21:00 PM
// Design Name: 
// Module Name: l3_buffer_arbiter
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

import packets_and_frames::*;

module l3_buffer_arbiter #(parameter int NUM_LINKS = 4)(
    input clk,
    input reset, 
    input [NUM_LINKS: 0] request_matrix,
    link_adapter_tx_if link_adapter_egress [NUM_LINKS+1],
    l3_buffer_if l3_buffer,
    output reg grant_active, 
    output reg [$clog2(NUM_LINKS): 0] granted_idx
);
reg [$clog2(NUM_LINKS): 0] latched_granted_idx;
reg [$clog2(NUM_LINKS): 0] rr_ptr;
reg servicing_l3_buffer_read;

// priority encoder
always_comb begin
    granted_idx = rr_ptr;
    grant_active = 0;
    if (!servicing_l3_buffer_read) begin
        reg [$clog2(NUM_LINKS):0] idx;
        for(int i = NUM_LINKS; i >= 0; i--) begin
            idx = (i + rr_ptr) % (NUM_LINKS+1);
            if(request_matrix[idx]) begin
                grant_active = 1;
                granted_idx = idx;
            end
        end
    end else begin
        granted_idx = latched_granted_idx;
        grant_active = 1;
    end
    l3_buffer.s_axis_tx_cmd_tvalid = grant_active & ~servicing_l3_buffer_read; // grant has been made, data on AXI bus will be valid 
end

// drive winning l3 packet descriptor to link_adapter_tx egress
// intermediate mux wires - one per ingress link (to overcome runtime interface indexing rules) 
l3_packet_descriptor_t mux_inputs [NUM_LINKS+1];
generate
    for (genvar i = 0; i <= NUM_LINKS; i++) begin : mux_gen
        assign mux_inputs[i] = link_adapter_egress[i].m_axis_tx_cmd_tdata;
    end
endgenerate
assign l3_buffer.s_axis_tx_cmd_tdata = grant_active ? mux_inputs[granted_idx] : '0;
wire axis_tx_cmd_handshake_complete = grant_active && !servicing_l3_buffer_read && l3_buffer.s_axis_tx_cmd_tready;
wire axis_tx_handshake_complete = l3_buffer.m_axis_tx_tlast && l3_buffer.m_axis_tx_tready && l3_buffer.m_axis_tx_tvalid;
always @(posedge clk) begin
    if(reset) begin
        rr_ptr <= 0;
        servicing_l3_buffer_read <= 0;
        latched_granted_idx <= 0;
    end else begin
        latched_granted_idx <= granted_idx;
        if (axis_tx_cmd_handshake_complete) begin
            servicing_l3_buffer_read <= 1;
        end
        if(axis_tx_handshake_complete) begin
            rr_ptr <= granted_idx + 1;
            servicing_l3_buffer_read <= 0;
        end
    end
end

endmodule
