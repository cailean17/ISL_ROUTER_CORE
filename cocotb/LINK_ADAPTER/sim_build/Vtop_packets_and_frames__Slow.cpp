// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_packets_and_frames
constexpr CData/*7:0*/ Vtop_packets_and_frames::L2_SOF_VAL;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_MAX_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_SRC_SAT_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_DEST_SAT_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_TTL_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_PAYLOAD_LENGTH_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_RESERVED_LENGTH_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_HEADER_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_PAYLOAD_MAX_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_SRC_SAT_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_SRC_SAT_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_DEST_SAT_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_DEST_SAT_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_TTL_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_TTL_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_PAYLOAD_LENGTH_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_PAYLOAD_LENGTH_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L3_PAYLOAD_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_MAX_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_SOF_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_TYPE_FLAGS_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_PAYLOAD_LENGTH_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_CRC_SIZE_BYTES;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_SOF_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_SOF_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_FLAGS_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_FLAGS_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_TYPE_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_TYPE_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_PAYLOAD_LENGTH_LSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_PAYLOAD_LENGTH_MSB;
constexpr IData/*31:0*/ Vtop_packets_and_frames::L2_L3_PACKET_LSB;



Vtop_packets_and_frames::Vtop_packets_and_frames() = default;
Vtop_packets_and_frames::~Vtop_packets_and_frames() = default;

void Vtop_packets_and_frames::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_packets_and_frames___configure_coverage(Vtop_packets_and_frames* vlSelf, bool first);

void Vtop_packets_and_frames::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop_packets_and_frames___configure_coverage(this, first);
}

void Vtop_packets_and_frames::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop_packets_and_frames::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
    const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    std::string fullhier = std::string{vlNamep} + hierp;
    if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
    if (!enable && !localCounter) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), vlNamep, count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",fullhier.c_str(),  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp,  (fsmVarp[0] ? "fsm_var" : ""), fsmVarp,  (fsmFromp[0] ? "fsm_from" : ""), fsmFromp,  (fsmTop[0] ? "fsm_to" : ""), fsmTop,  (fsmTagp[0] ? "fsm_tag" : ""), fsmTagp);
}

// Toggle Coverage
void Vtop_packets_and_frames::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    int step = (end >= begin) ? 1 : -1;
    for (int i = begin; i != end + step; i += step) {
        for (int j = 0; j < 2; j++) {
            uint32_t* count32p = countp;
            static uint32_t fake_zero_count = 0;
            std::string fullhier = std::string{vlNamep} + hierp;
            if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
            std::string commentWithIndex = commentp;
            if (ranged) commentWithIndex += '[' + std::to_string(i) + ']';
            commentWithIndex += j ? ":0->1" : ":1->0";
            if (!enable && !localCounter) count32p = &fake_zero_count;
            *count32p = 0;
            VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), vlNamep, count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
                "hier",fullhier.c_str(),  "page",pagep,  "comment",commentWithIndex.c_str(),  "", "");
            ++countp;
        }
    }
}
