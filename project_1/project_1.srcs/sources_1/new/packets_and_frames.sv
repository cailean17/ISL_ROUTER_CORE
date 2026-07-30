package packets_and_frames;

    // ============================================================
    // L3 DEFINITIONS
    // ============================================================

    parameter int L3_MAX_SIZE_BYTES            = 256;
    parameter int L3_SRC_SAT_SIZE_BYTES        = 1;
    parameter int L3_DEST_SAT_SIZE_BYTES       = 1;
    parameter int L3_TTL_SIZE_BYTES            = 1;
    parameter int L3_PAYLOAD_LENGTH_SIZE_BYTES = 2; // UNIT: BYTES
    parameter int L3_RESERVED_LENGTH_SIZE_BYTES= 1;

    parameter int L3_SIZE_BYTES_WITHOUT_PAYLOAD = 6;
    parameter int L3_PAYLOAD_MAX_SIZE_BYTES     = 250;

    // Bit offsets (L3)
    parameter int L3_SRC_SAT_LSB        = 0;
    parameter int L3_SRC_SAT_MSB        = 7;

    parameter int L3_DEST_SAT_LSB       = 8;
    parameter int L3_DEST_SAT_MSB       = 15;

    parameter int L3_TTL_LSB            = 16;
    parameter int L3_TTL_MSB            = 23;

    parameter int L3_PAYLOAD_LENGTH_LSB = 24;
    parameter int L3_PAYLOAD_LENGTH_MSB = 39;

    parameter int L3_PAYLOAD_LSB        = 40;


    // ============================================================
    // L2 DEFINITIONS
    // ============================================================

    parameter int L2_MAX_SIZE_BYTES             = 264;
    parameter int L2_SOF_SIZE_BYTES            = 1;
    parameter int L2_TYPE_FLAGS_SIZE_BYTES     = 1;
    parameter int L2_PAYLOAD_LENGTH_SIZE_BYTES = 2;
    parameter int L2_CRC_SIZE_BYTES            = 4;

    // Bit offsets (L2)
    parameter int L2_SOF_LSB = 0;
    parameter int L2_SOF_MSB = 7;

    parameter logic [7:0]  L2_SOF_VAL = 8'hAB;

    parameter int L2_FLAGS_LSB = 8;
    parameter int L2_FLAGS_MSB = 11;

    parameter int L2_TYPE_LSB = 12;
    parameter int L2_TYPE_MSB = 15;

    parameter int L2_PAYLOAD_LENGTH_LSB = 16;
    parameter int L2_PAYLOAD_LENGTH_MSB = 31;

    parameter int L2_L3_PACKET_LSB = 32;

endpackage