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

import packets_and_frames::*;

module crossbar_arbiter #(parameter int NUM_LINKS = 4)(
    input clk,
    input reset, 
    input [NUM_LINKS-1: 0] request_matrix,
    l3_buffer_if l3_buffers [NUM_LINKS],
    link_adapter_tx_if link_adapter_egress,
    output reg grant_active, 
    output reg [$clog2(NUM_LINKS)-1: 0] granted_idx
);
reg [$clog2(NUM_LINKS)-1: 0] rr_ptr;
reg [$clog2(NUM_LINKS)-1:0] idx;

// priority encoder
always @(*) begin
    granted_idx = rr_ptr;
    grant_active = 0;
    for(int i = NUM_LINKS-1; i >= 0; i--) begin
        idx = (i + rr_ptr) % NUM_LINKS;
        if(request_matrix[idx]) begin
            grant_active = 1;
            granted_idx = idx;
        end
    end
    link_adapter_egress.s_axis_router_cmd_tvalid = grant_active; // grant has been made, data on AXI bus will be valid 
end

// drive winning l3 packet descriptor to link_adapter_tx egress
// update l3 packet descriptor buffer_id field to map to specific src buffer
// intermediate mux wires - one per ingress link (to overcome runtime interface indexing rules) 
l3_packet_descriptor_t mux_inputs [NUM_LINKS-1:0];
generate
    for (genvar i = 0; i < NUM_LINKS; i++) begin : mux_gen
        assign mux_inputs[i] = '{
            start_ptr: l3_buffers[i].m_axis_pkt_desc_tdata.start_ptr,
            length: l3_buffers[i].m_axis_pkt_desc_tdata.length,
            dest_sat: l3_buffers[i].m_axis_pkt_desc_tdata.dest_sat,
            desc_id: l3_buffers[i].m_axis_pkt_desc_tdata.desc_id,
            buffer_id: i
        };
    end
endgenerate
assign link_adapter_egress.s_axis_router_cmd_tdata = grant_active ? mux_inputs[granted_idx] : '0;

wire axi_handshake_complete = link_adapter_egress.s_axis_router_cmd_tready && link_adapter_egress.s_axis_router_cmd_tvalid;
always @(posedge clk) begin
    if(reset) begin
        rr_ptr <= 0;
    end else begin
        if(axi_handshake_complete) begin
            rr_ptr <= granted_idx + 1;
        end
    end
end

endmodule
