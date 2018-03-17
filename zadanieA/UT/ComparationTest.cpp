#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

using namespace testing;

TEST(ComparationTest, inclusion_forEmptyInEmpty)
{
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::allZero));
}

TEST(ComparationTest, inclusion_forEmptySet_alwaysTrue)
{
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::allOne));
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::elem1));
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::alternateFrom0));
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::alternateFrom1));
    EXPECT_TRUE(Inclusion(intSet::allZero, intSet::custom01101));
}

TEST(ComparationTest, inclusion_inEmptySet_alwaysFalse)
{
    EXPECT_FALSE(Inclusion(intSet::allOne, intSet::allZero));
    EXPECT_FALSE(Inclusion(intSet::elem1, intSet::allZero));
    EXPECT_FALSE(Inclusion(intSet::alternateFrom0, intSet::allZero));
    EXPECT_FALSE(Inclusion(intSet::alternateFrom1, intSet::allZero));
    EXPECT_FALSE(Inclusion(intSet::custom01101, intSet::allZero));
}

TEST(ComparationTest, inclusion)
{
    EXPECT_FALSE(Inclusion(intSet::allOne, intSet::allZero));
    EXPECT_TRUE(Inclusion(intSet::elem1, intSet::allOne));
    EXPECT_FALSE(Inclusion(intSet::alternateFrom0, intSet::elem1));
    EXPECT_FALSE(Inclusion(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_FALSE(Inclusion(intSet::custom01101, intSet::alternateFrom1));
    EXPECT_FALSE(Inclusion(intSet::allOne, intSet::custom01101));
    EXPECT_TRUE(Inclusion(intSet::allOne, intSet::allOne));
    EXPECT_TRUE(Inclusion(intSet::custom00101, intSet::custom01101));
}

TEST(ComparationTest, disjoint_forEmptyAndFull_true)
{
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::allOne));
    EXPECT_TRUE(Disjoint(intSet::allOne, intSet::allZero));
}

TEST(ComparationTest, disjoint_forEmpty_alwaysTrue)
{
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::elem1));
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::alternateFrom0));
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::alternateFrom1));
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::custom01101));
    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::custom01101));

    EXPECT_TRUE(Disjoint(intSet::allZero, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::elem1, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::alternateFrom0, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::alternateFrom1, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::custom01101, intSet::allZero));
    EXPECT_TRUE(Disjoint(intSet::custom01101, intSet::allZero));
}

TEST(ComparationTest, disjoint_forFull_alwaysFalse)
{
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::elem1));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::alternateFrom0));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::alternateFrom1));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::custom01101));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::custom01101));

    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::elem1, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::alternateFrom0, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::alternateFrom1, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::custom01101, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::allOne, intSet::allOne));
    EXPECT_FALSE(Disjoint(intSet::custom01101, intSet::allOne));
}

TEST(ComparationTest, disjoint)
{
    EXPECT_FALSE(Disjoint(intSet::alternateFrom0, intSet::elem1));
    EXPECT_TRUE(Disjoint(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_FALSE(Disjoint(intSet::custom01101, intSet::alternateFrom1));
    EXPECT_FALSE(Disjoint(intSet::custom00101, intSet::custom01101));
    EXPECT_TRUE(Disjoint(intSet::custom00101, intSet::custom10010));
}

TEST(ComparationTest, conjunctive_forEmptyAndEmpty_false)
{
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::allZero));
}

TEST(ComparationTest, conjunctive_forEmpty_alwaysFalse)
{
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::allOne));
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::elem1));
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::alternateFrom0));
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::alternateFrom1));
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::custom01101));
    EXPECT_FALSE(Conjunctive(intSet::allZero, intSet::custom01101));

    EXPECT_FALSE(Conjunctive(intSet::allOne, intSet::allZero));
    EXPECT_FALSE(Conjunctive(intSet::elem1, intSet::allZero));
    EXPECT_FALSE(Conjunctive(intSet::alternateFrom0, intSet::allZero));
    EXPECT_FALSE(Conjunctive(intSet::alternateFrom1, intSet::allZero));
    EXPECT_FALSE(Conjunctive(intSet::custom01101, intSet::allZero));
    EXPECT_FALSE(Conjunctive(intSet::custom01101, intSet::allZero));
}

TEST(ComparationTest, conjunctive_forFull_alwaysTrue)
{
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::elem1));
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::alternateFrom0));
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::alternateFrom1));
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::custom01101));
    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::custom01101));

    EXPECT_TRUE(Conjunctive(intSet::allOne, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::elem1, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::alternateFrom0, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::alternateFrom1, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::custom01101, intSet::allOne));
    EXPECT_TRUE(Conjunctive(intSet::custom01101, intSet::allOne));
}

TEST(ComparationTest, conjunctive)
{
    EXPECT_TRUE(Conjunctive(intSet::alternateFrom0, intSet::elem1));
    EXPECT_FALSE(Conjunctive(intSet::alternateFrom1, intSet::alternateFrom0));
    EXPECT_TRUE(Conjunctive(intSet::custom01101, intSet::alternateFrom1));
    EXPECT_TRUE(Conjunctive(intSet::custom00101, intSet::custom01101));
    EXPECT_FALSE(Conjunctive(intSet::custom00101, intSet::custom10010));
}

TEST(ComparationTest, isEmpty)
{
    EXPECT_TRUE(Emptiness(intSet::allZero));
    EXPECT_FALSE(Emptiness(intSet::elem1));
    EXPECT_FALSE(Emptiness(intSet::allOne));
    EXPECT_FALSE(Emptiness(intSet::alternateFrom0));
    EXPECT_FALSE(Emptiness(intSet::alternateFrom1));
    EXPECT_FALSE(Emptiness(intSet::custom01101));
}

TEST(ComparationTest, isNotEmpty)
{
    EXPECT_FALSE(Nonempty(intSet::allZero));
    EXPECT_TRUE(Nonempty(intSet::elem1));
    EXPECT_TRUE(Nonempty(intSet::allOne));
    EXPECT_TRUE(Nonempty(intSet::alternateFrom0));
    EXPECT_TRUE(Nonempty(intSet::alternateFrom1));
    EXPECT_TRUE(Nonempty(intSet::custom01101));
}
