import packets_and_frames::*;
module link_adapter_rx
#(parameter int PACKET_COUNT = 8)
(
    input wire clk,
    input wire reset,
    input logic packet_ready,
    input logic [7:0] ISERDES_in,
    output wire [(L3_MAX_SIZE_BYTES << 3)-1 : 0] rx_packet,
    output wire packet_valid // AXI MASTER VALID
);

typedef enum logic [2:0] {STALL, DISASSEMBLE, ACQUIRE_LENGTH, RECONSTRUCT, CRC, COMMIT} link_adapter_rx_fsm_states;
link_adapter_rx_fsm_states current_link_adapter_rx_state, next_link_adapter_rx_state;


// LAYER 3 packet to send to router core (LSB first, SrcSat transmitted first):
// [Reserved(2047:2040), Payload(2039:40), Length(39:24), TTL(23:16), DestSat(15:8), SrcSat(7:0)]

// 8 L3 PACKET SDP BRAM RING FIFO BUFFER
(* ram_style = "block" *) reg [((L3_MAX_SIZE_BYTES << 3)-1):0] fifo_ring_buffer [PACKET_COUNT-1:0];
reg [$clog2(PACKET_COUNT)-1:0] fifo_ring_write_ptr, fifo_ring_top_ptr;
reg [$clog2(PACKET_COUNT):0] fifo_ring_size;
wire fifo_full = fifo_ring_size == PACKET_COUNT;
wire fifo_empty = (fifo_ring_size == 0);
wire crc_matched;
assign packet_valid = !fifo_empty && !reset; // AXI MASTER VALID
assign rx_packet = fifo_ring_buffer_port_a_rd_data;


