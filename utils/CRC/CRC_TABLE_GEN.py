def gen_crc_table():
    poly = 0xEDB88320
    table = []
    for i in range(256):
        crc = i # possible 8 bit value
        for b in range(8):
            # shift through all 8 bits of table key 
            if crc & 1:
                # if LSB is 1, then XOR and shift
                crc = (crc >> 1) ^ poly 
            else:
                crc >>= 1
        table.append(crc)
    return table

if __name__ == "__main__":
    tab = gen_crc_table()
    with open("CRC_TABLE.mem","w") as file: 
        for val in tab: 
            file.write(f"{val:08x}\n")