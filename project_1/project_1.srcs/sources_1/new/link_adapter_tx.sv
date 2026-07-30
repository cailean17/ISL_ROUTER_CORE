    
    //////////////////////////////////////////////////////////////////////////////////
    // Company: 
    // Engineer: 
    // 
    // Create Date: 02/12/2026 04:08:41 PM
    // Design Name: 
    // Target Devices: 
    // Tool Versions: 
    // Description: 
    // 
    // Dependencies: 
    // Module Name: link_adapter
    // Project Name: 
    // 
    // Revision:
    // Revision 0.01 - File Created
    // Additional Comments:
    // 
    //////////////////////////////////////////////////////////////////////////////////
    import packets_and_frames::*;
    module link_adapter_tx 
    #(parameter int PACKET_COUNT = 8)
    (
        input wire clk, 
        input wire reset,
        input wire [(L3_MAX_SIZE_BYTES << 3)-1 : 0] tx_packet,
        input wire packet_valid, // AXI MASTER VALID
        output logic packet_ready,
        output reg [7:0] OSERDES_out
    );
    typedef enum logic [2:0] {STALL, FETCH, ASSEMBLE, SHIFT, CRC_SHIFT} link_adapter_fsm_states;
    link_adapter_fsm_states current_link_adapter_state, next_link_adapter_state;
    
    
    // LAYER 3 packet from router core (LSB first, SrcSat transmitted first):
    // [Reserved(2047:2040), Payload(2039:40), Length(39:24), TTL(23:16), DestSat(15:8), SrcSat(7:0)]
    
    // 8 L3 PACKET SDP BRAM RING fifo_ring BUFFER
    (* ram_style = "block" *) reg [((L3_MAX_SIZE_BYTES << 3)-1):0] fifo_ring_buffer [PACKET_COUNT-1:0];
    reg [$clog2(PACKET_COUNT)-1:0] fifo_ring_write_ptr, fifo_ring_top_ptr;
    reg [$clog2(PACKET_COUNT):0] fifo_ring_size;
    wire fifo_full = fifo_ring_size == PACKET_COUNT;
    wire fifo_empty = (fifo_ring_size == 0);
    assign packet_ready = !fifo_full && !reset; // AXI SLAVE READY
     
     
    // SDP BRAM RING FIFO RING BUFFER
    // Read Port (A)
    reg [$clog2(PACKET_COUNT)-1:0] fifo_ring_buffer_port_a_addr;
    reg fifo_ring_buffer_port_a_rd_en;
    reg [((L3_MAX_SIZE_BYTES << 3)-1)  : 0] fifo_ring_buffer_port_a_rd_data;
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
    always @(*) begin
        fifo_ring_buffer_port_a_addr = fifo_ring_top_ptr;
        fifo_ring_buffer_port_a_rd_en = current_link_adapter_state == FETCH;
        fifo_ring_buffer_port_b_addr = fifo_ring_write_ptr;
        fifo_ring_buffer_port_b_w_data = tx_packet;
        fifo_ring_buffer_port_b_w_en = packet_valid && packet_ready;
    end
    
    // RING FIFO POINTERS:
    wire push_fifo = packet_valid && packet_ready;
    reg pop_fifo;
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
    
    // LAYER 2 frame (LSB first, SOF transmitted first):
    // [CRC32(2111:2080), L3_Packet(2079:32), Length(31:16),Type(15:12), Flags(11:8), SOF(7:0)]
    reg [(L2_MAX_SIZE_BYTES << 3)-(L2_CRC_SIZE_BYTES << 3)-1:0] L2_frame_shift_reg;
    reg [8:0] byte_ctr_shift; 
    reg [1:0] byte_ctr_crc_shift; 
    reg [(L2_PAYLOAD_LENGTH_SIZE_BYTES << 3)-1:0] latched_L3_packet_size; 
    reg [(L2_PAYLOAD_LENGTH_SIZE_BYTES << 3)-1:0] curr_L3_packet_size;
    reg [(L2_CRC_SIZE_BYTES << 3)-1: 0] crc_calc_output;
    reg [7:0] crc_byte_output; 
    wire [7:0] crc_calc_input = L2_frame_shift_reg[7:0];
    reg crc_calc_en;
    wire crc_reset = reset || (current_link_adapter_state == FETCH);
    CRC CRC_CALC(crc_calc_input, crc_reset, crc_calc_en, clk, crc_calc_output);
    
    // LINK ADAPTER: combinational next state
    always @(*) begin
        next_link_adapter_state = current_link_adapter_state;
        case (current_link_adapter_state)
            STALL: begin
                if(!reset && !fifo_empty) begin
                    next_link_adapter_state = FETCH;
                end
            end
            FETCH: begin
                next_link_adapter_state = ASSEMBLE;
            end
            ASSEMBLE: begin
                next_link_adapter_state = SHIFT;
            end
            SHIFT: begin
                if(byte_ctr_shift >= L2_SOF_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES + L2_PAYLOAD_LENGTH_SIZE_BYTES + latched_L3_packet_size-1) begin
                    next_link_adapter_state = CRC_SHIFT;
                end else begin
                    next_link_adapter_state = SHIFT;
                end 
            end
            CRC_SHIFT: begin
                if(byte_ctr_crc_shift >= 3) begin
                    if(!fifo_empty) begin
                        next_link_adapter_state = FETCH;
                    end else begin
                        next_link_adapter_state = STALL;
                    end
                end else begin
                    next_link_adapter_state = CRC_SHIFT;
                end
            end
            default: begin
                next_link_adapter_state = current_link_adapter_state; 
            end
        endcase
    end
    
    // LINK ADATPER: combinational outputs: 
    always @(*) begin
        curr_L3_packet_size = 0;
        crc_calc_en = 0;
        case (current_link_adapter_state)
            SHIFT: begin
                curr_L3_packet_size = 0;
                crc_calc_en   = (byte_ctr_shift >= 1);  // IEEE 802.3 exclude SOF from crc calcuation
            end
            ASSEMBLE: begin
                curr_L3_packet_size = fifo_ring_buffer_port_a_rd_data[L3_PAYLOAD_LENGTH_MSB:L3_PAYLOAD_LENGTH_LSB] + (L3_SIZE_BYTES_WITHOUT_PAYLOAD);
                crc_calc_en = 0;            
            end
            default: begin
                curr_L3_packet_size = 0; 
                crc_calc_en = 0;
            end
        endcase
    end
    
    // LINK ADAPTER: sequential state update: 
    always @(posedge clk) begin
        if(reset) begin
            current_link_adapter_state <= STALL;
        end else begin
            current_link_adapter_state <= next_link_adapter_state;
        end
    end
    
    
    // MAIN combinational logic: 
    always @(*) begin
        case (byte_ctr_crc_shift)
            2'd0: crc_byte_output = crc_calc_output[7:0]   ^ 8'hFF;
            2'd1: crc_byte_output = crc_calc_output[15:8]  ^ 8'hFF;
            2'd2: crc_byte_output = crc_calc_output[23:16] ^ 8'hFF;
            2'd3: crc_byte_output = crc_calc_output[31:24] ^ 8'hFF;
            default:  crc_byte_output = 8'h00;
        endcase
    end
    // MAIN sequential logic: 
    always @(posedge clk) begin
        if (reset) begin
            L2_frame_shift_reg <= 0;
            byte_ctr_shift <= 0; 
            byte_ctr_crc_shift <= 0; 
            pop_fifo <= 0;
            latched_L3_packet_size <= 0;
            OSERDES_out <= 0; 
        end else if(current_link_adapter_state == FETCH) begin
            L2_frame_shift_reg <= 0;
            byte_ctr_shift <= 0; 
            byte_ctr_crc_shift <= 0; 
            pop_fifo <= 0; 
            latched_L3_packet_size <= 0;
            OSERDES_out <= 0; 
        end else if(current_link_adapter_state == ASSEMBLE) begin
            L2_frame_shift_reg <= {fifo_ring_buffer_port_a_rd_data, curr_L3_packet_size, {(L2_TYPE_FLAGS_SIZE_BYTES << 3){1'b0}}, L2_SOF_VAL};
            byte_ctr_shift <= 0; 
            byte_ctr_crc_shift <= 0; 
            latched_L3_packet_size <= curr_L3_packet_size;
            OSERDES_out <= 0;
            pop_fifo <= 1; 
        end else if(current_link_adapter_state == SHIFT) begin
            OSERDES_out <= L2_frame_shift_reg[7:0];
            L2_frame_shift_reg >>= 8; 
            byte_ctr_shift <= byte_ctr_shift + 1;
            pop_fifo <= 0;
        end else if(current_link_adapter_state == CRC_SHIFT) begin
            OSERDES_out <= crc_byte_output; 
            byte_ctr_crc_shift <= byte_ctr_crc_shift + 1;
            pop_fifo <= 0;
        end else begin
            L2_frame_shift_reg <= 0;
            byte_ctr_shift <= 0; 
            byte_ctr_crc_shift <= 0; 
            pop_fifo <= 0;
            latched_L3_packet_size <= 0;
            OSERDES_out <= 0; 
        end
    end
    
    endmodule
