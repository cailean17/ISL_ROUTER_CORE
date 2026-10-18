`timescale 1ns / 1ps
module router_core_flat #(parameter int NUM_LINKS = 2) (
    input  wire                   clk,
    input  wire                   reset,
    input  wire [NUM_LINKS*8-1:0] link_rx,    // one byte per link, packed
    output wire [NUM_LINKS*8-1:0] link_tx
);
    laser_link_phy_if ingress [NUM_LINKS] ();
    laser_link_phy_if egress  [NUM_LINKS] ();

    for (genvar i = 0; i < NUM_LINKS; i++) begin : io
        assign ingress[i].data   = link_rx[i*8 +: 8];
        assign link_tx[i*8 +: 8] = egress[i].data;
    end

    router_core #(.NUM_LINKS(NUM_LINKS)) core (
        .clk(clk), .reset(reset),
        .laser_link_ingress(ingress),
        .laser_link_egress(egress)
    );
endmodule