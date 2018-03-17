#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

using namespace testing;

TEST(OrderTest, equality)
{
    ASSERT_TRUE(Equality(intSet::allZero, intSet::allZero));
    ASSERT_TRUE(Equality(intSet::allOne, intSet::allOne));
    ASSERT_TRUE(Equality(intSet::elem1, intSet::elem1));
    ASSERT_TRUE(Equality(intSet::alternateFrom0, intSet::alternateFrom0));
    ASSERT_TRUE(Equality(intSet::alternateFrom1, intSet::alternateFrom1));
    ASSERT_TRUE(Equality(intSet::custom01101, intSet::custom01101));
}

TEST(OrderTest, unequality)
{
    ASSERT_FALSE(Equality(intSet::allZero, intSet::custom01101));
    ASSERT_FALSE(Equality(intSet::allOne, intSet::allZero));
    ASSERT_FALSE(Equality(intSet::elem1, intSet::allOne));
    ASSERT_FALSE(Equality(intSet::alternateFrom0, intSet::elem1));
    ASSERT_FALSE(Equality(intSet::alternateFrom1, intSet::alternateFrom0));
    ASSERT_FALSE(Equality(intSet::custom01101, intSet::alternateFrom1));
}

TEST(OrderTest, any_not_LessThen_self)
{
    ASSERT_FALSE(LessThen(intSet::allZero, intSet::allZero));
    ASSERT_FALSE(LessThen(intSet::allOne, intSet::allOne));
    ASSERT_FALSE(LessThen(intSet::elem1, intSet::elem1));
    ASSERT_FALSE(LessThen(intSet::alternateFrom0, intSet::alternateFrom0));
    ASSERT_FALSE(LessThen(intSet::alternateFrom1, intSet::alternateFrom1));
    ASSERT_FALSE(LessThen(intSet::custom01101, intSet::custom01101));
}

TEST(OrderTest, empty_LessThen_anySingleElement)
{
    ASSERT_TRUE(LessThen(intSet::allZero, intSet::elem0));
    ASSERT_TRUE(LessThen(intSet::allZero, intSet::elem1));
    ASSERT_TRUE(LessThen(intSet::allZero, intSet::elem2));
    ASSERT_TRUE(LessThen(intSet::allZero, intSet::elem3));
    ASSERT_TRUE(LessThen(intSet::allZero, intSet::elem4));
}

TEST(OrderTest, anySet_LessThen_anyBiggerSet)
{
    ASSERT_TRUE(LessThen(intSet::elem0, intSet::alternateFrom0));
    ASSERT_TRUE(LessThen(intSet::elem1, intSet::alternateFrom0));
    ASSERT_TRUE(LessThen(intSet::elem2, intSet::alternateFrom0));
    ASSERT_TRUE(LessThen(intSet::elem3, intSet::alternateFrom0));
    ASSERT_TRUE(LessThen(intSet::elem4, intSet::alternateFrom0));
    ASSERT_TRUE(LessThen(intSet::alternateFrom0, intSet::alternateFrom1));
    ASSERT_TRUE(LessThen(intSet::alternateFrom1, intSet::allOne));
}

TEST(OrderTest, anyElement_LessThen_anyElementOnFurtherRightPosition)
{
    ASSERT_TRUE(LessThen(intSet::elem0, intSet::elem1));
    ASSERT_TRUE(LessThen(intSet::elem0, intSet::elem2));
    ASSERT_TRUE(LessThen(intSet::elem0, intSet::elem3));
    ASSERT_TRUE(LessThen(intSet::elem0, intSet::elem4));
    ASSERT_TRUE(LessThen(intSet::elem1, intSet::elem2));
    ASSERT_TRUE(LessThen(intSet::elem1, intSet::elem3));
    ASSERT_TRUE(LessThen(intSet::elem1, intSet::elem4));
    ASSERT_TRUE(LessThen(intSet::elem2, intSet::elem3));
    ASSERT_TRUE(LessThen(intSet::elem2, intSet::elem4));
    ASSERT_TRUE(LessThen(intSet::elem3, intSet::elem4));
}

