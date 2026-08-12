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


module crossbar_arbitrer #(parameter uint NUM_LINKS = 4)(
    input clk,
    input reset, 
    input [NUM_LINKS-1: 0] request_matrix,
    link_adapter_if.slave link_adapter_ingress [NUM_LINKS-1: 0],
    link_adapter_if.master link_adapter_egress,
    output reg grant_active, 
    output reg [$clog2(NUM_LINKS)-1: 0] granted_idx
);

reg [$clog2(NUM_LINKS)-1: 0] rr_ptr;
reg [$clog2(NUM_LINKS)-1:0] idx;
reg [$clog2(NUM_LINKS): 0] grants;

// priority encoder NUM LINKS to clog(NUM_LINKS)
always @(*) begin
    granted_idx = rr_ptr;
    grant_active = 0;
    for(int i = NUM_LINKS -1; i >= 0; i--) begin
        idx = (i[$clog2(NUM_LINKS)-1:0] + rr_ptr);
        if(request_matrix[idx] && link_adapter_egress.axi_ready) begin
            // dont grant any new requests unless the request_matrix for the ingress is high AND the egress link (tx) is ready to accept.
            grant_active = 1;
            granted_idx = idx;
        end
    end
    link_adapter_egress.axi_valid = grant_active; // grant has been made, data on AXI bus will be valid 
end

// // drive axi_ready signal of granted ingress link 
// generate
//     for (genvar k = 0; k < NUM_LINKS; k++) begin : DEMUX
//          always @(*) begin
//             link_adapter_ingress[k].axi_ready = ((granted_idx==k && !reset)) ? link_adapter_egress.axi_ready : 0;
//          end
//     end
// endgenerate

// drive l3 data signal of egress link
// intermediate mux wires - one per ingress link 
wire [(L3_MAX_SIZE_BYTES<<3)-1:0] mux_inputs [NUM_LINKS-1:0];
generate
    for (genvar i = 0; i < NUM_LINKS; i++) begin : mux_gen
        assign mux_inputs[i] = link_adapter_ingress[i].l3_packet;
    end
endgenerate
assign link_adapter_egress.l3_packet = grant_active ? mux_inputs[granted_idx] : '0;


always @(posedge clk) begin
    if(reset) begin
        rr_ptr <= 0;
        // grants <= 0;
    end else begin
        if(link_adapter_egress.axi_ready && link_adapter_egress.axi_valid) begin
            rr_ptr <= granted_idx + 1;
        end
        if(grant_active) begin
            grants[idx] <= 1;
        end
    end
end

endmodule
