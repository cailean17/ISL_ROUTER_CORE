`timescale 1ns / 1ps
import packets_and_frames::*;
module link_adapter_rx
(
    input   wire clk,
    input   wire reset,
    // RX<->PHY
    input   logic [7:0] ISERDES_in,
    // RX<->buffer
    input   logic       s_axis_tready, // pinned to HIGH can't enforce backpressure on RX Adapter, if L3 buffer full it intelligently drops and rolls back ptrs
    output  logic [7:0] s_axis_tdata,
    output  logic       s_axis_tvalid,
    output  logic       s_axis_tlast,
    output  logic       s_axis_tuser
);

typedef enum logic [2:0] {STALL, DISASSEMBLE, ACQUIRE_LENGTH, RECEIVE, CRC, COMMIT} link_adapter_rx_fsm_states_t;
link_adapter_rx_fsm_states_t current_link_adapter_rx_state, next_link_adapter_rx_state;

// LAYER 2 frame received from PHY (LSB first, SOF transmitted first):
// [CRC32(2111:2080), L3_Packet(2079:32), Length(31:16),Type(15:12), Flags(11:8), SOF(7:0)]

// Auxillary
reg [$clog2(L2_MAX_SIZE_BYTES+1)-1:0] byte_ctr_in;   // 11 bits
reg [1:0] byte_ctr_crc_in;
reg [(L2_PAYLOAD_LENGTH_SIZE_BYTES << 3)-1:0] latched_L3_packet_size;


// CRC Instantiation
reg [(L2_CRC_SIZE_BYTES << 3)-1: 0] crc_calc_output;
wire [7:0] crc_calc_input = ISERDES_in;
wire crc_matched;   
assign crc_matched = (ISERDES_in == (crc_calc_output[{4'b0000, byte_ctr_crc_in} << 3 +:8 ] ^ 8'hFF));
reg valid_crc_flag;
reg crc_calc_en;
wire crc_reset = reset || (current_link_adapter_rx_state == STALL);
CRC CRC_CALC(
    .clk(clk),
    .reset(crc_reset),
    .enable(crc_calc_en),
    .message(crc_calc_input),
    .crc_output(crc_calc_output));
wire sof_detected = (ISERDES_in == L2_SOF_VAL);

// L3 Byte and Valid Delay Pipeline (Accounts for 4 cycle CRC evaluation delay) necessary to allign tuser sideband to L3-buffer
reg [7:0] d1, d2, d3, d4, d5;
reg v1, v2, v3, v4, v5;
always @(posedge clk) begin
    if(reset) begin
        d2 <= 0;
        d3 <= 0;
        d4 <= 0;
        d5 <= 0;

        v2 <= 0;
        v3 <= 0;
        v4 <= 0;
        v5 <= 0;

    end else begin
        d2 <= d1;
        d3 <= d2;
        d4 <= d3;
        d5 <= d4;

        v2 <= v1;
        v3 <= v2;
        v4 <= v3;
        v5 <= v4;
    end
end

// AXI RX<->L3 Buffer Interface
always_comb begin
    s_axis_tdata = d5;
    s_axis_tvalid = v5;
    s_axis_tlast = v5 && current_link_adapter_rx_state == (COMMIT);
    s_axis_tuser = ~valid_crc_flag && s_axis_tlast;
end


// LINK ADAPTER RX FSM COMBINATIONAL NEXT STATE
always_comb begin
    next_link_adapter_rx_state = current_link_adapter_rx_state;
    case (current_link_adapter_rx_state)
        STALL: begin
            if (!reset && sof_detected) begin
                next_link_adapter_rx_state = DISASSEMBLE;
            end else begin
                next_link_adapter_rx_state = STALL;
            end
        end
        DISASSEMBLE: begin
            // WAIT IN THIS STATE UNTIL L2 HEADER ENDS
             if(byte_ctr_in >= L2_TYPE_FLAGS_SIZE_BYTES-1) begin
                next_link_adapter_rx_state = ACQUIRE_LENGTH;
             end else begin
                next_link_adapter_rx_state = DISASSEMBLE;
             end
        end
        ACQUIRE_LENGTH: begin
            // OBTAIN L3 PACKET LENGTH
            if(byte_ctr_in >= L2_PAYLOAD_LENGTH_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES-1) begin
                next_link_adapter_rx_state = RECEIVE;
            end else begin
                next_link_adapter_rx_state = ACQUIRE_LENGTH;
            end
        end
        RECEIVE: begin
            // Read out L3 Packet Bytes
            if(byte_ctr_in >= L2_PAYLOAD_LENGTH_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES + latched_L3_packet_size-1) begin
                next_link_adapter_rx_state = CRC;
            end else begin
                next_link_adapter_rx_state = RECEIVE;
            end
        end
        CRC: begin
            // Confirm CRC matches
            if(byte_ctr_crc_in >= L2_CRC_SIZE_BYTES-1) begin
                next_link_adapter_rx_state = COMMIT;
            end else begin
                next_link_adapter_rx_state = CRC;
            end
        end
        COMMIT: begin
            // Commit last byte and mark valid/invalid to L3 Buffer
            next_link_adapter_rx_state = STALL;
        end
        default: begin
            next_link_adapter_rx_state = current_link_adapter_rx_state;
        end
    endcase
end

// LINK ADAPTER RX FSM COMBINATIONAL OUTPUTS
always_comb begin
    crc_calc_en = 0;
    case(current_link_adapter_rx_state)
        STALL: begin
            crc_calc_en = 0;
        end
        DISASSEMBLE: begin
            crc_calc_en = 1;
        end
        ACQUIRE_LENGTH: begin
            crc_calc_en = 1;
        end
        RECEIVE: begin
            crc_calc_en = 1;
        end
        CRC: begin
            crc_calc_en = 0;
        end
        COMMIT: begin
            crc_calc_en = 0;
        end
        default: begin
            crc_calc_en = 0;
        end
    endcase
end

// LINK ADAPTER RX FSM SEQUENTIAL UPDATE
always @(posedge clk) begin
    if(reset) begin
        current_link_adapter_rx_state <= STALL;
    end else begin
        current_link_adapter_rx_state <= next_link_adapter_rx_state;
    end
end


// MAIN SEQUENTIAL LOGIC:
always @(posedge clk) begin
    if(reset) begin
        byte_ctr_in <= 0;
        byte_ctr_crc_in <= 0;
        latched_L3_packet_size <= 0;
        d1 <= 0;
        v1 <= 0;
        valid_crc_flag <= 1;
    end else begin
        d1 <= 0;
        v1 <= 0;
         case (current_link_adapter_rx_state)
            STALL: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
                latched_L3_packet_size <= 0;
                valid_crc_flag <= 1;
            end
            DISASSEMBLE: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
            end
            ACQUIRE_LENGTH: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
                latched_L3_packet_size <= (latched_L3_packet_size >> 8) | {ISERDES_in, {((L2_PAYLOAD_LENGTH_SIZE_BYTES-1) << 3){1'b0}}};
            end
            RECEIVE: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
                d1 <= ISERDES_in;
                v1 <= 1;
            end
            CRC: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= byte_ctr_crc_in + 1;
                if (!crc_matched) begin
                    valid_crc_flag <= 0;
                end
            end
            COMMIT: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
            end
            default: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
            end
         endcase
    end
end


endmodule
