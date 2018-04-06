#include "gtest/gtest.h"
#include "MathOnStrings/Mult.hpp"

using namespace testing;
using namespace MathOnStrings;
using namespace MathOnStrings::details;

TEST(Math_Mult_test, mulByOneDigit_byZero)
{
    EXPECT_EQ("0", mulByOneDigit("", "0"));
    EXPECT_EQ("0", mulByOneDigit("0", "0"));
    EXPECT_EQ("0", mulByOneDigit("1", "0"));
    EXPECT_EQ("0", mulByOneDigit("123", "0"));
}

TEST(Math_Mult_test, mulByOneDigit_byOne)
{
    EXPECT_EQ("", mulByOneDigit("", "1"));
    EXPECT_EQ("0", mulByOneDigit("0", "1"));
    EXPECT_EQ("1", mulByOneDigit("1", "1"));
    EXPECT_EQ("123", mulByOneDigit("123", "1"));
}

TEST(Math_Mult_test, mulByOneDigit_byMore)
{
    EXPECT_EQ("0", mulByOneDigit("", "2"));
    EXPECT_EQ("00", mulByOneDigit("0", "3"));
    EXPECT_EQ("04", mulByOneDigit("1", "4"));
    EXPECT_EQ("0615", mulByOneDigit("123", "5"));
}

TEST(Math_Mult_test, mult_byZero)
{
    EXPECT_EQ("0", mult("", "0"));
    EXPECT_EQ("0", mult("0", "0"));
    EXPECT_EQ("0", mult("1", "0"));
    EXPECT_EQ("0", mult("123", "0"));
}

TEST(Math_Mult_test, mult_byOne)
{
    EXPECT_EQ("0", mult("", "1"));
    EXPECT_EQ("0", mult("0", "1"));
    EXPECT_EQ("1", mult("1", "1"));
    EXPECT_EQ("123", mult("123", "1"));
}

TEST(Math_Mult_test, mult_byNegativeOne)
{
    EXPECT_EQ("0", mult("", "-1"));
    EXPECT_EQ("0", mult("0", "-1"));
    EXPECT_EQ("-1", mult("1", "-1"));
    EXPECT_EQ("-123", mult("123", "-1"));
}

TEST(Math_Mult_test, mult_byMore)
{
    EXPECT_EQ("0", mult("", "2"));
    EXPECT_EQ("0", mult("0", "3"));
    EXPECT_EQ("4", mult("1", "4"));
    EXPECT_EQ("615", mult("123", "5"));
    EXPECT_EQ("1476", mult("123", "12"));
    EXPECT_EQ("1476", mult("00000123", "000012"));
    EXPECT_EQ("1479107432518560", mult("123023056", "12023010"));
    EXPECT_EQ("-1479107432518560", mult("123023056", "-12023010"));
    EXPECT_EQ("-1479107432518560", mult("-123023056", "12023010"));
    EXPECT_EQ("1479107432518560", mult("-123023056", "-12023010"));
}
