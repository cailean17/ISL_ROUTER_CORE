`timescale 1ns / 1ps
// Router receive sink port: consumes descriptors for packets addressed to THIS satellite, reads the
// bytes out of the owning L3 buffer, and streams them to the host/ground interface.
// Port names mirror link_adapter_tx so it plugs into the same link_adapter_tx_if slot
// (the extra egress entry, index NUM_LINKS) and is arbitrated like any other TX.
module downlink
#()
(
    input   wire clk,
    input   wire reset,

    // DOWNLINK<->router (descriptors whose FIB lookup said "local")
    input   logic s_axis_router_cmd_tvalid,
    input   packets_and_frames::l3_packet_descriptor_t s_axis_router_cmd_tdata,
    output  logic s_axis_router_cmd_tready,

    // DOWNLINK<->L3 buffer
    // (command) DOWNLINK->L3 buffer (tdata carries buffer_id so the buffer arbiter can route it)
    input   logic m_axis_tx_cmd_tready,
    output  packets_and_frames::l3_packet_descriptor_t m_axis_tx_cmd_tdata,
    output  logic m_axis_tx_cmd_tvalid,

    // (data) L3 buffer->DOWNLINK
    input   logic [7:0] s_axis_tx_tdata,
    input   logic       s_axis_tx_tvalid,
    input   logic       s_axis_tx_tlast,
    output  logic       s_axis_tx_tready
);

typedef enum logic [1:0] {STALL, FETCH, STREAM} local_downlink_fsm_states_e;
local_downlink_fsm_states_e current_downlink_state, next_downlink_state;

packets_and_frames::l3_packet_descriptor_t latched_descriptor;

// AXI: descriptor in (accepted only while STALLED)
assign s_axis_router_cmd_tready = current_downlink_state == STALL;
wire handshake_router_cmd;
assign handshake_router_cmd = s_axis_router_cmd_tvalid & s_axis_router_cmd_tready;

// AXI: read command out (held until the buffer arbiter accepts it)
assign m_axis_tx_cmd_tdata  = latched_descriptor;
assign m_axis_tx_cmd_tvalid = current_downlink_state == FETCH;

// AXI: byte stream
assign s_axis_tx_tready = (current_downlink_state == STREAM);

wire last_byte_transferred = s_axis_tx_tvalid && s_axis_tx_tready && s_axis_tx_tlast;

// DOWNLINK: combinational next state
always_comb begin
    next_downlink_state = current_downlink_state;
    case (current_downlink_state)
        STALL: begin
            if (s_axis_router_cmd_tvalid && s_axis_router_cmd_tready) begin
                next_downlink_state = FETCH;
            end
        end
        FETCH: begin
            if (m_axis_tx_cmd_tvalid && m_axis_tx_cmd_tready) begin
                next_downlink_state = STREAM;
            end
        end
        STREAM: begin
            if (last_byte_transferred) begin
                next_downlink_state = STALL;
            end
        end
        default: begin
            next_downlink_state = STALL;
        end
    endcase
end

// sequential state update
always @(posedge clk) begin
    if (reset) begin
        current_downlink_state <= STALL;
    end else begin
        current_downlink_state <= next_downlink_state;
    end
end

// main sequential logic
always @(posedge clk) begin
    if (reset) begin
        latched_descriptor <= 0;
    end else if (handshake_router_cmd) begin
        latched_descriptor <= s_axis_router_cmd_tdata;
    end
end

endmodule
