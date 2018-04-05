#include "gtest/gtest.h"
#include "MyMathOnStrings/Utils.hpp"

using namespace testing;
using namespace MyMathOnStrings::Utils;

TEST(SupportFunctionsTest, sign)
{
    EXPECT_EQ("+", sign("0"));
    EXPECT_EQ("+", sign("+0"));
    EXPECT_EQ("-", sign("-0"));
    EXPECT_EQ("-", sign("-043232554"));
    EXPECT_EQ("+", sign("+043232554"));
}

TEST(SupportFunctionsTest, abs)
{
    EXPECT_EQ("0", absVal("0"));
    EXPECT_EQ("0", absVal("+0"));
    EXPECT_EQ("0", absVal("-0"));
    EXPECT_EQ("043232554", absVal("-043232554"));
    EXPECT_EQ("043232554", absVal("+043232554"));
}

TEST(SupportFunctionsTest, removePrefixZeros)
{
    EXPECT_EQ("0", removePrefixZeros("0000"));
    EXPECT_EQ("0", removePrefixZeros("0"));
    EXPECT_EQ("43232554", removePrefixZeros("000043232554"));
    EXPECT_EQ("43232554", removePrefixZeros("43232554"));
}

TEST(SupportFunctionsTest, normalizeNumber)
{
    EXPECT_EQ("+0", normalizeNumber("0"));
    EXPECT_EQ("-0", normalizeNumber("-0"));
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

TEST(SupportFunctionsTest, at)
{
    EXPECT_EQ('6', at("123098456", 0));
    EXPECT_EQ('0', at("123098456", 5));
    EXPECT_EQ('0', at("123098456", 9));
    EXPECT_EQ('0', at("123098456", 30));
}

TEST(SupportFunctionsTest, trunkLastDigit)
{
    EXPECT_EQ("", trunkLastDigit(""));
    EXPECT_EQ("", trunkLastDigit("0"));
    EXPECT_EQ("", trunkLastDigit("1"));
    EXPECT_EQ("1", trunkLastDigit("12"));
}

TEST(SupportFunctionsTest, flipCompleatTo9_singleDigit)
{
    EXPECT_EQ("9", flipCompleatTo9("0"));
    EXPECT_EQ("8", flipCompleatTo9("1"));
    EXPECT_EQ("7", flipCompleatTo9("2"));
    EXPECT_EQ("6", flipCompleatTo9("3"));
    EXPECT_EQ("5", flipCompleatTo9("4"));
    EXPECT_EQ("4", flipCompleatTo9("5"));
    EXPECT_EQ("3", flipCompleatTo9("6"));
    EXPECT_EQ("2", flipCompleatTo9("7"));
    EXPECT_EQ("1", flipCompleatTo9("8"));
    EXPECT_EQ("0", flipCompleatTo9("9"));
}

TEST(SupportFunctionsTest, flipCompleatTo9_longerNumbers)
{
    EXPECT_EQ("8765432109", flipCompleatTo9("1234567890"));
    EXPECT_EQ("0126831564571", flipCompleatTo9("9873168435428"));
}

TEST(SupportFunctionsTest, flipU10_singleDigit)
{
    EXPECT_EQ("10", flipU10("0"));
    EXPECT_EQ("9", flipU10("1"));
    EXPECT_EQ("8", flipU10("2"));
    EXPECT_EQ("7", flipU10("3"));
    EXPECT_EQ("6", flipU10("4"));
    EXPECT_EQ("5", flipU10("5"));
    EXPECT_EQ("4", flipU10("6"));
    EXPECT_EQ("3", flipU10("7"));
    EXPECT_EQ("2", flipU10("8"));
    EXPECT_EQ("1", flipU10("9"));
}

TEST(SupportFunctionsTest, flipU10)
{
    EXPECT_EQ("8765432110", flipU10("1234567890"));
    EXPECT_EQ("126831564572", flipU10("9873168435428"));
}

TEST(SupportFunctionsTest, extendToLength)
{
    EXPECT_EQ("0000", extendToLength("", 4));
    EXPECT_EQ("0000", extendToLength("00", 4));
    EXPECT_EQ("0000", extendToLength("0000", 4));
    EXPECT_EQ("00000", extendToLength("00000", 4));
    EXPECT_EQ("0023", extendToLength("23", 4));
}
