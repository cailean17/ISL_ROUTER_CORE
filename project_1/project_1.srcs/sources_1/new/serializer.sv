`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/12/2026 02:51:52 PM
// Design Name: 
// Module Name: serializer
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

// Serially shift out 8-bit slices of frames (LSB FIRST) from link_adapter
// Back pressure aware with AXI-esque valid/ready handshake

module serializer
    #(parameter int SLICE_WIDTH = 8)
    (
    input wire reset,
    input wire clk,
    input reg [SLICE_WIDTH-1:0] packet_slice, 
    input wire packet_end,
    input wire load_valid, // driven high by link_adapter when new packet slice is ready to be serialized
    output reg load_ready,// Used by sender link_adapter to know when serializer is ready for new data.
    input reg tx_ready,
    output reg tx_valid, 
    output wire tx_serial // serial output to virtual_isl_link
    );
    
reg [($clog2(SLICE_WIDTH)):0] shift_counter;
reg [SLICE_WIDTH-1:0] shift_reg;

// continuous assignmnet for output
assign tx_serial = shift_reg[0];

//fsm variables
typedef enum logic [2:0] {
    IDLE,
    LOAD_READY,
    LOAD_DATA, 
    SHIFT_VALID, 
    SHIFT_DATA
} ser_fsm_state;

ser_fsm_state current_state, next_state;

//registered fsm outputs 
always @(posedge clk or posedge reset) begin
    if(reset) begin 
        current_state <= IDLE; 
        shift_counter <= 0;
        shift_reg <= 0;
        tx_valid <= 0; 
        load_ready <= 0; 
    end else begin
        case (current_state)
            IDLE: begin
                shift_counter <= 0; 
                shift_reg <= 0; 
                load_ready <= 0; 
                tx_valid <= 0; 
            end 
            LOAD_READY: begin
                shift_reg <= 0; 
                shift_counter <= 0;
                load_ready <= 1;
                tx_valid <= 0;
            end
            LOAD_DATA: begin
                shift_reg <= packet_slice;
                shift_counter <= 0; 
                load_ready <= 0; 
                tx_valid <= 0;
            end
            SHIFT_VALID: begin
                load_ready <= 0;
                tx_valid <= 1; 
            end 
            SHIFT_DATA: begin
                shift_counter <= shift_counter + 1; 
                shift_reg <= {0, shift_reg[SLICE_WIDTH-1:1]};
                load_ready <= 0;
                tx_valid <= 0;
            end
        endcase
    end
end

// next state fsm logic
always @(*) begin
    case (current_state)
        IDLE: begin
            if(load_valid) begin
                next_state = LOAD_READY;
            end else begin
                next_state = IDLE;
            end
        end 
        LOAD_READY: begin
            next_state = LOAD_DATA;
        end
        LOAD_DATA: begin
           next_state = SHIFT_VALID;
        end
        SHIFT_VALID: begin
           if(shift_counter >= SLICE_WIDTH) begin
             next_state = IDLE;
           end else begin
               if(tx_ready) begin
                    next_state = SHIFT_DATA;
               end else begin
                    next_state = SHIFT_VALID;
               end
           end
        end
        SHIFT_DATA: begin
            next_state = SHIFT_VALID;
        end
        default: next_state = IDLE;
    endcase
end


endmodule
