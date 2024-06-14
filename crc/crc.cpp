#include <crc/crc.hpp>

Crc::Crc8::Crc8(std::uint8_t polynomial): polynomial {polynomial} {}

Crc::Crc8::~Crc8() {};

std::uint8_t Crc::Crc8::operator()(const std::uint8_t* first, const std::uint8_t* last) const {
    std::uint8_t crc = 0;

    for (; first != last; first++) {
        crc ^= *first;
        for (int i = 0; i < 8; i++) {
            crc = ((crc & 0x80) ? polynomial : 0) ^ (crc << 1);
        }
    }

    return crc;
}
