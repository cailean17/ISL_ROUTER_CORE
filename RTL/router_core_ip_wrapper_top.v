`timescale 1ns / 1ps
module router_top #(parameter integer NUM_LINKS = 2) (
    input  wire                   clk,
    input  wire                   reset,
    input  wire [NUM_LINKS*8-1:0] link_rx,
    output wire [NUM_LINKS*8-1:0] link_tx
);
    router_core_flat #(.NUM_LINKS(NUM_LINKS)) core (
        .clk(clk), .reset(reset),
        .link_rx(link_rx), .link_tx(link_tx)
    );
endmodule