TEST(OrderTest, whenSizesAreEqual_reverseLexicografhicalOrder_applies_earlierSetByRLO_LessThen_latterSetByRLO)
{
    ASSERT_TRUE(LessThen(intSet::custom01101, intSet::custom10011));
    ASSERT_TRUE(LessThen(intSet::custom01101, intSet::custom11001));
    ASSERT_TRUE(LessThen(intSet::custom10011, intSet::custom11001));
}

TEST(OrderTest, any_LessEqual_self)
{
    EXPECT_TRUE(LessEqual(intSet::allZero, intSet::allZero));
    EXPECT_TRUE(LessEqual(intSet::allOne, intSet::allOne));
    EXPECT_TRUE(LessEqual(intSet::elem1, intSet::elem1));
    EXPECT_TRUE(LessEqual(intSet::alternateFrom0, intSet::alternateFrom0));
    EXPECT_TRUE(LessEqual(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_TRUE(LessEqual(intSet::custom01101, intSet::custom01101));
}

TEST(OrderTest, LessEqual_worksInGeneral_becauseUsesAlreadyWorking_LessThen)
{
    EXPECT_TRUE(LessEqual(intSet::allZero, intSet::elem3));
    EXPECT_TRUE(LessEqual(intSet::alternateFrom0, intSet::alternateFrom1));
    EXPECT_TRUE(LessEqual(intSet::alternateFrom1, intSet::allOne));
    EXPECT_TRUE(LessEqual(intSet::elem1, intSet::elem4));
    EXPECT_TRUE(LessEqual(intSet::custom01101, intSet::custom10011));
    EXPECT_TRUE(LessEqual(intSet::custom01101, intSet::custom11001));
    EXPECT_TRUE(LessEqual(intSet::custom10011, intSet::custom11001));
}

TEST(OrderTest, GreatThen_worksInGeneral_becauseUsesAlreadyWorking_LessThen)
{
    EXPECT_TRUE(GreatThen(intSet::elem3, intSet::allZero));
    EXPECT_TRUE(GreatThen(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_TRUE(GreatThen(intSet::allOne, intSet::alternateFrom1));
    EXPECT_TRUE(GreatThen(intSet::elem4, intSet::elem1));
    EXPECT_TRUE(GreatThen(intSet::custom10011, intSet::custom01101));
    EXPECT_TRUE(GreatThen(intSet::custom11001, intSet::custom01101));
    EXPECT_TRUE(GreatThen(intSet::custom11001, intSet::custom10011));
}

TEST(OrderTest, any_GreatEqual_self)
{
    EXPECT_TRUE(GreatEqual(intSet::allZero, intSet::allZero));
    EXPECT_TRUE(GreatEqual(intSet::allOne, intSet::allOne));
    EXPECT_TRUE(GreatEqual(intSet::elem1, intSet::elem1));
    EXPECT_TRUE(GreatEqual(intSet::alternateFrom0, intSet::alternateFrom0));
    EXPECT_TRUE(GreatEqual(intSet::alternateFrom1, intSet::alternateFrom1));
    EXPECT_TRUE(GreatEqual(intSet::custom01101, intSet::custom01101));
}

TEST(OrderTest, GreatEqual_worksInGeneral_becauseUsesAlreadyWorking_LessThen)
{
    EXPECT_TRUE(GreatEqual(intSet::elem3, intSet::allZero));
    EXPECT_TRUE(GreatEqual(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_TRUE(GreatEqual(intSet::allOne, intSet::alternateFrom1));
    EXPECT_TRUE(GreatEqual(intSet::elem4, intSet::elem1));
    EXPECT_TRUE(GreatEqual(intSet::custom10011, intSet::custom01101));
    EXPECT_TRUE(GreatEqual(intSet::custom11001, intSet::custom01101));
    EXPECT_TRUE(GreatEqual(intSet::custom11001, intSet::custom10011));
}
