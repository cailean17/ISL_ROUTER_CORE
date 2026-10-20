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

generate
    // drive request matrix from pkt_desc axi_valid signals
    for(genvar k = 0; k < NUM_LINKS; k++) begin: crossbar_arbiter_requests_gen
        always_comb begin
            request_matrix[k] = 0;
            if (l3_buffers[k].m_axis_pkt_desc_tvalid) begin
                request_matrix[k] = 1'b1;
            end
        end
    end
    // extract egresss packet descriptor interface axi ready signal to use without indexing the interface (because indexing interfaces with runtime variables (int) is illegal in Verilog)
    logic egress_s_axis_router_cmd_tready_signal;
    always @(*) begin
        egress_s_axis_router_cmd_tready_signal = link_adapter_egress.s_axis_router_cmd_tready;
    end

    // drive the ingress interface axi ready signals using crossbar outputs and 
    for (genvar m = 0; m < NUM_LINKS; m++) begin : demux_crossbar_arbiter
            always_comb begin
            l3_buffers[m].m_axis_pkt_desc_tready = 0;
            for (int j = 0; j < NUM_LINKS; j++) begin
                if(grant_active && granted_idx == m) begin
                    l3_buffers[m].m_axis_pkt_desc_tready = egress_s_axis_router_cmd_tready_signal;
                end
            end
            end
    end
endgenerate

endmodule