// LAYER 2 frame received from PHY (LSB first, SOF transmitted first):
// [CRC32(2111:2080), L3_Packet(2079:32), Length(31:16),Type(15:12), Flags(11:8), SOF(7:0)]
reg [8:0] byte_ctr_in;
reg [1:0] byte_ctr_crc_in;
reg [((L3_MAX_SIZE_BYTES << 3)-1):0] received_L3_packet;
reg [(L2_PAYLOAD_LENGTH_SIZE_BYTES << 3)-1:0] latched_L3_packet_size;
reg [(L2_CRC_SIZE_BYTES << 3)-1: 0] crc_calc_output;
wire [7:0] crc_calc_input = ISERDES_in;
reg [(L2_CRC_SIZE_BYTES << 3)-1: 0] received_crc;
assign crc_matched = (received_crc == (crc_calc_output ^ { (L2_CRC_SIZE_BYTES<<3){1'b1} }));
reg crc_calc_en;
wire crc_reset = reset || (current_link_adapter_rx_state == STALL);
CRC CRC_CALC(crc_calc_input, crc_reset, crc_calc_en, clk, crc_calc_output);
wire sof_detected = (ISERDES_in == L2_SOF_VAL);


// SDP BRAM RING FIFO RING BUFFER
// Read Port (A)
reg [$clog2(PACKET_COUNT)-1:0] fifo_ring_buffer_port_a_addr;
reg fifo_ring_buffer_port_a_rd_en;
reg [((L3_MAX_SIZE_BYTES << 3)-1):0] fifo_ring_buffer_port_a_rd_data;
always @(posedge clk) begin
    if(fifo_ring_buffer_port_a_rd_en) begin
        fifo_ring_buffer_port_a_rd_data <= fifo_ring_buffer[fifo_ring_buffer_port_a_addr];
    end
end

// Write Port (B)
reg [$clog2(PACKET_COUNT)-1: 0] fifo_ring_buffer_port_b_addr;
reg fifo_ring_buffer_port_b_w_en;
reg [((L3_MAX_SIZE_BYTES*8)-1): 0] fifo_ring_buffer_port_b_w_data;
always @(posedge clk) begin
    if(fifo_ring_buffer_port_b_w_en) begin
        fifo_ring_buffer[fifo_ring_buffer_port_b_addr] <= fifo_ring_buffer_port_b_w_data;
    end
end

// combinational BRAM input
always_comb begin
    fifo_ring_buffer_port_a_addr = fifo_ring_top_ptr;
    fifo_ring_buffer_port_a_rd_en = packet_valid;
    fifo_ring_buffer_port_b_addr = fifo_ring_write_ptr;
    fifo_ring_buffer_port_b_w_data = received_L3_packet;
    fifo_ring_buffer_port_b_w_en = (current_link_adapter_rx_state == COMMIT && crc_matched);
end

// RING FIFO POINTERS:
wire pop_fifo = packet_valid && packet_ready;
reg push_fifo;
always @(posedge clk) begin
    if(reset) begin
       fifo_ring_write_ptr <= 0;
       fifo_ring_top_ptr <= 0;
       fifo_ring_size <= 0;
    end else begin
        if(push_fifo) begin
            if(fifo_ring_write_ptr == PACKET_COUNT -1) begin
                fifo_ring_write_ptr <= 0;
            end else begin
                fifo_ring_write_ptr <=  fifo_ring_write_ptr + 1;
             end
        end
        if(pop_fifo) begin
            if(fifo_ring_top_ptr == PACKET_COUNT -1) begin
                fifo_ring_top_ptr <= 0;
            end else begin
                fifo_ring_top_ptr <= fifo_ring_top_ptr + 1;
            end
        end
        case ({push_fifo, pop_fifo})
            2'b00: fifo_ring_size <= fifo_ring_size; 
            2'b01: fifo_ring_size <= fifo_ring_size - 1; 
            2'b10: fifo_ring_size <= fifo_ring_size + 1;
            2'b11: fifo_ring_size <= fifo_ring_size;
        endcase
    end
end


// LINK ADAPTER RX FSM COMBINATIONAL NEXT STATE
always @(*) begin
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
            if(byte_ctr_in >= L2_PAYLOAD_LENGTH_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES -1) begin
                next_link_adapter_rx_state = RECONSTRUCT;
            end else begin
                next_link_adapter_rx_state = ACQUIRE_LENGTH;
            end
        end
        RECONSTRUCT: begin
            if(byte_ctr_in >= L2_PAYLOAD_LENGTH_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES + latched_L3_packet_size-1) begin
                next_link_adapter_rx_state = CRC;
            end else begin
                next_link_adapter_rx_state = RECONSTRUCT;
            end
        end
        CRC: begin
            if(byte_ctr_crc_in >= L2_CRC_SIZE_BYTES-1) begin
                next_link_adapter_rx_state = COMMIT;
            end else begin
                next_link_adapter_rx_state = CRC;
            end
        end
        COMMIT: begin
            next_link_adapter_rx_state = STALL;
        end
    endcase
end

// LINK ADAPTER RX FSM COMBINATIONAL OUTPUTS
always @(*) begin
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
        RECONSTRUCT: begin
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
        received_L3_packet <= 0;
        received_crc <= 0;
        latched_L3_packet_size <= 0;
        push_fifo <= 0;
    end else begin
         case (current_link_adapter_rx_state)
            STALL: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
                received_L3_packet <= 0;
                received_crc <= 0;
                latched_L3_packet_size <= 0;
                push_fifo <= 0;
            end
            DISASSEMBLE: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
                push_fifo <= 0;
            end
            ACQUIRE_LENGTH: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
                latched_L3_packet_size <= (latched_L3_packet_size >> 8) | {ISERDES_in, {((L2_PAYLOAD_LENGTH_SIZE_BYTES-1) << 3){1'b0}}};
                push_fifo <= 0;
            end
            RECONSTRUCT: begin
                byte_ctr_in <= byte_ctr_in + 1;
                byte_ctr_crc_in <= 0;
                received_L3_packet[((byte_ctr_in - (L2_TYPE_FLAGS_SIZE_BYTES+L2_PAYLOAD_LENGTH_SIZE_BYTES)) << 3)+:8] <= ISERDES_in;
                push_fifo <= 0;
            end
            CRC: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= byte_ctr_crc_in + 1;
                received_crc <= (received_crc >> 8) | {ISERDES_in, {((L2_CRC_SIZE_BYTES-1) << 3){1'b0}}};
                push_fifo <= 0;
            end
            COMMIT: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
                if(crc_matched) begin
                    push_fifo <= 1;
                end else begin
                    push_fifo <= 0;
                end
            end
            default: begin
                byte_ctr_in <= 0;
                byte_ctr_crc_in <= 0;
                push_fifo <= 0;
            end
         endcase
    end
end


endmodule
