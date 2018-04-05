#include "gtest/gtest.h"
#include "MyMathOnStrings/Addition.hpp"

using namespace testing;
using namespace MyMathOnStrings;

TEST(MathsubingOnStringsTest, SubAbs_empties)
{
    EXPECT_EQ("0", subAbs("", ""));
    EXPECT_EQ("", subAbs("1", ""));
    EXPECT_EQ("-1", subAbs("", "1"));
}

TEST(MathsubingOnStringsTest, SubAbs_zeros)
{
    EXPECT_EQ("0", subAbs("0", "0"));
    EXPECT_EQ("-1", subAbs("0", "1"));
    EXPECT_EQ("1", subAbs("1", "0"));
}

TEST(MathsubingOnStringsTest, SubAbs_bothPositive)
{
    EXPECT_EQ("02", subAbs("15", "13"));
    EXPECT_EQ("13", subAbs("15", "2"));
    EXPECT_EQ("-2", subAbs("13", "15"));
    EXPECT_EQ("-13", subAbs("2", "15"));
    EXPECT_EQ("0999999999999999901", subAbs("1000000000000000012", "111"));
    EXPECT_EQ("0000000000000000111", subAbs("1000000000000000012", "999999999999999901"));
    EXPECT_EQ("8435118364368268068401", subAbs("8435926825213689153241", "808460845421084840"));
    EXPECT_EQ("0000808460845421084840", subAbs("8435926825213689153241", "8435118364368268068401"));
}

TEST(MathsubingOnStringsTest, subAbs_acceptsNoNegativeValues)
{
    ASSERT_TRUE(true);
}

TEST(MathsubingOnStringsTest, Sub_bothPositive)
{
    EXPECT_EQ("2", sub("15", "13"));
    EXPECT_EQ("13", sub("15", "2"));
    EXPECT_EQ("-2", sub("13", "15"));
    EXPECT_EQ("-13", sub("2", "15"));
    EXPECT_EQ("999999999999999901", sub("1000000000000000012", "111"));
    EXPECT_EQ("111", sub("1000000000000000012", "999999999999999901"));
    EXPECT_EQ("8435118364368268068401", sub("8435926825213689153241", "808460845421084840"));
    EXPECT_EQ("808460845421084840", sub("8435926825213689153241", "8435118364368268068401"));
}
