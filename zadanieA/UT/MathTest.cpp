#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

using namespace testing;
using namespace math;

TEST(odd, worksCorrectly)
{
    ASSERT_TRUE(odd(0b1));
    ASSERT_TRUE(odd(0b01));
    ASSERT_TRUE(odd(0b11));
    ASSERT_TRUE(odd(0b010010101001011001001));
    ASSERT_FALSE(odd(0b0));
    ASSERT_FALSE(odd(0b00));
    ASSERT_FALSE(odd(0b10));
    ASSERT_FALSE(odd(0b010010101001011001000));
}

TEST(addOne, incrementsEvenValues)
{
    ASSERT_EQ(0b1, addOne(0b0));
    ASSERT_EQ(0b11, addOne(0b10));
    ASSERT_EQ(0b1001, addOne(0b1000));
    ASSERT_EQ(0b10011, addOne(0b10010));
    ASSERT_EQ(0b1111111111, addOne(0b1111111110));
}

TEST(addOne, incrementsOddValues)
{
    ASSERT_EQ(0b10, addOne(0b1));
    ASSERT_EQ(0b100, addOne(0b11));
    ASSERT_EQ(0b1010, addOne(0b1001));
    ASSERT_EQ(0b10100, addOne(0b10011));
    ASSERT_EQ(0b10000000000, addOne(0b1111111111));
}

TEST(add, trickyNumbers)
{
    ASSERT_EQ(0b0, add(0b0, 0b0));
    ASSERT_EQ(0b1, add(0b1, 0b0));
    ASSERT_EQ(0b1, add(0b0, 0b1));
    ASSERT_EQ(0b10, add(0b1, 0b1));
    ASSERT_EQ(0b1000, add(0b111, 0b1));
    ASSERT_EQ(0b100000, add(0b10101, 0b1011));
}

TEST(subOne, decrementsOddValues)
{
    ASSERT_EQ(0b0, subOne(0b1));
    ASSERT_EQ(0b10, subOne(0b11));
    ASSERT_EQ(0b1000, subOne(0b1001));
    ASSERT_EQ(0b10010, subOne(0b10011));
    ASSERT_EQ(0b1111111110, subOne(0b1111111111));
}

TEST(subOne, cennootDecrementBelowZero)
{
    ASSERT_EQ(0b0, subOne(0b0));
}

TEST(subOne, decrementsEvenValues)
{
    ASSERT_EQ(0b1, subOne(0b10));
    ASSERT_EQ(0b111, subOne(0b1000));
    ASSERT_EQ(0b10001, subOne(0b10010));
    ASSERT_EQ(0b111011011, subOne(0b111011100));
}

TEST(sub, trickyNumbers)
{
    ASSERT_EQ(0b0, sub(0b0, 0b0));
    ASSERT_EQ(0b1, sub(0b1, 0b0));
    ASSERT_EQ(0b0, sub(0b0, 0b1));
    ASSERT_EQ(0b0, sub(0b1, 0b1));
    ASSERT_EQ(0b110, sub(0b111, 0b1));
    ASSERT_EQ(0b1110011, sub(0b1110111, 0b100));
    ASSERT_EQ(0b1101111, sub(0b1110111, 0b1000));
    ASSERT_EQ(0b10101, sub(0b100000, 0b1011));
}