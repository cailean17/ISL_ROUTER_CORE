import random

def crc(m, poly = 0xEDB88320):
    crc = m ^ 0xFFFFFFFF
    for i in range(0, 32):
        # shift through all 8 bits of table key 
        if crc & 1:
            # if LSB is 1, then XOR and shift
            crc = (crc >> 1) ^ poly 
        else:
            crc >>= 1
    return crc ^ 0xFFFFFFFF


def test_vector(n = 100):
    test_vector = []
    result_vector = []
    for i in range(n):
        test = random.randint(0, 0xFFFFFFFF)
        correct = crc(test)
        test_vector.append(test)
        result_vector.append(correct)
    with open ("CRC_TEST_VECTOR.mem", "w") as file: 
        for val in test_vector: 
            file.write(f"{val:08x}\n")
    with open ("CRC_RESULT_VECTOR.mem", "w") as file: 
        for val in result_vector: 
            file.write(f"{val:08x}\n")

if __name__ == "__main__":
    test_vector(100)