#include <gtest/gtest.h>
#include <crc/crc.hpp>

TEST(Crc8Suite, IsStable) {
    Crc::Crc8 crc8 {0x07, 0};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[3]), crc8(&buf[0], &buf[3]));
}

TEST(Crc8Suite, ZeroLengthInputReturnsInitialValue) {
    Crc::Crc8 crc8_0 {0x07, 0};
    Crc::Crc8 crc8_1c {0x07, 0x1C};
    Crc::Crc8 crc8_ff {0x07, 0xFF};
    std::uint8_t buf[] {};

    EXPECT_EQ(crc8_0(&buf[0], &buf[0]), 0);
    EXPECT_EQ(crc8_1c(&buf[0], &buf[0]), 0x1C);
    EXPECT_EQ(crc8_ff(&buf[0], &buf[0]), 0xFF);
}

TEST(Crc8Suite, ArbitraryLengthInputReturnsExpectedCrcValue) {
    Crc::Crc8 crc8 {0x07, 0};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[1]), 0x9E);
    EXPECT_EQ(crc8(&buf[0], &buf[3]), 0x9D);
}
