import packets_and_frames::*;

module l3_buffer
#()
(
    input clk,
    input reset,
    // RX<->buffer
    input  logic [7:0] s_axis_rx_tdata,
    input  logic       s_axis_rx_tvalid,
    input  logic       s_axis_rx_tlast,   // last L3 byte of the frame
    input  logic       s_axis_rx_tuser,   // meaningful on tlast: 1 = bad frame (CRC fail, timeout, bad length)
    output logic       s_axis_rx_tready,   // tied to 1'b1: the PHY can't be stalled
    // buffer<->router
    output packets_and_frames::l3_packet_descriptor_t m_axis_pkt_desc_tdata,
    output logic m_axis_pkt_desc_tvalid,
    input  logic m_axis_pkt_desc_tready,
   // TX<->buffer
   // (command) TX->buffer
    input  packets_and_frames::l3_packet_descriptor_t s_axis_tx_cmd_tdata,
    input  logic s_axis_tx_cmd_tvalid,
    output logic s_axis_tx_cmd_tready,
   // (data) buffer->TX
    output logic [7:0] m_axis_tx_tdata,
    output logic m_axis_tx_tvalid,
    output logic m_axis_tx_tlast,
    input  logic m_axis_tx_tready
);

// DRAM PACKET DESCRIPTOR BUFFER
// out-of-order servicing, in-order retirement
(* ram_style = "distributed" *) packets_and_frames::l3_packet_descriptor_t pkt_desc_buffer [RX_L3_DESC_BUFFER_DEPTH];
reg [$clog2(RX_L3_DESC_BUFFER_DEPTH)-1:0] pkt_desc_buffer_wr_ptr;
reg [$clog2(RX_L3_DESC_BUFFER_DEPTH)-1:0] pkt_desc_buffer_rd_ptr;
reg [$clog2(RX_L3_DESC_BUFFER_DEPTH)-1:0] pkt_desc_buffer_retire_ptr;
reg [RX_L3_DESC_BUFFER_DEPTH-1:0] pkt_desc_buffer_ready_to_retire;
reg [$clog2(RX_L3_DESC_BUFFER_DEPTH):0] unretired_cnt, pending_cnt;
wire retire = pkt_desc_buffer_ready_to_retire[pkt_desc_buffer_retire_ptr];
wire advertise = m_axis_pkt_desc_tvalid && m_axis_pkt_desc_tready;

// SDP BRAM ACTUAL PACKET BUFFER
(* ram_style = "block" *) reg [7:0] pkt_buffer [RX_L3_BUFFER_DEPTH_BYTES];
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] pkt_buffer_wr_ptr;
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] pkt_buffer_rd_ptr;
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] pkt_buffer_prev_wr_ptr;
reg [$clog2(L3_MAX_SIZE_BYTES):0] pkt_buffer_curr_pkt_len_bytes;
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES):0] pkt_buffer_bytes_used;
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES):0] pkt_buffer_bytes_free;
packets_and_frames::l3_packet_descriptor_t descriptor_wr;
reg [(L3_DEST_SAT_SIZE_BYTES*8)-1:0] dest_sat_wr;
assign descriptor_wr = '{start_ptr: pkt_buffer_prev_wr_ptr,
                           length: pkt_buffer_curr_pkt_len_bytes+1,
                           dest_sat: dest_sat_wr,
                           desc_id: pkt_desc_buffer_wr_ptr,
                           buffer_id: '0
                           };

localparam logic [$clog2(RX_L3_BUFFER_DEPTH_BYTES):0] UPPER_ROOM_THRESHOLD = RX_L3_BUFFER_DEPTH_BYTES - L3_MAX_SIZE_BYTES;

// Auxillary
always_comb begin
    // pkt_buffer_bytes_free = RX_L3_BUFFER_DEPTH_BYTES - pkt_buffer_bytes_used - pkt_buffer_curr_pkt_len_bytes;
    s_axis_rx_tready = 1;
