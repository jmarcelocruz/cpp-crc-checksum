#ifndef CRC_HPP
#define CRC_HPP

#include <cstdint>

namespace Crc {
    class Crc8 {
        private:
            std::uint8_t polynomial;
        public:
            Crc8(std::uint8_t polynomial);
            ~Crc8();
            std::uint8_t operator()(const std::uint8_t* first, const std::uint8_t* last) const;
    };
}

#endif
