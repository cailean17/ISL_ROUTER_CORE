    `timescale 1ns / 1ps
    //////////////////////////////////////////////////////////////////////////////////
    // Company: 
    // Engineer: 
    // 
    // Create Date: 05/11/2026 09:46:15 AM
    // Design Name: 
    // Module Name: router_core
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

module router_core #(parameter NUM_LINKS = 2, parameter NUM_SATS = 256, parameter SAT_ID = 0, parameter string FIB_FILE = "SAT1_FIB.mem")(
    input clk, 
    input reset,
    output test,
    laser_link_phy_if.slave laser_link_ingress[NUM_LINKS-1:0],
    laser_link_phy_if.master laser_link_egress[NUM_LINKS-1:0]
);
    
    assign test = 1;
    link_adapter_if link_adapter_ingress[NUM_LINKS-1:0] ();
    link_adapter_if link_adapter_egress[NUM_LINKS-1:0] ();

    // generate link adapters for each ingress/egress link
    genvar i;
    generate
        for(i = 0; i < NUM_LINKS; i++) begin: link_adapters_gen
            link_adapter_rx RX (
                .clk(clk),
                .reset(reset),
                .rx_packet(link_adapter_ingress[i].l3_packet),
                .packet_valid(link_adapter_ingress[i].axi_valid),
                .packet_ready(link_adapter_ingress[i].axi_ready),
                .ISERDES_in(laser_link_ingress[i].data)
            );
            link_adapter_tx TX (
                .clk(clk),
                .reset(reset),
                .tx_packet(link_adapter_egress[i].l3_packet),
                .packet_valid(link_adapter_egress[i].axi_valid),
                .packet_ready(link_adapter_egress[i].axi_ready),
                .OSERDES_out(laser_link_egress[i].data)
            );
        end
    endgenerate
    
    // routing crossbar arbiters logic
    logic [NUM_LINKS-1:0] crossbar_arbiters_request_matrix [NUM_LINKS-1:0]; 
    logic [NUM_LINKS-1:0] crossbar_arbiters_grant_active_output;
    logic [$clog2(NUM_LINKS)-1:0] crossbar_arbiters_granted_idx_output [NUM_LINKS-1:0];
    // egress link 0 -> 0010 (ingress 2 requests egress 0)
    // egress link 1 -> 1110 (ingress 0,1,2 requests egress 1)
    // etc......
    generate
        for(genvar j = 0; j < NUM_LINKS; j++) begin
            crossbar_arbiter #(.NUM_LINKS(NUM_LINKS)) CB(
                .clk(clk), 
                .reset(reset),
                .request_matrix(crossbar_arbiters_request_matrix[j]),
                .link_adapter_ingress(link_adapter_ingress), 
                .link_adapter_egress(link_adapter_egress[j]),
                .grant_active(crossbar_arbiters_grant_active_output[j]),
                .granted_idx(crossbar_arbiters_granted_idx_output[j])
            );
        end
    endgenerate
    
    // LUTRAM FIB (UPDATED FROM GROUND STATION UPLINK)
    reg [31:0] FIB [NUM_SATS-1:0];
    initial begin 
       $readmemh(FIB_FILE, FIB);
    end
  
    for(genvar k = 0; k < NUM_LINKS; k++) begin: crossbar_requests
        always @(*) begin
            for (int e = 0; e < NUM_LINKS; e++) begin
                crossbar_arbiters_request_matrix[e][k] = 0;
            end
            if (link_adapter_ingress[k].axi_valid)
                crossbar_arbiters_request_matrix
                    [FIB[link_adapter_ingress[k].l3_packet[L3_DEST_SAT_MSB:L3_DEST_SAT_LSB]]
                        [$clog2(NUM_LINKS)-1:0]][k] = 1'b1;
        end
        // always @(posedge clk) begin
        //     if(reset) begin
        //         for (int d = 0; d < NUM_LINKS; d++) begin
        //             crossbar_arbiters_request_matrix[d][k] <= 1'b0;
        //         end
        //     end else begin
        //         if (link_adapter_ingress[k].axi_valid) begin
        //             crossbar_arbiters_request_matrix[FIB[link_adapter_ingress[k].l3_packet[L3_DEST_SAT_MSB:L3_DEST_SAT_LSB]][$clog2(NUM_LINKS): 0]][k] <= 1;
        //         end else begin
        //             crossbar_arbiters_request_matrix[FIB[link_adapter_ingress[k].l3_packet[L3_DEST_SAT_MSB:L3_DEST_SAT_LSB]][$clog2(NUM_LINKS): 0]][k] <= 0;
        //         end
        //     end
        // end
    end

    // drive axi_ready using crossbar grant outputs to complete handshake from ingress links (link_adapter_rx):

    // extract egresss interface axi ready signals to use without indexing the interface (because indexing interfaces is illegal in Verilog)
    logic [NUM_LINKS-1: 0] egress_axi_ready_signals;
    generate
        for(genvar l = 0; l < NUM_LINKS; l++) begin
            always @(*) begin
                egress_axi_ready_signals[l] = link_adapter_egress[l].axi_ready;
            end
        end

    // drive the ingress interface axi ready signals
    endgenerate
    generate
        for (genvar k = 0; k < NUM_LINKS; k++) begin : DEMUX
             always @(*) begin
                link_adapter_ingress[k].axi_ready = 0;
                for (int j = 0; j < NUM_LINKS; j++) begin
                    if(crossbar_arbiters_grant_active_output[j] && crossbar_arbiters_granted_idx_output[j] == k) begin
                        link_adapter_ingress[k].axi_ready = egress_axi_ready_signals[j];
                    end
                end
             end
        end
    endgenerate
        
endmodule