end
reg first_beat;
wire no_desc_space = first_beat && (unretired_cnt == RX_L3_DESC_BUFFER_DEPTH);
wire no_packet_space = first_beat && (pkt_buffer_bytes_used > UPPER_ROOM_THRESHOLD);
wire packet_too_long = (pkt_buffer_curr_pkt_len_bytes == L3_MAX_SIZE_BYTES);
// wire no_bytes_left = pkt_buffer_bytes_free == 0;
// wire drop = (no_desc_space || no_bytes_left) && s_axis_rx_tvalid;
wire drop = (no_desc_space || no_packet_space || packet_too_long) && s_axis_rx_tvalid;
reg latched_drop;
wire last = (s_axis_rx_tlast && s_axis_rx_tvalid);
wire crc_mismatch = s_axis_rx_tuser; // RX raises tuser high on last byte to represent CRC error detection
wire accept = !drop && !latched_drop && s_axis_rx_tvalid;
wire commit = last && !crc_mismatch && accept;

// latched_drop logic
always_ff @(posedge clk) begin
    if(reset) begin
        latched_drop <= 0;
    end else begin
        if(s_axis_rx_tlast && s_axis_rx_tvalid) begin
            latched_drop <= 0;
        end else begin
            if(drop) begin
                latched_drop <= 1;
            end
        end
    end
end

// BRAM Packet Buffer Writing Logic
always_ff @(posedge clk) begin
    if (reset) begin
        pkt_buffer_wr_ptr <= 0;
        pkt_buffer_prev_wr_ptr <= 0;
        pkt_buffer_curr_pkt_len_bytes <= 0;
        pkt_buffer_bytes_used <= 0;
        dest_sat_wr <= 0;
        first_beat <= 1;
    end else begin
        pkt_buffer_bytes_used <= pkt_buffer_bytes_used
                    + (commit ? pkt_buffer_curr_pkt_len_bytes + 1 : 0)
                    - (retire ? pkt_desc_buffer[pkt_desc_buffer_retire_ptr].length : 0);
        if (first_beat) begin
            pkt_buffer_prev_wr_ptr <= pkt_buffer_wr_ptr;
        end
        if (accept) begin
            pkt_buffer_wr_ptr <= pkt_buffer_wr_ptr + 1;
            pkt_buffer_curr_pkt_len_bytes <= pkt_buffer_curr_pkt_len_bytes + 1;
            if (first_beat) begin
                first_beat <= 0;
            end
            if (pkt_buffer_curr_pkt_len_bytes == 1) begin
                // Register dest_sat(Second Byte of Packet) for current packet's descriptor
                dest_sat_wr <= s_axis_rx_tdata;
            end
        end
        if(last) begin
            if (!commit) begin
                // roll-back since link_adapter_RX marked packet as invalid
                pkt_buffer_wr_ptr <= pkt_buffer_prev_wr_ptr;
            end
            first_beat <= 1;
            pkt_buffer_curr_pkt_len_bytes <= 0;
        end
    end
end

// BRAM Packet Buffer Reading Logic
reg servicing_buffer_read;
packets_and_frames::l3_packet_descriptor_t descriptor_rd;
assign s_axis_tx_cmd_tready = !servicing_buffer_read;
reg [$clog2(L3_MAX_SIZE_BYTES):0] bytes_left;
wire on_last_byte_read;
assign on_last_byte_read = bytes_left == 1;
wire read_done = m_axis_tx_tvalid && m_axis_tx_tready && on_last_byte_read;
assign m_axis_tx_tlast = on_last_byte_read;
always_ff @(posedge clk) begin
    if(reset) begin
        descriptor_rd <= 0;
        servicing_buffer_read <= 0;
        pkt_buffer_rd_ptr <= 0;
        m_axis_tx_tvalid <= 0;
        bytes_left <= 0;
    end else begin
        m_axis_tx_tvalid <= servicing_buffer_read && !read_done;
        if(s_axis_tx_cmd_tready && s_axis_tx_cmd_tvalid) begin
                servicing_buffer_read <= 1;
                descriptor_rd <= s_axis_tx_cmd_tdata;
                pkt_buffer_rd_ptr <= s_axis_tx_cmd_tdata.start_ptr;
                bytes_left <= s_axis_tx_cmd_tdata.length;
        end else begin
            if(m_axis_tx_tvalid && m_axis_tx_tready) begin
                pkt_buffer_rd_ptr <= pkt_buffer_rd_ptr+1;
                bytes_left <= bytes_left-1;
                if (on_last_byte_read) begin
                    servicing_buffer_read <= 0;
                end
            end
        end
    end
