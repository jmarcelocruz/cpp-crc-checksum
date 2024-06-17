#include <crc/crc.hpp>

Crc::Crc8::Crc8(std::uint8_t polynomial, std::uint8_t initial_value, std::uint8_t final_xor):
    Crc8(polynomial, initial_value, final_xor, false) {}

Crc::Crc8::Crc8(std::uint8_t polynomial, std::uint8_t initial_value, std::uint8_t final_xor,
        bool reflect_input):
        polynomial {polynomial},
        initial_value {initial_value},
        final_xor {final_xor},
        reflect_input {reflect_input} {}

Crc::Crc8::~Crc8() {};

std::uint8_t Crc::Crc8::operator()(const std::uint8_t* first, const std::uint8_t* last) const {
    std::uint8_t crc = initial_value;

    for (; first != last; first++) {
        std::uint8_t b = (reflect_input) ? reverse_byte(*first) : *first;
        crc ^= b;
        for (int i = 0; i < 8; i++) {
            crc = ((crc & 0x80) ? polynomial : 0) ^ (crc << 1);
        }
    }

    return crc ^ final_xor;
}

std::uint8_t Crc::Crc8::reverse_byte(std::uint8_t b) const {
    std::uint8_t reversed = 0;
    for (int i = 0; i < 7; i++) {
        reversed = (reversed | (b & 1)) << 1;
        b >>= 1;
    }

    reversed = (reversed | (b & 1));

    return reversed;
}
