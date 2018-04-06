#include "gtest/gtest.h"
#include "MathOnStrings/Utils.hpp"

using namespace testing;
using namespace MathOnStrings::Utils;
using namespace MathOnStrings::U10;

TEST(SupportFunctionsTest, sign)
{
    EXPECT_EQ("+", sign("0"));
    EXPECT_EQ("+", sign("+0"));
    EXPECT_EQ("-", sign("-0"));
    EXPECT_EQ("-", sign("-043232554"));
    EXPECT_EQ("+", sign("+043232554"));
}

TEST(SupportFunctionsTest, noSign)
{
    EXPECT_EQ("0", noSign("0"));
    EXPECT_EQ("0", noSign("+0"));
    EXPECT_EQ("0", noSign("-0"));
    EXPECT_EQ("043232554", noSign("-043232554"));
    EXPECT_EQ("043232554", noSign("+043232554"));
    EXPECT_EQ("123", noSign("123"));
    EXPECT_EQ("0123", noSign("0123"));
}

TEST(SupportFunctionsTest, stripFrontZeros)
{
    EXPECT_EQ("0", stripFrontZeros(""));
    EXPECT_EQ("10000", stripFrontZeros("10000"));
    EXPECT_EQ("0", stripFrontZeros("00"));
    EXPECT_EQ("0", stripFrontZeros("0000"));
    EXPECT_EQ("0", stripFrontZeros("00000"));
    EXPECT_EQ("23", stripFrontZeros("0023"));
}

TEST(SupportFunctionsTest, extendToLength)
{
    EXPECT_EQ("0000", extendToLength("", 4));
    EXPECT_EQ("0000", extendToLength("00", 4));
    EXPECT_EQ("0000", extendToLength("0000", 4));
    EXPECT_EQ("00000", extendToLength("00000", 4));
    EXPECT_EQ("0023", extendToLength("23", 4));
}

TEST(SupportFunctionsTest, normalizeNumber)
{
    EXPECT_EQ("+0", normalizeNumber("0"));
    EXPECT_EQ("+0", normalizeNumber("-0"));
    EXPECT_EQ("+0", normalizeNumber("+0"));
    EXPECT_EQ("+43232554", normalizeNumber("000043232554"));
    EXPECT_EQ("+43232554", normalizeNumber("+000043232554"));
    EXPECT_EQ("-43232554", normalizeNumber("-000043232554"));
    EXPECT_EQ("+43232554", normalizeNumber("43232554"));
    EXPECT_EQ("+43232554", normalizeNumber("+43232554"));
    EXPECT_EQ("-43232554", normalizeNumber("-43232554"));
}

TEST(SupportFunctionsTest, normalizeResult)
{
    EXPECT_EQ("0", normalizeResult("0"));
    EXPECT_EQ("0", normalizeResult("-0"));
    EXPECT_EQ("0", normalizeResult("+0"));
    EXPECT_EQ("43232554", normalizeResult("000043232554"));
    EXPECT_EQ("43232554", normalizeResult("+000043232554"));
    EXPECT_EQ("-43232554", normalizeResult("-000043232554"));
    EXPECT_EQ("43232554", normalizeResult("43232554"));
    EXPECT_EQ("43232554", normalizeResult("+43232554"));
    EXPECT_EQ("-43232554", normalizeResult("-43232554"));
}

TEST(SupportFunctionsTest, encodeSign)
{
    EXPECT_EQ("0", encodeSign("+"));
    EXPECT_EQ("1", encodeSign("-"));
}

TEST(SupportFunctionsTest, encodeDigits)
{
    EXPECT_EQ("9", encodeDigits("1"));
    EXPECT_EQ("877", encodeDigits("123"));
    EXPECT_EQ("9987700", encodeDigits("0012300"));
}

TEST(SupportFunctionsTest, encodeU10_zero)
{
    EXPECT_EQ("00", encodeU10("+0"));
}

TEST(SupportFunctionsTest, encodeU10_positive)
{
    EXPECT_EQ("01", encodeU10("1"));
    EXPECT_EQ("01", encodeU10("+1"));
    EXPECT_EQ("0123567345", encodeU10("123567345"));
    EXPECT_EQ("0123567345", encodeU10("+123567345"));
    EXPECT_EQ("0000012300", encodeU10("000012300"));
    EXPECT_EQ("0000012300", encodeU10("+000012300"));
}

TEST(SupportFunctionsTest, encodeU10_negative)
{
    EXPECT_EQ("19", encodeU10("-1"));
    EXPECT_EQ("11", encodeU10("-9"));
    EXPECT_EQ("1876432655", encodeU10("-123567345"));
    EXPECT_EQ("1999987700", encodeU10("-000012300"));
}

TEST(SupportFunctionsTest, decodeU10_zero)
{
    EXPECT_EQ("00", decodeU10("00"));
}

TEST(SupportFunctionsTest, decodeU10_positive)
{
    EXPECT_EQ("01", decodeU10("01"));
    EXPECT_EQ("0123567345", decodeU10("0123567345"));
    EXPECT_EQ("0000012300", decodeU10("0000012300"));
}

TEST(SupportFunctionsTest, decodeU10_negative)
{
    EXPECT_EQ("-1", decodeU10("19"));
    EXPECT_EQ("-9", decodeU10("11"));
    EXPECT_EQ("-123567345", decodeU10("1876432655"));
    EXPECT_EQ("-000012300", decodeU10("1999987700"));
}
