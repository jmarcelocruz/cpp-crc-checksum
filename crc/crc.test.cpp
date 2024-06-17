#include <gtest/gtest.h>
#include <crc/crc.hpp>

TEST(Crc8Suite, IsStable) {
    Crc::Crc8 crc8 {0x07, 0, 0};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[3]), crc8(&buf[0], &buf[3]));
}

TEST(Crc8Suite, ZeroLengthInputReturnsXoredInitialValue) {
        Crc::Crc8 crc8_0 {0x07, 0, 0};
    Crc::Crc8 crc8_1c {0x07, 0x1C, 0};
    Crc::Crc8 crc8_ff {0x07, 0xFF, 0};
    Crc::Crc8 crc8_1c_1c {0x07, 0x1C, 0x1C};
    std::uint8_t buf[] {};

    EXPECT_EQ(crc8_0(&buf[0], &buf[0]), 0);
    EXPECT_EQ(crc8_1c(&buf[0], &buf[0]), 0x1C);
    EXPECT_EQ(crc8_ff(&buf[0], &buf[0]), 0xFF);
    EXPECT_EQ(crc8_1c_1c(&buf[0], &buf[0]), 0x1C ^ 0x1C);
}

TEST(Crc8Suite, ArbitraryLengthInputReturnsExpectedCrcValue) {
    Crc::Crc8 crc8 {0x07, 0, 0};
    Crc::Crc8 crc8_1c {0x07, 0, 0x1C};
    std::uint8_t buf[] {0x32, 0x23, 0x64};

    EXPECT_EQ(crc8(&buf[0], &buf[1]), 0x9E);
    EXPECT_EQ(crc8_1c(&buf[0], &buf[1]), 0x9E ^ 0x1C);
    EXPECT_EQ(crc8(&buf[0], &buf[3]), 0x9D);
    EXPECT_EQ(crc8_1c(&buf[0], &buf[3]), 0x9D ^ 0x1C);
}

TEST(Crc8Suite, ValueWhenInputReflectionIsEnabledEqualsValueForReflectedInput) {
    Crc::Crc8 crc8 {0x07, 0, 0};
    Crc::Crc8 crc8_reflected {0x07, 0, 0, true};
    std::uint8_t buf[] {0x32, 0x23, 0x64};
    std::uint8_t buf_reflected[] {0x4C, 0xC4, 0x26};

    EXPECT_EQ(crc8_reflected(&buf[0], &buf[0]), crc8(&buf_reflected[0], &buf_reflected[0]));
    EXPECT_EQ(crc8_reflected(&buf[0], &buf[1]), crc8(&buf_reflected[0], &buf_reflected[1]));
    EXPECT_EQ(crc8_reflected(&buf[0], &buf[3]), crc8(&buf_reflected[0], &buf_reflected[3]));
}
