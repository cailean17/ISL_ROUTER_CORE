// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_PACKETS_AND_FRAMES_H_
#define VERILATED_VTOP_PACKETS_AND_FRAMES_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_packets_and_frames final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*7:0*/ L2_SOF_VAL = 0xabU;
    static constexpr IData/*31:0*/ L3_MAX_SIZE_BYTES = 0x00000100U;
    static constexpr IData/*31:0*/ L3_SRC_SAT_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L3_DEST_SAT_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L3_TTL_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L3_PAYLOAD_LENGTH_SIZE_BYTES = 2U;
    static constexpr IData/*31:0*/ L3_RESERVED_LENGTH_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L3_HEADER_SIZE_BYTES = 6U;
    static constexpr IData/*31:0*/ L3_PAYLOAD_MAX_SIZE_BYTES = 0x000000faU;
    static constexpr IData/*31:0*/ L3_SRC_SAT_LSB = 0U;
    static constexpr IData/*31:0*/ L3_SRC_SAT_MSB = 7U;
    static constexpr IData/*31:0*/ L3_DEST_SAT_LSB = 8U;
    static constexpr IData/*31:0*/ L3_DEST_SAT_MSB = 0x0000000fU;
    static constexpr IData/*31:0*/ L3_TTL_LSB = 0x00000010U;
    static constexpr IData/*31:0*/ L3_TTL_MSB = 0x00000017U;
    static constexpr IData/*31:0*/ L3_PAYLOAD_LENGTH_LSB = 0x00000018U;
    static constexpr IData/*31:0*/ L3_PAYLOAD_LENGTH_MSB = 0x00000027U;
    static constexpr IData/*31:0*/ L3_PAYLOAD_LSB = 0x00000028U;
    static constexpr IData/*31:0*/ L2_MAX_SIZE_BYTES = 0x00000108U;
    static constexpr IData/*31:0*/ L2_SOF_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L2_TYPE_FLAGS_SIZE_BYTES = 1U;
    static constexpr IData/*31:0*/ L2_PAYLOAD_LENGTH_SIZE_BYTES = 2U;
    static constexpr IData/*31:0*/ L2_CRC_SIZE_BYTES = 4U;
    static constexpr IData/*31:0*/ L2_SOF_LSB = 0U;
    static constexpr IData/*31:0*/ L2_SOF_MSB = 7U;
    static constexpr IData/*31:0*/ L2_FLAGS_LSB = 8U;
    static constexpr IData/*31:0*/ L2_FLAGS_MSB = 0x0000000bU;
    static constexpr IData/*31:0*/ L2_TYPE_LSB = 0x0000000cU;
    static constexpr IData/*31:0*/ L2_TYPE_MSB = 0x0000000fU;
    static constexpr IData/*31:0*/ L2_PAYLOAD_LENGTH_LSB = 0x00000010U;
    static constexpr IData/*31:0*/ L2_PAYLOAD_LENGTH_MSB = 0x0000001fU;
    static constexpr IData/*31:0*/ L2_L3_PACKET_LSB = 0x00000020U;

    // CONSTRUCTORS
    Vtop_packets_and_frames();
    ~Vtop_packets_and_frames();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_packets_and_frames);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
