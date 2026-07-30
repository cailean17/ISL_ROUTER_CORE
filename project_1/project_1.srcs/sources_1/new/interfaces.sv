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

interface link_adapter_if;
    logic [(L3_MAX_SIZE_BYTES << 3)-1: 0] l3_packet;
    logic axi_valid;
    logic axi_ready;

    modport slave (input l3_packet, input axi_valid, output axi_ready);
    modport master (output l3_packet, output axi_valid, input axi_ready); 
endinterface

interface laser_link_phy_if;
    logic [7:0] data;

    modport slave(input data);
    modport master(output data);
endinterface

