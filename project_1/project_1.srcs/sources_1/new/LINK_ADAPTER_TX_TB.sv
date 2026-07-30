`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: LINK_ADAPTER_TB
// Description: Testbench for link_adapter
//
// Revision:
//   0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

import packets_and_frames::*;

module LINK_ADAPTER_TB();

    reg  clk;
    reg  reset;
    reg  [(L3_MAX_SIZE_BYTES << 3)-1:0] tx_packet;
    reg  [(L3_MAX_SIZE_BYTES << 3)-1:0] rx_packet;
    reg  [(L3_MAX_SIZE_BYTES << 3)-1:0] temp_tx_packet;
    reg  packet_valid;
    wire packet_ready;
    reg  packet_valid_rx;
    wire packet_ready_rx = 0;
    wire [7:0] OSERDES_out;

    // DUT
    link_adapter_tx #(
        .PACKET_COUNT(8)
    ) dut (
        .clk         (clk),
        .reset       (reset),
        .tx_packet   (tx_packet),
        .packet_valid(packet_valid),
        .packet_ready(packet_ready),
        .OSERDES_out (OSERDES_out)
    );
    
    link_adapter_rx #(
        .PACKET_COUNT(8)
    ) dut_rx (
        .clk         (clk),
        .reset       (reset),
        .rx_packet   (rx_packet),
        .packet_valid(packet_valid_rx),
        .packet_ready(packet_ready_rx),
        .ISERDES_in (OSERDES_out)
    );

    // clock
    initial clk = 0;
    always #1 clk = ~clk;

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
    task automatic send_packet(
        input [(L3_MAX_SIZE_BYTES << 3)-1:0] pkt
    );
        begin
            tx_packet    <= pkt;
            packet_valid <= 1'b1;
            do begin
                @(posedge clk);
            end while (!packet_ready);
            packet_valid <= 1'b0;
            tx_packet <= 0; 
        end
    endtask

    // -------------------------------------------------------------------------
    // Main test sequence
    // -------------------------------------------------------------------------
    initial begin
        clk          = 0;
        reset        = 1;
        packet_valid = 0;
        tx_packet    = 0;

        repeat(5) @(posedge clk);
        reset = 0;

        // -------------------------------------------------------------------
        // Test 1: zero payload
        // -------------------------------------------------------------------
        $display("--- Test 1: zero payload ---");
        build_l3_packet(8'hAA, 8'hBB, 8'h10, 16'h0000, 8'h00, temp_tx_packet);
        send_packet(temp_tx_packet);
        repeat(20) @(posedge clk);

        // -------------------------------------------------------------------
        // Test 2: small payload (4 bytes)
        // -------------------------------------------------------------------
        $display("--- Test 2: 4 byte payload ---");
        build_l3_packet(8'h01, 8'h02, 8'hFF, 16'h0004, 8'hDE, temp_tx_packet);
        send_packet(temp_tx_packet);
        repeat(30) @(posedge clk);

        // -------------------------------------------------------------------
        // Test 3: maximum payload (250 bytes)
        // -------------------------------------------------------------------
        $display("--- Test 3: max payload (250 bytes) ---");
        build_l3_packet(8'hCA, 8'hFE, 8'h01, 16'h00FA, 8'hAA, temp_tx_packet);
        send_packet(temp_tx_packet);
        repeat(300) @(posedge clk);

        // -------------------------------------------------------------------
        // Test 4: back-to-back packets
        // -------------------------------------------------------------------
        $display("--- Test 4: 3 back-to-back packets ---");
        repeat(3) begin
            build_l3_packet(8'h11, 8'h22, 8'h08, 16'h000A, 8'h55, temp_tx_packet);
            send_packet(temp_tx_packet);
        end
        repeat(400) @(posedge clk);

        // -------------------------------------------------------------------
        // Test 5: FIFO fill and overflow check
        // -------------------------------------------------------------------
        $display("--- Test 5: fill FIFO to capacity ---");
        repeat(8) begin
            build_l3_packet(8'hDE, 8'hAD, 8'h05, 16'h0005, 8'hBE, temp_tx_packet);
            send_packet(temp_tx_packet);
        end

        $display("--- Test 5b: attempt overflow (should stall) ---");
        build_l3_packet(8'hDE, 8'hAD, 8'h05, 16'h0005, 8'hEF, temp_tx_packet);
        tx_packet    <= temp_tx_packet;
        packet_valid <= 1'b1;
        repeat(10) @(posedge clk);

        if (packet_ready)
            $display("FAIL: packet accepted into full FIFO");
        else
            $display("PASS: FIFO correctly blocked overflow");

        packet_valid <= 1'b0;
        repeat(500) @(posedge clk);

        $display("Done");
        $finish;
    end

    // -------------------------------------------------------------------------
    // Output monitor
    // -------------------------------------------------------------------------
    always @(posedge clk) begin
        if (OSERDES_out !== 8'hxx)
            $display("t=%0t OSERDES=%02x", $time, OSERDES_out);
    end

endmodule