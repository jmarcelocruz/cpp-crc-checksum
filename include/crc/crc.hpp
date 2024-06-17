#ifndef CRC_HPP
#define CRC_HPP

#include <cstdint>

namespace Crc {
    class Crc8 {
        private:
            std::uint8_t final_xor;
            std::uint8_t initial_value;
            std::uint8_t polynomial;
            bool reflect_input;
            bool reflect_output;

            std::uint8_t reverse_byte(std::uint8_t b) const;
        public:
            Crc8(std::uint8_t polynomial, std::uint8_t initial_value, std::uint8_t final_xor);
            Crc8(std::uint8_t polynomial, std::uint8_t initial_value, std::uint8_t final_xor,
                    bool reflect_input, bool reflect_output);
            ~Crc8();
            std::uint8_t operator()(const std::uint8_t* first, const std::uint8_t* last) const;
    };
}

#endif
