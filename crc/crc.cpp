#include <crc/crc.hpp>

Crc::Crc8::Crc8(std::uint8_t polynomial, std::uint8_t initial_value, std::uint8_t final_xor):
        polynomial {polynomial}, initial_value {initial_value}, final_xor {final_xor} {}

Crc::Crc8::~Crc8() {};

std::uint8_t Crc::Crc8::operator()(const std::uint8_t* first, const std::uint8_t* last) const {
    std::uint8_t crc = initial_value;

    for (; first != last; first++) {
        crc ^= *first;
        for (int i = 0; i < 8; i++) {
            crc = ((crc & 0x80) ? polynomial : 0) ^ (crc << 1);
        }
    }

    return crc ^ final_xor;
}
