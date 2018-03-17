#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

using namespace testing;
using namespace set;

// NOTE: setSize() works for up to 5 elements

TEST(setSize, zero_forEmptySet)
{
    ASSERT_EQ(0, setSize(0b0000000000000000));
}

TEST(setSize, one_regardlessWhereTheElementIs)
{
    ASSERT_EQ(1, setSize(0b00001));
    ASSERT_EQ(1, setSize(0b00010));
    ASSERT_EQ(1, setSize(0b00100));
    ASSERT_EQ(1, setSize(0b01000));
    ASSERT_EQ(1, setSize(0b10000));
}

TEST(setSize, two_regardlessWhereTheElementsAre)
{
    ASSERT_EQ(2, setSize(0b10001));
    ASSERT_EQ(2, setSize(0b10010));
    ASSERT_EQ(2, setSize(0b10100));
    ASSERT_EQ(2, setSize(0b11000));

    ASSERT_EQ(2, setSize(0b00101));
    ASSERT_EQ(2, setSize(0b00110));
    ASSERT_EQ(2, setSize(0b01100));
    ASSERT_EQ(2, setSize(0b10100));

    ASSERT_EQ(2, setSize(0b00011));
    ASSERT_EQ(2, setSize(0b00101));
    ASSERT_EQ(2, setSize(0b01001));
    ASSERT_EQ(2, setSize(0b10001));
}

TEST(setSize, three_regardlessWhereTheElementsAre)
{
    ASSERT_EQ(3, setSize(0b01110));
    ASSERT_EQ(3, setSize(0b01101));
    ASSERT_EQ(3, setSize(0b01011));
    ASSERT_EQ(3, setSize(0b00111));

    ASSERT_EQ(3, setSize(0b11010));
    ASSERT_EQ(3, setSize(0b11001));
    ASSERT_EQ(3, setSize(0b10011));
    ASSERT_EQ(3, setSize(0b01011));

    ASSERT_EQ(3, setSize(0b11100));
    ASSERT_EQ(3, setSize(0b11010));
    ASSERT_EQ(3, setSize(0b10110));
    ASSERT_EQ(3, setSize(0b01110));
}

TEST(setSize, four_regardlessWhereTheElementsAre)
{
    ASSERT_EQ(4, setSize(0b11110));
    ASSERT_EQ(4, setSize(0b11101));
    ASSERT_EQ(4, setSize(0b11011));
    ASSERT_EQ(4, setSize(0b10111));
    ASSERT_EQ(4, setSize(0b01111));
}

TEST(setSize, five_forFullSet)
{
    ASSERT_EQ(5, setSize(0b00000000000011111));
}

TEST(push_back, addsBitsAt_leastSignificantPosition)
{
    int val_01 = 0b00110;
    ASSERT_EQ(0b001101, push_back(val_01, '1'));
    ASSERT_EQ(0b0011011, push_back(val_01, '1'));
    ASSERT_EQ(0b00110110, push_back(val_01, '0'));
    ASSERT_EQ(0b001101100, push_back(val_01, '0'));
    ASSERT_EQ(0b0011011001, push_back(val_01, '1'));
}

// already tested indirectly in SetArythmeticsTest
//  const unsigned invert(unsigned set1);
//  const unsigned sum(unsigned set1, unsigned set2);
//  const unsigned intersect(unsigned set1, unsigned set2);
//  const unsigned symmetricDifference(unsigned set1, unsigned set2);
//  const unsigned difference(unsigned set1, unsigned set2);
