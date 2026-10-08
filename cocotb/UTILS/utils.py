from cocotb.triggers import RisingEdge

from CONSTANTS.constants import (
    L2_PAYLOAD_LENGTH_SIZE_BYTES,
    L3_DEST_SAT_SIZE_BYTES,
    L3_HEADER_SIZE_BYTES,
    L3_LENGTH_W,
    L3_SRC_SAT_SIZE_BYTES,
    L3_TTL_SIZE_BYTES,
    RX_L3_BUFFER_PTR_W,
    RX_L3_DESC_ID_W,
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


# must match l3_packet_descriptor_t's declaration order (MSB first)
DESC_FIELDS = [
    ("start_ptr", RX_L3_BUFFER_PTR_W),
    ("desc_id", RX_L3_DESC_ID_W),
    ("length", L3_LENGTH_W),
    ("dest_sat", 8 * L3_DEST_SAT_SIZE_BYTES),
]
DESC_WIDTH = sum(w for _, w in DESC_FIELDS)


def pack_desc(**fields):
    """Build the packed descriptor int. Unspecified fields default to 0."""
    value = 0
    for name, width in DESC_FIELDS:
        v = fields.get(name, 0)
        assert 0 <= v < (1 << width), f"{name}={v} doesn't fit in {width} bits"
        value = (value << width) | v
    unknown = set(fields) - {n for n, _ in DESC_FIELDS}
    assert not unknown, f"unknown descriptor fields: {unknown}"
    return value


def desc_hex(**fields):
    return f"0x{pack_desc(**fields):0{(DESC_WIDTH + 3) // 4}X}"