end



// PORT A (READ)
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] pkt_buffer_port_a_addr;
reg [7:0] pkt_buffer_port_a_data;
reg pkt_buffer_port_a_en;
always_comb begin
    pkt_buffer_port_a_addr = (m_axis_tx_tready && m_axis_tx_tvalid) ? pkt_buffer_rd_ptr + 1 : pkt_buffer_rd_ptr;
    pkt_buffer_port_a_en = servicing_buffer_read;
    m_axis_tx_tdata = pkt_buffer_port_a_data;
end
always_ff @(posedge clk) begin
    if(pkt_buffer_port_a_en) begin
        pkt_buffer_port_a_data <= pkt_buffer[pkt_buffer_port_a_addr];
    end
end

// PORT B (WRITE)
reg [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] pkt_buffer_port_b_addr;
reg [7:0] pkt_buffer_port_b_data;
reg pkt_buffer_port_b_en;
always_comb begin
    pkt_buffer_port_b_addr = pkt_buffer_wr_ptr;
    pkt_buffer_port_b_data = s_axis_rx_tdata;
    pkt_buffer_port_b_en = accept;
end
always_ff @(posedge clk) begin
    if(pkt_buffer_port_b_en) begin
        pkt_buffer[pkt_buffer_port_b_addr] <= pkt_buffer_port_b_data;
    end
end

// BRAM PACKET DESCRIPTOR BUFFER LOGIC
assign m_axis_pkt_desc_tdata = pkt_desc_buffer[pkt_desc_buffer_rd_ptr];
assign m_axis_pkt_desc_tvalid = (pending_cnt != 0);

wire pkt_desc_buffer_rd = m_axis_pkt_desc_tready & m_axis_pkt_desc_tvalid;
wire pkt_desc_buffer_wr = commit;

always_ff @(posedge clk) begin
    if(reset) begin
        pkt_desc_buffer_wr_ptr <= 0;
        pkt_desc_buffer_rd_ptr <= 0;
        pkt_desc_buffer_retire_ptr <= 0;
        pkt_desc_buffer_ready_to_retire <= 0;
        unretired_cnt <= 0;
        pending_cnt <= 0;
    end else begin
        unretired_cnt <= unretired_cnt + commit - retire;     // committed, not yet retired
        pending_cnt   <= pending_cnt   + commit - advertise;   // committed, not yet advertised
        if (read_done) begin
            pkt_desc_buffer_ready_to_retire[descriptor_rd.desc_id] <= 1;
        end
        if (pkt_desc_buffer_ready_to_retire[pkt_desc_buffer_retire_ptr]) begin
            pkt_desc_buffer_retire_ptr <= pkt_desc_buffer_retire_ptr + 1;
            pkt_desc_buffer_ready_to_retire[pkt_desc_buffer_retire_ptr] <= 0;
        end
        case ({pkt_desc_buffer_rd, pkt_desc_buffer_wr})
            2'b00: begin
                pkt_desc_buffer_rd_ptr <= pkt_desc_buffer_rd_ptr;
                pkt_desc_buffer_wr_ptr <= pkt_desc_buffer_wr_ptr;
            end
            2'b01: begin
                pkt_desc_buffer_rd_ptr <= pkt_desc_buffer_rd_ptr;
                pkt_desc_buffer_wr_ptr <= pkt_desc_buffer_wr_ptr+1;
            end
           2'b10: begin
                pkt_desc_buffer_rd_ptr <= pkt_desc_buffer_rd_ptr+1;
                pkt_desc_buffer_wr_ptr <= pkt_desc_buffer_wr_ptr;
            end
            2'b11: begin
                pkt_desc_buffer_rd_ptr <= pkt_desc_buffer_rd_ptr+1;
                pkt_desc_buffer_wr_ptr <= pkt_desc_buffer_wr_ptr+1;
            end
            default: begin
                pkt_desc_buffer_rd_ptr <= pkt_desc_buffer_rd_ptr;
                pkt_desc_buffer_wr_ptr <= pkt_desc_buffer_wr_ptr;
            end
        endcase
        if (commit) begin
            pkt_desc_buffer[pkt_desc_buffer_wr_ptr] <= descriptor_wr;
        end
    end
end

endmodule
