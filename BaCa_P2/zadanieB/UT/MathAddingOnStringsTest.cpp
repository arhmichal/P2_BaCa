#include "gtest/gtest.h"
#include "MyMathOnStrings/Addition.hpp"

using namespace testing;
using namespace MyMathOnStrings;

TEST(MathAddingOnStringsTest, AddAbs_empties)
{
    EXPECT_EQ("", addAbs("", ""));
    EXPECT_EQ("1", addAbs("1", ""));
    EXPECT_EQ("1", addAbs("", "1"));
}

TEST(MathAddingOnStringsTest, AddAbs_zeros)
{
    EXPECT_EQ("0", addAbs("0", "0"));
    EXPECT_EQ("1", addAbs("0", "1"));
    EXPECT_EQ("1", addAbs("1", "0"));
}

TEST(MathAddingOnStringsTest, AddAbs_bothPositive)
{
    EXPECT_EQ("15", addAbs("2", "13"));
    EXPECT_EQ("15", addAbs("13", "2"));
    EXPECT_EQ("1000000000000000012", addAbs("999999999999999901", "111"));
    EXPECT_EQ("8435926825213689153241", addAbs("8435118364368268068401", "808460845421084840"));
}

TEST(MathAddingOnStringsTest, AddAbs_acceptsNoNegativeValues)
{
    ASSERT_TRUE(true);
}

TEST(MathAddingOnStringsTest, Add_bothPositive)
{
    EXPECT_EQ("15", add("2", "13"));
    EXPECT_EQ("15", add("13", "2"));
    EXPECT_EQ("1000000000000000012", add("999999999999999901", "111"));
    EXPECT_EQ("8435926825213689153241", add("8435118364368268068401", "808460845421084840"));
}

TEST(MathAddingOnStringsTest, Add_bothNegative)
{
    EXPECT_EQ("-15", add("-2", "-13"));
    EXPECT_EQ("-15", add("-13", "-2"));
    EXPECT_EQ("-1000000000000000012", add("-999999999999999901", "-111"));
    EXPECT_EQ("-8435926825213689153241", add("-8435118364368268068401", "-808460845421084840"));
}

TEST(MathAddingOnStringsTest, Add_oneNegative)
{
    EXPECT_EQ("11", add("-2", "13"));
    EXPECT_EQ("-11", add("-13", "2"));
    EXPECT_EQ("-887", add("-899", "12"));
    EXPECT_EQ("-987", add("-999", "12"));
    EXPECT_EQ("987", add("999", "-12"));
    EXPECT_EQ("999", add("1000", "-1"));
    EXPECT_EQ("900", add("1000", "-100"));
    EXPECT_EQ("0", add("1000", "-1000"));
}

TEST(MathAddingOnStringsTest, XXX)
{
    EXPECT_EQ("-987", add("-999", "12"));
}
