`timescale 1ns/ 1ps

module top_l3_buffer_arbiter #(parameter int NUM_LINKS = 4)(
    input clk, 
    input reset
);
reg [NUM_LINKS:0] request_matrix;
link_adapter_tx_if link_adapter_egress[NUM_LINKS+1] ();
l3_buffer_if l3_buffer();
reg grant_active;
reg [$clog2(NUM_LINKS) : 0] granted_idx;

l3_buffer_arbiter #(
    .NUM_LINKS(NUM_LINKS)
 ) l3_buffer_arbiter (
    .clk                (clk),
    .reset              (reset),
    .request_matrix     (request_matrix),
    .link_adapter_egress(link_adapter_egress),
    .l3_buffer          (l3_buffer),
    .grant_active       (grant_active),
    .granted_idx        (granted_idx)
);

generate 
    for(genvar k = 0; k < NUM_LINKS; k++) begin: l3_buffer_arbiter_requests_gen
        always @(*) begin
            request_matrix[k] = 0;
            if (link_adapter_egress[k].m_axis_tx_cmd_tvalid) begin
                request_matrix[k] = 1'b1;
            end
        end
    end
    logic [7:0] l3_buffer_m_axis_tx_tdata_signal;
    logic l3_buffer_m_axis_tx_tvalid_signal;
    logic l3_buffer_m_axis_tx_tlast_signal;
    logic l3_buffer_s_axis_tx_cmd_tready_signal;
    always_comb begin
        l3_buffer_m_axis_tx_tdata_signal  = l3_buffer.m_axis_tx_tdata;
        l3_buffer_m_axis_tx_tvalid_signal = l3_buffer.m_axis_tx_tvalid;
        l3_buffer_m_axis_tx_tlast_signal  = l3_buffer.m_axis_tx_tlast;
        l3_buffer_s_axis_tx_cmd_tready_signal = l3_buffer.s_axis_tx_cmd_tready;
    end
    for(genvar m = 0; m < NUM_LINKS; m++) begin : demux_l3_buffer_arbiter
        always_comb begin
            link_adapter_egress[m].s_axis_tx_tdata = 0;
            link_adapter_egress[m].s_axis_tx_tvalid = 0;
            link_adapter_egress[m].s_axis_tx_tlast = 0;
            link_adapter_egress[m].m_axis_tx_cmd_tready = 0;
            for(int i = 0; i < NUM_LINKS; i++) begin
                if (grant_active && granted_idx == m) begin
                    link_adapter_egress[m].s_axis_tx_tdata = l3_buffer_m_axis_tx_tdata_signal;
                    link_adapter_egress[m].s_axis_tx_tvalid = l3_buffer_m_axis_tx_tvalid_signal;
                    link_adapter_egress[m].s_axis_tx_tlast = l3_buffer_m_axis_tx_tlast_signal;
                    link_adapter_egress[m].m_axis_tx_cmd_tready = l3_buffer_s_axis_tx_cmd_tready_signal;
                end
            end
        end
    end
    logic link_adapter_egress_s_axis_tx_tready_signals [NUM_LINKS-1:0];
    for(genvar l = 0; l < NUM_LINKS; l++) begin: link_adapter_egress_signal_extract
        always_comb begin
            link_adapter_egress_s_axis_tx_tready_signals[l] = link_adapter_egress[l].s_axis_tx_tready;
        end
    end

    always_comb begin
        l3_buffer.m_axis_tx_tready = 0;
        if(grant_active) begin
            l3_buffer.m_axis_tx_tready = link_adapter_egress_s_axis_tx_tready_signals[granted_idx];
        end
    end
endgenerate


endmodule
