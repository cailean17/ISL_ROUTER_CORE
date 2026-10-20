`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/17/2026 03:28:48 PM
// Design Name: 
// Module Name: interfaces
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
/* verilator coverage_off */
interface laser_link_phy_if;
    logic [7:0] data;
    modport slave(input data);
    modport master(output data);
endinterface

interface link_adapter_rx_if;
    logic [7:0] l3_packet_byte;
    logic       s_axis_tready;
    logic [7:0] s_axis_tdata;
    logic       s_axis_tvalid;
    logic       s_axis_tlast;
    logic       s_axis_tuser;
endinterface

interface link_adapter_tx_if;
    // router->TX
    logic s_axis_router_cmd_tvalid;
    l3_packet_descriptor_t s_axis_router_cmd_tdata;
    logic s_axis_router_cmd_tready;
    // TX<->L3 buffer
    // (command) TX->L3 buffer
    logic m_axis_tx_cmd_tready;
    l3_packet_descriptor_t m_axis_tx_cmd_tdata;
    logic m_axis_tx_cmd_tvalid;
    // (data) L3 buffer -> TX
    logic [7:0] s_axis_tx_tdata;
    logic       s_axis_tx_tvalid;
    logic       s_axis_tx_tlast;
    logic       s_axis_tx_tready;
endinterface


interface l3_buffer_if;
    // RX->buffer
    logic [7:0] s_axis_rx_tdata;
    logic       s_axis_rx_tvalid;
    logic       s_axis_rx_tlast;
    logic       s_axis_rx_tuser;
    logic       s_axis_rx_tready;
    // buffer->router
    l3_packet_descriptor_t m_axis_pkt_desc_tdata;
    logic m_axis_pkt_desc_tvalid;
    logic m_axis_pkt_desc_tready;
   // TX<->buffer
   // (command) TX->buffer
    l3_packet_descriptor_t s_axis_tx_cmd_tdata;
    logic s_axis_tx_cmd_tvalid;
    logic s_axis_tx_cmd_tready;
   // (data) buffer->TX
    logic [7:0] m_axis_tx_tdata;
    logic m_axis_tx_tvalid;
    logic m_axis_tx_tlast;
    logic m_axis_tx_tready;

endinterface
/* verilator coverage_on */
