import random
import zlib

from cocotb.triggers import RisingEdge

from CONSTANTS.constants import (
    L2_CRC_SIZE_BYTES,
    L2_PAYLOAD_LENGTH_SIZE_BYTES,
    L2_SOF_VAL,
    L2_TYPE_FLAGS_SIZE_BYTES,
    L3_DEST_SAT_SIZE_BYTES,
    L3_HEADER_SIZE_BYTES,
    L3_LENGTH_W,
    L3_PAYLOAD_MAX_SIZE_BYTES,
    L3_SRC_SAT_SIZE_BYTES,
    L3_TTL_SIZE_BYTES,
    NUM_LINKS,
    RX_L3_BUFFER_PTR_W,
    RX_L3_DESC_ID_W,
    clog2,
)


# Custom json.dumps encode
def obj_encoder(obj):
    if hasattr(obj, "__dict__"):
        return obj.__dict__
    return str(obj)


async def wait_cycles(clk, n):
    for _ in range(n):
        await RisingEdge(clk)


def assert_with_message(name, actual, expected):
    assert actual == expected, (
        f"{name}: actual: {hex(actual)}, expected: {hex(expected)}"
    )


def generate_l3_packet(src_sat, dest_sat, ttl, payload_length, seed_byte=0x00):
    """**Description:** Generates a L3 packet with user specified arguments, generates paylod upto payload length, incrementing from seed_byte \n
    **Args:**\n
    src_sat (byte)\n
    dest_sat (byte)\n
    ttl (byte): defines max ISL hops before packet is dropped\n
    payload_length (number)\n
    seed_byte (byte): first payload byte, next payload bytes will increment from seed_byte\n
    **Returns:**\n
    A tuple: (l3_packet (list of bytes LSB first), packet_size_bytes)
    """
    l3_packet = [0] * (payload_length + L3_HEADER_SIZE_BYTES)
    running_offset = 0

    for i in range(L3_SRC_SAT_SIZE_BYTES):
        l3_packet[running_offset + i] = src_sat & 0xFF
        src_sat >>= 8
    running_offset += L3_SRC_SAT_SIZE_BYTES

    for i in range(L3_DEST_SAT_SIZE_BYTES):
        l3_packet[running_offset + i] = dest_sat & 0xFF
        dest_sat >>= 8
    running_offset += L3_DEST_SAT_SIZE_BYTES

    for i in range(L3_TTL_SIZE_BYTES):
        l3_packet[running_offset + i] = ttl & 0xFF
        ttl >>= 8
    running_offset += L3_TTL_SIZE_BYTES

    payload_length_cp = payload_length
    for i in range(L2_PAYLOAD_LENGTH_SIZE_BYTES):
        l3_packet[running_offset + i] = payload_length_cp & 0xFF
        payload_length_cp >>= 8
    running_offset += L2_PAYLOAD_LENGTH_SIZE_BYTES

    for i in range(payload_length):
        l3_packet[running_offset + i] = (seed_byte + i) & 0xFF

    return l3_packet, len(l3_packet) & 0xFFFF


def generate_l2_frame(l3_packet):
    l2_frame = []

    # Append SOF
    l2_frame.append(L2_SOF_VAL)

    # Append EMPTY FLAGS
    for i in range(0, L2_TYPE_FLAGS_SIZE_BYTES):
        l2_frame.append(0x00)

    # Append L3 Packet Size
    l2_frame = l2_frame + list(
        len(l3_packet).to_bytes(L2_PAYLOAD_LENGTH_SIZE_BYTES, byteorder="little")
    )

    # Append L3 Packet
    l2_frame += l3_packet

    #  (DUT excludes SOF byte from CRC calculation)
    expected_crc = zlib.crc32(bytes(l2_frame[1:])).to_bytes(L2_CRC_SIZE_BYTES, "little")

    # Append CRC
    l2_frame = l2_frame + list(expected_crc)

    return l2_frame


PACKET_DESC_FIELDS = [
    ("start_ptr", RX_L3_BUFFER_PTR_W),
    ("length", L3_LENGTH_W),
    ("dest_sat", 8 * L3_DEST_SAT_SIZE_BYTES),
    ("desc_id", RX_L3_DESC_ID_W),
    ("buffer_id", clog2(NUM_LINKS)),
]
PACKET_DESC_WIDTH = sum(w for _, w in PACKET_DESC_FIELDS)


def pack_desc(**fields):
    """Build the packet descriptor int. Unspecified fields default to constrained random generation"""
    value = 0
    for name, width in PACKET_DESC_FIELDS:
        v = fields.get(name, random.randint(0, (1 << width) - 1))
        assert 0 <= v < (1 << width), f"{name}={v} doesn't fit in {width} bits"
        value = (value << width) | v
    unknown = set(fields) - {n for n, _ in PACKET_DESC_FIELDS}
    assert not unknown, f"unknown descriptor fields: {unknown}"
    return value


def unpack_desc(value):
    """Inverse of pack_desc: packed descriptor int -> {field: int}."""
    value = int(value)  # accepts an int or a cocotb signal value
    fields = {}
    shift = sum(width for _, width in PACKET_DESC_FIELDS)
    for name, width in PACKET_DESC_FIELDS:  # same MSB-first order pack_desc uses
        shift -= width
        fields[name] = (value >> shift) & ((1 << width) - 1)
    return fields


def generate_l3_packet_and_desc_pair(l3_packet_payload_length=None, src_sat=None, dest_sat= None):
    """Unspecified fields default to constrained random generation"""
    l3_packet_payload_length = (
        l3_packet_payload_length
        if l3_packet_payload_length is not None
        else random.randint(1, L3_PAYLOAD_MAX_SIZE_BYTES)
    )
    l3_packet_desc = None
    if l3_packet_payload_length and dest_sat:
        l3_packet_desc = pack_desc(length=l3_packet_payload_length + L3_HEADER_SIZE_BYTES, dest_sat=dest_sat)
    elif l3_packet_payload_length:
        l3_packet_desc = pack_desc(length=l3_packet_payload_length + L3_HEADER_SIZE_BYTES)
    elif dest_sat:
        l3_packet_desc = pack_desc(dest_sat=dest_sat)
    else:
        l3_packet_desc = pack_desc()

    l3_packet, l3_packet_size = generate_l3_packet(
        src_sat=src_sat
        if src_sat
        else random.randint(0, 1 << (L3_SRC_SAT_SIZE_BYTES * 8) - 1),
        dest_sat=unpack_desc(l3_packet_desc)["dest_sat"],
        ttl=random.randint(0, 1 << (L3_TTL_SIZE_BYTES * 8) - 1),
        payload_length=l3_packet_payload_length,
        seed_byte=random.randint(0, 0xFF),
    )
    return l3_packet_desc, l3_packet


def desc_hex(**fields):
    return f"0x{pack_desc(**fields):0{(PACKET_DESC_WIDTH + 3) // 4}X}"
