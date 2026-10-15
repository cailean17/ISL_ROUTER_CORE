package packets_and_frames;

    // ============================================================
    // L3 DEFINITIONS
    // ============================================================
    // [Reserved(2047:2040), Payload(2039:40), Length(39:24), TTL(23:16), DestSat(15:8), SrcSat(7:0)]

    parameter int NUM_LINKS                     = 4;
    parameter int L3_SRC_SAT_SIZE_BYTES         = 1;
    parameter int L3_DEST_SAT_SIZE_BYTES        = 1;
    parameter int L3_TTL_SIZE_BYTES             = 1;
    parameter int L3_PAYLOAD_LENGTH_SIZE_BYTES  = 2; // REPRESENTS PACKET LENGTH IN BYTES (SATURATE AT L3_PAYLOAD_MAX_SIZE_BYTES)
    parameter int L3_RESERVED_LENGTH_SIZE_BYTES = 1;

    parameter int L3_HEADER_SIZE_BYTES = L3_SRC_SAT_SIZE_BYTES + L3_DEST_SAT_SIZE_BYTES
                                 + L3_TTL_SIZE_BYTES + L3_PAYLOAD_LENGTH_SIZE_BYTES
                                 + L3_RESERVED_LENGTH_SIZE_BYTES;
    parameter int L3_PAYLOAD_MAX_SIZE_BYTES = 1500; // Standard MTU
    parameter int L3_MAX_SIZE_BYTES         = L3_PAYLOAD_MAX_SIZE_BYTES + L3_HEADER_SIZE_BYTES;

    // Bit offsets (L3)
    parameter int L3_SRC_SAT_LSB        = 0;
    parameter int L3_SRC_SAT_MSB        = L3_SRC_SAT_LSB + (8*L3_SRC_SAT_SIZE_BYTES) - 1;

    parameter int L3_DEST_SAT_LSB       = L3_SRC_SAT_MSB + 1;
    parameter int L3_DEST_SAT_MSB       = L3_DEST_SAT_LSB + (8*L3_DEST_SAT_SIZE_BYTES) - 1;

    parameter int L3_TTL_LSB            = L3_DEST_SAT_MSB + 1;
    parameter int L3_TTL_MSB            = L3_TTL_LSB + (8*L3_TTL_SIZE_BYTES) - 1 ;

    parameter int L3_PAYLOAD_LENGTH_LSB = L3_TTL_MSB + 1;
    parameter int L3_PAYLOAD_LENGTH_MSB = L3_PAYLOAD_LENGTH_LSB + (8*L3_PAYLOAD_LENGTH_SIZE_BYTES) - 1;

    parameter int L3_PAYLOAD_LSB        = L3_PAYLOAD_LENGTH_MSB+1;


    // ============================================================
    // L3 DESCRIPTOR DEFINITIONS
    // ============================================================
    parameter int RX_L3_BUFFER_DEPTH_BYTES = 16384;
    parameter int RX_L3_DESC_BUFFER_DEPTH = 64; // PACKETS
    // [Start_Ptr, Desc_id, L3PacketLength, DestSat(7:0)
    typedef struct packed {
        logic [$clog2(RX_L3_BUFFER_DEPTH_BYTES)-1:0] start_ptr;
        logic [$clog2(L3_MAX_SIZE_BYTES+1)-1:0] length;
        logic [(8*L3_DEST_SAT_SIZE_BYTES)-1:0] dest_sat;
        logic [$clog2(RX_L3_DESC_BUFFER_DEPTH)-1:0] desc_id;
        logic [$clog2(NUM_LINKS)-1:0] buffer_id;
    } l3_packet_descriptor_t;

    // ============================================================
    // L2 DEFINITIONS
    // ============================================================
    // [CRC32(2111:2080), L3_Packet(2079:32), Length(31:16),Type(15:12), Flags(11:8), SOF(7:0)]
    parameter int L2_SOF_SIZE_BYTES            = 1;
    parameter int L2_TYPE_FLAGS_SIZE_BYTES     = 1;
    parameter int L2_PAYLOAD_LENGTH_SIZE_BYTES = 2;
    parameter int L2_CRC_SIZE_BYTES            = 4;

    parameter int L2_HEADER_SIZE_BYTES = L2_SOF_SIZE_BYTES + L2_TYPE_FLAGS_SIZE_BYTES + L2_PAYLOAD_LENGTH_SIZE_BYTES + L2_CRC_SIZE_BYTES;
    parameter int L2_MAX_SIZE_BYTES            = L3_MAX_SIZE_BYTES + L2_HEADER_SIZE_BYTES;

    // Bit offsets (L2)
    parameter int L2_SOF_LSB = 0;
    parameter int L2_SOF_MSB = L2_SOF_LSB + (8*L2_SOF_SIZE_BYTES) - 1;

    parameter logic [7:0]  L2_SOF_VAL = 8'hAB;

    parameter int L2_FLAGS_LSB = L2_SOF_MSB + 1;
    parameter int L2_FLAGS_MSB = L2_FLAGS_LSB + (4*L2_TYPE_FLAGS_SIZE_BYTES) - 1;

    parameter int L2_TYPE_LSB = L2_FLAGS_MSB + 1;
    parameter int L2_TYPE_MSB = L2_TYPE_LSB + (4*L2_TYPE_FLAGS_SIZE_BYTES) - 1;

    parameter int L2_PAYLOAD_LENGTH_LSB = L2_TYPE_MSB+1;
    parameter int L2_PAYLOAD_LENGTH_MSB = L2_PAYLOAD_LENGTH_LSB + (8 * L2_PAYLOAD_LENGTH_SIZE_BYTES) - 1;

    parameter int L2_L3_PACKET_LSB = L2_PAYLOAD_LENGTH_MSB+1;

endpackage
