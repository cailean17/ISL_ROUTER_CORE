// CRC-32/ISO-HDLC: IEEE 802.3 REVERSED POLY: 0xEDB88320

module CRC #(parameter int POLY = 32'hEDB88320, parameter int MESSAGE_SLICE_SIZE_BITS = 8)(
    input [MESSAGE_SLICE_SIZE_BITS-1:0] message,
    input reset,
    input enable,
    input clk,
    output reg [31:0] CRC_REG
);

reg [31:0] PRECOMPUTED_CRC [(1 << MESSAGE_SLICE_SIZE_BITS)];

initial begin
   $readmemh("../../utils/CRC_TABLE.mem", PRECOMPUTED_CRC);
end

// 8-bit slice CRC calculation.
always @(posedge clk) begin
    if(reset) begin
        // new packet CRC calculation
        CRC_REG <= 32'hFFFFFFFF;
    end else if (enable) begin
        CRC_REG <= {8'h00, CRC_REG[31:8]} ^ PRECOMPUTED_CRC[CRC_REG[7:0] ^ message];
    end else begin
        CRC_REG <= CRC_REG;
    end
end
endmodule
