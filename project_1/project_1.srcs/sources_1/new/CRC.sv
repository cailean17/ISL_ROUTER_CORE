// reverse IEEE 802.3 POLY 0xEDB88320

module CRC #(parameter POLY = 32'hEDB88320, parameter MESSAGE_SLICE_SIZE_BITS = 8)(
    input [MESSAGE_SLICE_SIZE_BITS-1:0] message,
    input reset,
    input enable,
    input clk, 
    output reg [31:0] CRC
);

reg [31:0] PRECOMPUTED_CRC [0:(1 << MESSAGE_SLICE_SIZE_BITS)-1];

initial begin
   $readmemh("CRC_TABLE.mem", PRECOMPUTED_CRC);
end

// 8-bit slice CRC calculation.
always @(posedge clk) begin
    if(reset) begin
        // new packet CRC calculation
        CRC <= 32'hFFFFFFFF; 
    end else if (enable) begin
        CRC <= {8'h00, CRC[31:8]} ^ PRECOMPUTED_CRC[CRC[7:0] ^ message];
    end else begin
        CRC <= CRC;
    end
end

endmodule