#include "gtest/gtest.h"
#include "MathOnStrings/Add.hpp"

using namespace testing;
using namespace MathOnStrings;
using namespace MathOnStrings::details;

TEST(Math_Add_test, simpleAdd_sanityCheck_unequalLengthArguments_throws)
{
    EXPECT_THROW(simpleAdd("", "0"), std::logic_error);
    EXPECT_THROW(simpleAdd("0", ""), std::logic_error);
    EXPECT_THROW(simpleAdd("000", "00"), std::logic_error);
    EXPECT_THROW(simpleAdd("00", "000"), std::logic_error);
    EXPECT_THROW(simpleAdd("00", "00000000000000"), std::logic_error);
    EXPECT_THROW(simpleAdd("00000000000000", "00"), std::logic_error);
}

TEST(Math_Add_U10_test, simpleAdd_zero)
{
    EXPECT_EQ("", simpleAdd("", ""));
    EXPECT_EQ("0", simpleAdd("0", "0"));
    EXPECT_EQ("00", simpleAdd("00", "00"));
    EXPECT_EQ("000", simpleAdd("000", "000"));
}

TEST(Math_Add_U10_test, simpleAdd_numbers_noCarry_noOverflow)
{
    EXPECT_EQ("5", simpleAdd("2", "3"));
    EXPECT_EQ("5", simpleAdd("3", "2"));
    EXPECT_EQ("369", simpleAdd("148", "221"));
}

TEST(Math_Add_U10_test, simpleAdd_numbers_withCarry_noOverflow)
{
    EXPECT_EQ("30", simpleAdd("17", "13"));
    EXPECT_EQ("30", simpleAdd("13", "17"));
    EXPECT_EQ("371", simpleAdd("148", "223"));
}

TEST(Math_Add_U10_test, simpleAdd_numbers_withCarry_withOverflow)
{
    EXPECT_EQ("100", simpleAdd("17", "83"));
    EXPECT_EQ("100", simpleAdd("83", "17"));
    EXPECT_EQ("1001", simpleAdd("148", "853"));
}

TEST(Math_Add_U10_test, add_zeros)
{
    EXPECT_EQ("0", add("0", "0"));
    EXPECT_EQ("0", add("0", "+0"));
    EXPECT_EQ("0", add("+0", "0"));
    EXPECT_EQ("0", add("0", "-0"));
    EXPECT_EQ("0", add("-0", "0"));
    EXPECT_EQ("0", add("+0", "-0"));
    EXPECT_EQ("0", add("-0", "+0"));
    EXPECT_EQ("0", add("+0", "+0"));
    EXPECT_EQ("0", add("-0", "-0"));
}

TEST(Math_Add_U10_test, add_twoSmallPositives_noCarry_noOverflow)
{
    EXPECT_EQ("25", add("12", "13"));
    EXPECT_EQ("25", add("13", "12"));
    EXPECT_EQ("149", add("148", "1"));
}

TEST(Math_Add_U10_test, add_twoSmallPositives_withCarry_noOverflow)
{
    EXPECT_EQ("31", add("18", "13"));
    EXPECT_EQ("31", add("13", "18"));
    EXPECT_EQ("156", add("148", "8"));
}

TEST(Math_Add_U10_test, add_twoSmallPositives_withCarry_withOverflow)
{
    EXPECT_EQ("131", add("58", "73"));
    EXPECT_EQ("131", add("73", "58"));
    EXPECT_EQ("1156", add("348", "808"));
}

TEST(Math_Add_U10_test, add_SmallAndBigPositives_withCarry_noOverflow)
{
    EXPECT_EQ("10131", add("10058", "73"));
    EXPECT_EQ("10131", add("73", "10058"));
    EXPECT_EQ("101156", add("100348", "808"));
}

TEST(Math_Add_U10_test, add_twoSmallNegatives_noCarry_noOverflow)
{
    EXPECT_EQ("-25", add("-12", "-13"));
    EXPECT_EQ("-25", add("-13", "-12"));
    EXPECT_EQ("-149", add("-148", "-1"));
}

TEST(Math_Add_U10_test, add_twoSmallNegatives_withCarry_noOverflow)
{
    EXPECT_EQ("-31", add("-18", "-13"));
    EXPECT_EQ("-31", add("-13", "-18"));
    EXPECT_EQ("-156", add("-148", "-8"));
}

TEST(Math_Add_U10_test, add_twoSmallNegatives_withCarry_withOverflow)
{
    EXPECT_EQ("-131", add("-58", "-73"));
    EXPECT_EQ("-131", add("-73", "-58"));
    EXPECT_EQ("-1156", add("-348", "-808"));
}

TEST(Math_Add_U10_test, add_SmallAndBigNegatives_withCarry_noOverflow)
{
    EXPECT_EQ("-10131", add("-10058", "-73"));
    EXPECT_EQ("-10131", add("-73", "-10058"));
    EXPECT_EQ("-101156", add("-100348", "-808"));
}

TEST(Math_Add_U10_test, add_smallPositive_smallNegative)
{
    EXPECT_EQ("-15", add("58", "-73"));
    EXPECT_EQ("-15", add("-73", "58"));
    EXPECT_EQ("460", add("-348", "808"));
}

TEST(Math_Add_U10_test, add_bigPositive_smallNegative)
{
    EXPECT_EQ("123333", add("123345", "-12"));
    EXPECT_EQ("923333", add("923345", "-12"));
}

TEST(Math_Add_U10_test, add_smallPositive_bigNegative)
{
    EXPECT_EQ("-123333", add("12", "-123345"));
    EXPECT_EQ("-923333", add("12", "-923345"));
}
