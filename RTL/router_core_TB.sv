`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/23/2026 08:53:11 AM
// Design Name: 
// Module Name: router_core_TB
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

(* DONT_TOUCH = "TRUE" *) module router_core_TB(
);

reg clk;
initial clk = 0;
always #1 clk = ~clk;


reg reset; 
reg  [(L3_MAX_SIZE_BYTES << 3)-1:0] test_packet, test_packet_2, test_packet_3;

// -------------------------------------------------------------------------
// build_l3_packet - construct L3 packet field by field
// -------------------------------------------------------------------------
task automatic build_l3_packet(
    input  [7:0]  src_sat,
    input  [7:0]  dest_sat,
    input  [7:0]  ttl,
    input  [15:0] payload_length,
    input  [7:0]  payload_fill,
    output [(L3_MAX_SIZE_BYTES << 3)-1:0] pkt
);
    integer j;
    begin
        pkt = '0;
        pkt[L3_SRC_SAT_MSB          : L3_SRC_SAT_LSB]        = src_sat;
        pkt[L3_DEST_SAT_MSB         : L3_DEST_SAT_LSB]       = dest_sat;
        pkt[L3_TTL_MSB              : L3_TTL_LSB]             = ttl;
        pkt[L3_PAYLOAD_LENGTH_MSB   : L3_PAYLOAD_LENGTH_LSB]  = payload_length;
        for (j = 0; j < payload_length && j < L3_PAYLOAD_MAX_SIZE_BYTES; j++) begin
            pkt[L3_PAYLOAD_LSB + (j*8) +: 8] = payload_fill + j[7:0];
        end
    end
endtask

// -------------------------------------------------------------------------
// send_packet - AXI valid/ready handshake
// -------------------------------------------------------------------------
typedef virtual link_adapter_if link_adapter_vif;
task automatic send_packet(
    input [(L3_MAX_SIZE_BYTES << 3)-1:0] pkt,
    link_adapter_vif link_adapter_rx
);
    begin
        link_adapter_rx.l3_packet    <= pkt;
        link_adapter_rx.axi_valid <= 1'b1;
        do begin
            @(posedge clk);
        end while (!link_adapter_rx.axi_ready);
        link_adapter_rx.axi_valid <= 1'b0;
        link_adapter_rx.l3_packet <= 0; 
    end
endtask

// NETWORK TEST TOPOLOGY (CONTAINED IN INDIVUDAL FIB FILES)
// SAT 1, INGRESS: SAT 2, SAT 3, EGRESS: SAT 2, SAT 3
// SAT 2, INGRESS: SAT 1, SAT 3, EGRESS: SAT 1, SAT 3
// SAT 3, INGRESS: SAT 1, SAT 2, EGRESS: SAT 1, SAT 2

// Instantiate Topology Links:
laser_link_phy_if sat_0_to_sat_1();
laser_link_phy_if sat_1_to_sat_0();
laser_link_phy_if sat_0_to_sat_2();
laser_link_phy_if sat_2_to_sat_0();
laser_link_phy_if sat_1_to_sat_2();
laser_link_phy_if sat_2_to_sat_1();

(* DONT_TOUCH = "TRUE" *) router_core #(
        .NUM_LINKS(2),
        .NUM_SATS(3), 
        .SAT_ID(0),
        .FIB_FILE("SAT1_FIB.mem")
    ) SAT_0 (
        .clk(clk),
        .reset(reset),
        .laser_link_ingress({sat_2_to_sat_0, sat_1_to_sat_0}),
        .laser_link_egress({sat_0_to_sat_2, sat_0_to_sat_1})
    );

 (* DONT_TOUCH = "TRUE" *) router_core #(
        .NUM_LINKS(2),
        .NUM_SATS(3), 
        .SAT_ID(1),
        .FIB_FILE("SAT2_FIB.mem")
    ) SAT_1 (
        .clk(clk),
        .reset(reset),
        .laser_link_ingress({sat_2_to_sat_1, sat_0_to_sat_1}),
        .laser_link_egress({sat_1_to_sat_2, sat_1_to_sat_0})
    );

(* DONT_TOUCH = "TRUE" *) router_core #(
        .NUM_LINKS(2),
        .NUM_SATS(3), 
        .SAT_ID(2),
        .FIB_FILE("SAT3_FIB.mem")
    ) SAT_2 (
        .clk(clk),
        .reset(reset),
        .laser_link_ingress({sat_1_to_sat_2, sat_0_to_sat_2}),
        .laser_link_egress({sat_2_to_sat_1, sat_2_to_sat_0})
    );


initial begin
// -------------------------------------------------------------------------
// TEST 1. SAT 0 -> SAT 1
     clk = 0;
     reset = 1; 
     repeat(5) @(posedge clk );
     reset = 0;
     $display("--- Test 1: SAT 0 -> SAT 1 --- single egress no contention test");
     // Kind of a hack: inject into ingress link from SAT 1 to bring into SAT 0 router core, with final packet dest being SAT 1 itself
     build_l3_packet(8'h01, 8'h01, 8'h10, 16'h0000, 8'h00, test_packet);
     send_packet(test_packet, SAT_0.link_adapter_ingress[0]);
     repeat(25) @(posedge clk);
    
     assert(SAT_1.link_adapter_ingress[0].l3_packet == test_packet) 
         $display("PASSED TEST 1 SAT 0 -> SAT 1 (single egress no contention test)");
         else $error("TEST 1 SAT 0 -> SAT 1, FAILED: TEST PACKET NOT RECEIVED AT DESTINATION", $time);
// // -------------------------------------------------------------------------
// TEST 2. SAT 0 -> SAT 1, SAT 0-> SAT 2 (multi-egress no contention test)
    // reset = 1; 
    // repeat(5) @(posedge clk);
    // reset = 0;
    // $display("--- TEST 2. SAT 0 -> SAT 1, SAT 0-> SAT 2 --- (multi-egress no contention test)");
    // build_l3_packet(8'h01, 8'h01, 8'h10, 16'h0004, 8'h00, test_packet);
    // build_l3_packet(8'h02, 8'h02, 8'h10, 16'h0004, 8'h00, test_packet_2);
    // fork
    //     send_packet(test_packet, SAT_0.link_adapter_ingress[0]);
    //     send_packet(test_packet_2, SAT_0.link_adapter_ingress[1]);
    // join
    // repeat(50) @(posedge clk);
    // assert(SAT_1.link_adapter_ingress[0].l3_packet == test_packet) 
    //     else $error("TEST 2 FAILED: TEST PACKET WITH SOURCE SAT 0 NOT RECEIVED AT DESTINATION SAT 1", $time);
    // assert(SAT_2.link_adapter_ingress[0].l3_packet == test_packet_2)         
    //     $display("PASSED TEST 2. SAT 0 -> SAT 1, SAT 0-> SAT 2 (multi-egress no contention test)");
    //     else $error("TEST 2 FAILED: TEST PACKET WITH SOURCE SAT 0 NOT RECEIVED AT DESTINATION SAT 2", $time);
// -------------------------------------------------------------------------
// TEST 3. SAT 0 -> SAT 1, SAT 0-> SAT 1 (single egress contention test)
    // reset = 1; 
    // repeat(5) @(posedge clk);
    // reset = 0;
    // $display("--- TEST 3. SAT 0 -> SAT 1, SAT 0-> SAT 1 --- (single egress contention test)");
    // build_l3_packet(8'h01, 8'h01, 8'h10, 16'h0004, 8'h00, test_packet);
    // build_l3_packet(8'h02, 8'h01, 8'h10, 16'h0004, 8'h00, test_packet_2);
    // fork
    //     send_packet(test_packet, SAT_0.link_adapter_ingress[0]);
    //     send_packet(test_packet_2, SAT_0.link_adapter_ingress[1]);
    // join
    // repeat(50) @(posedge clk);
    // $finish;
end
endmodule
