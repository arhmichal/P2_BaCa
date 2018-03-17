#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

int complement(int val1) { int ret = 0; Complement(val1, &ret); return ret; }
int unionX(int val1, int val2) { int ret = 0; Union(val1, val2, &ret); return ret; }
int intersection(int val1, int val2) { int ret = 0; Intersection(val1, val2, &ret); return ret; }
int symmetric(int val1, int val2) { int ret = 0; Symmetric(val1, val2, &ret); return ret; }
int difference(int val1, int val2) { int ret = 0; Difference(val1, val2, &ret); return ret; }

using namespace testing;

TEST(SetArythmeticsTest, complement)
{
    EXPECT_EQ(intSet::allOne, complement(intSet::allZero));
    EXPECT_EQ(intSet::allZero, complement(intSet::allOne));
    EXPECT_EQ(intSet::notElem1, complement(intSet::elem1));
    EXPECT_EQ(intSet::alternateFrom1, complement(intSet::alternateFrom0));
    EXPECT_EQ(intSet::alternateFrom0, complement(intSet::alternateFrom1));
    EXPECT_EQ(intSet::custom10010, complement(intSet::custom01101));
}

TEST(SetArythmeticsTest, union_withEmpty_returnsUnchanged)
{
    EXPECT_EQ(intSet::allZero, unionX(intSet::allZero, intSet::allZero));
    EXPECT_EQ(intSet::allOne, unionX(intSet::allOne, intSet::allZero));
    EXPECT_EQ(intSet::elem1, unionX(intSet::elem1, intSet::allZero));
    EXPECT_EQ(intSet::alternateFrom0, unionX(intSet::alternateFrom0, intSet::allZero));
    EXPECT_EQ(intSet::alternateFrom1, unionX(intSet::alternateFrom1, intSet::allZero));
    EXPECT_EQ(intSet::custom01101, unionX(intSet::custom01101, intSet::allZero));
}

TEST(SetArythmeticsTest, union_withSingleton_unitesTheSets)
{
    EXPECT_EQ(intSet::elem2, unionX(intSet::allZero, intSet::elem2));
    EXPECT_EQ(intSet::allOne, unionX(intSet::allOne, intSet::elem2));
    EXPECT_EQ(intSet::custom00110, unionX(intSet::elem1, intSet::elem2));
    EXPECT_EQ(intSet::custom01110, unionX(intSet::alternateFrom0, intSet::elem2));
    EXPECT_EQ(intSet::alternateFrom1, unionX(intSet::alternateFrom1, intSet::elem2));
    EXPECT_EQ(intSet::custom01101, unionX(intSet::custom01101, intSet::elem2));
}

TEST(SetArythmeticsTest, union_withOtherSet_unitesTheSets)
{
    EXPECT_EQ(intSet::alternateFrom1, unionX(intSet::allZero, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allOne, unionX(intSet::allOne, intSet::alternateFrom1));
    EXPECT_EQ(intSet::notElem3, unionX(intSet::elem1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allOne, unionX(intSet::alternateFrom0, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom1, unionX(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::notElem1, unionX(intSet::custom01101, intSet::alternateFrom1));
}

TEST(SetArythmeticsTest, intersection_withEmpty_returnsEmpty)
{
    EXPECT_EQ(intSet::allZero, intersection(intSet::allZero, intSet::allZero));
    EXPECT_EQ(intSet::allZero, intersection(intSet::allOne, intSet::allZero));
    EXPECT_EQ(intSet::allZero, intersection(intSet::elem1, intSet::allZero));
    EXPECT_EQ(intSet::allZero, intersection(intSet::alternateFrom0, intSet::allZero));
    EXPECT_EQ(intSet::allZero, intersection(intSet::alternateFrom1, intSet::allZero));
    EXPECT_EQ(intSet::allZero, intersection(intSet::custom01101, intSet::allZero));
}

TEST(SetArythmeticsTest, intersection_withSingleton_ReturnsTheSameSingletonOrEmpty)
{
    EXPECT_EQ(intSet::allZero, intersection(intSet::allZero, intSet::elem2));
    EXPECT_EQ(intSet::elem2, intersection(intSet::allOne, intSet::elem2));
    EXPECT_EQ(intSet::elem1, intersection(intSet::elem1, intSet::elem1));
    EXPECT_EQ(intSet::allZero, intersection(intSet::alternateFrom0, intSet::elem2));
    EXPECT_EQ(intSet::elem2, intersection(intSet::alternateFrom1, intSet::elem2));
    EXPECT_EQ(intSet::elem3, intersection(intSet::custom01101, intSet::elem3));
}

TEST(SetArythmeticsTest, intersection_withOtherSet_intersectsTheSets)
{
    EXPECT_EQ(intSet::allZero, intersection(intSet::allZero, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom1, intersection(intSet::allOne, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allZero, intersection(intSet::elem1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allZero, intersection(intSet::alternateFrom0, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom1, intersection(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::custom00101, intersection(intSet::custom01101, intSet::alternateFrom1));

    EXPECT_EQ(intSet::allZero, intersection(intSet::allZero, intSet::alternateFrom0));
    EXPECT_EQ(intSet::alternateFrom0, intersection(intSet::allOne, intSet::alternateFrom0));
    EXPECT_EQ(intSet::elem1, intersection(intSet::elem1, intSet::alternateFrom0));
    EXPECT_EQ(intSet::alternateFrom0, intersection(intSet::alternateFrom0, intSet::alternateFrom0));
    EXPECT_EQ(intSet::allZero, intersection(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_EQ(intSet::elem3, intersection(intSet::custom01101, intSet::alternateFrom0));
}

TEST(SetArythmeticsTest, symmetric_withOtherSet)
{
    EXPECT_EQ(intSet::alternateFrom1, symmetric(intSet::allZero, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom0, symmetric(intSet::allOne, intSet::alternateFrom1));
    EXPECT_EQ(intSet::notElem3, symmetric(intSet::elem1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allOne, symmetric(intSet::alternateFrom0, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allZero, symmetric(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::custom11000, symmetric(intSet::custom01101, intSet::alternateFrom1));
}

TEST(SetArythmeticsTest, difference_withOtherSet)
{
    EXPECT_EQ(intSet::allZero, difference(intSet::allZero, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom0, difference(intSet::allOne, intSet::alternateFrom1));
    EXPECT_EQ(intSet::elem1, difference(intSet::elem1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::alternateFrom0, difference(intSet::alternateFrom0, intSet::alternateFrom1));
    EXPECT_EQ(intSet::allZero, difference(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_EQ(intSet::elem3, difference(intSet::custom01101, intSet::alternateFrom1));
}
