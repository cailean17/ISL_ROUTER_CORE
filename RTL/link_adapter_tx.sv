import packets_and_frames::*;

module link_adapter_tx
#()
(
    input   wire clk,
    input   wire reset,

    // TX<->router
    input   logic s_axis_router_cmd_tvalid,
    input   l3_packet_descriptor_t s_axis_router_cmd_tdata,
    output  logic s_axis_router_cmd_tready,

    // TX<->L3 buffer
    // (command) TX->L3 buffer
    input   logic m_axis_tx_cmd_tready,
    output  l3_packet_descriptor_t m_axis_tx_cmd_tdata,
    output  logic m_axis_tx_cmd_tvalid,

    // (data)
    input  logic [7:0] s_axis_tx_tdata,
    input  logic       s_axis_tx_tvalid,
    input  logic       s_axis_tx_tlast,
    output logic       s_axis_tx_tready,

    // TX->PHY
    output reg [7:0]   OSERDES_out
);
typedef enum logic [2:0] {STALL, FETCH, ASSEMBLE, TRANSMIT, CRC} link_adapter_fsm_states_e;
link_adapter_fsm_states_e current_link_adapter_state, next_link_adapter_state;

// LAYER 3 packet from router core (LSB first, SrcSat transmitted first):
// [Reserved(2047:2040), Payload(2039:40), Length(39:24), TTL(23:16), DestSat(15:8), SrcSat(7:0)]

// LAYER 2 frame (LSB first, SOF transmitted first):
// [CRC32(2111:2080), PAYLOAD: L3_Packet(2079:32), Length(31:16),Type(15:12), Flags(11:8), SOF(7:0)]
reg [$clog2(L2_MAX_SIZE_BYTES):0] byte_ctr_shift;
reg [1:0] byte_ctr_crc_shift; 
l3_packet_descriptor_t latched_descriptor;

// BYTE BEING LOADED ONTO THE PHY THIS CYCLE (shared by OSERDES_out and the CRC)
logic [7:0] tx_byte;
wire handshake = s_axis_tx_tvalid && s_axis_tx_tready;
always_comb begin
    tx_byte = 8'h00;
    case (current_link_adapter_state)
        ASSEMBLE: begin
            case (byte_ctr_shift[1:0])
                2'd0: tx_byte = L2_SOF_VAL;
                2'd1: tx_byte = 8'h00;
                2'd2: tx_byte = latched_descriptor.length[7:0];
                2'd3: tx_byte = 8'(latched_descriptor.length >> 8);
                default: tx_byte = tx_byte;
            endcase
        end
        TRANSMIT: tx_byte = s_axis_tx_tdata;
        default: ;
    endcase
end

// CRC
reg [(L2_CRC_SIZE_BYTES << 3)-1: 0] crc_calc_output;
reg [7:0] crc_byte_output;
wire [7:0] crc_calc_input = tx_byte;
wire crc_calc_en;
assign crc_calc_en = (current_link_adapter_state == ASSEMBLE && byte_ctr_shift >= 1)
                  || (current_link_adapter_state == TRANSMIT && handshake);
wire crc_reset = reset || (current_link_adapter_state == FETCH);
CRC CRC_CALC(
    .message(crc_calc_input),
    .reset(crc_reset),
    .enable(crc_calc_en),
    .clk(clk),
    .crc_output(crc_calc_output)
);
always_comb begin
    case (byte_ctr_crc_shift)
        2'd0: crc_byte_output = crc_calc_output[7:0]   ^ 8'hFF;
        2'd1: crc_byte_output = crc_calc_output[15:8]  ^ 8'hFF;
        2'd2: crc_byte_output = crc_calc_output[23:16] ^ 8'hFF;
        2'd3: crc_byte_output = crc_calc_output[31:24] ^ 8'hFF;
        default:  crc_byte_output = 8'h00;
    endcase
end

// AXI:
assign s_axis_router_cmd_tready = current_link_adapter_state == STALL;
assign m_axis_tx_cmd_tdata = latched_descriptor;
assign m_axis_tx_cmd_tvalid = current_link_adapter_state == FETCH;
assign s_axis_tx_tready = current_link_adapter_state == TRANSMIT;

// LINK ADAPTER: combinational next state
always_comb begin
    next_link_adapter_state = current_link_adapter_state;
    case (current_link_adapter_state)
        STALL: begin
            if(s_axis_router_cmd_tvalid && s_axis_router_cmd_tready) begin
                next_link_adapter_state = FETCH;
            end
        end
        FETCH: begin
            if(m_axis_tx_cmd_tready && m_axis_tx_cmd_tvalid) begin
                next_link_adapter_state = ASSEMBLE;
            end            
        end
        ASSEMBLE: begin
            if(byte_ctr_shift >= L2_SOF_SIZE_BYTES
                + L2_TYPE_FLAGS_SIZE_BYTES
                + L2_PAYLOAD_LENGTH_SIZE_BYTES - 1) begin
                next_link_adapter_state = TRANSMIT;
            end
        end
        TRANSMIT: begin
            if(s_axis_tx_tlast && s_axis_tx_tready && s_axis_tx_tvalid) 
            begin
                next_link_adapter_state = CRC;
            end
        end
        CRC: begin
            if(byte_ctr_crc_shift >= 3) begin
                    next_link_adapter_state = STALL;
            end
        end
        default: begin
            next_link_adapter_state = current_link_adapter_state;
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

// MAIN sequential logic:
always @(posedge clk) begin
    if (reset) begin
        byte_ctr_shift <= 0;
        byte_ctr_crc_shift <= 0;
        latched_descriptor <= 0;
        OSERDES_out <= 0;
    end else begin
        case (current_link_adapter_state)
            STALL: begin
                latched_descriptor <= s_axis_router_cmd_tdata;
                byte_ctr_shift <= 0;
                byte_ctr_crc_shift <= 0;
                OSERDES_out <= 0;
            end
            ASSEMBLE: begin
                OSERDES_out <= tx_byte;
                byte_ctr_shift <= byte_ctr_shift + 1;
            end
            TRANSMIT: begin
                if (handshake) begin
                    OSERDES_out <= tx_byte;
                    byte_ctr_shift <= byte_ctr_shift + 1;
                end
                byte_ctr_crc_shift <= 0;
            end
            CRC: begin
                OSERDES_out <= crc_byte_output;
                byte_ctr_crc_shift <= byte_ctr_crc_shift + 1;
            end
            default: begin
                byte_ctr_shift <= byte_ctr_shift;
                byte_ctr_crc_shift <= byte_ctr_crc_shift;
                latched_descriptor <= latched_descriptor;
                OSERDES_out <= OSERDES_out;
            end
        endcase
    end
end

endmodule