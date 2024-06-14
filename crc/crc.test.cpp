#include <gtest/gtest.h>
#include <crc/crc.hpp>

TEST(Crc8Suite, IsStable) {
    Crc::Crc8 crc8 {0x07};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[3]), crc8(&buf[0], &buf[3]));
}

TEST(Crc8Suite, ArbitraryLengthInputReturnsExpectedCrcValue) {
    Crc::Crc8 crc8 {0x07};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[0]), 0);
    EXPECT_EQ(crc8(&buf[0], &buf[1]), 0x9E);
    EXPECT_EQ(crc8(&buf[0], &buf[3]), 0x9D);
}
