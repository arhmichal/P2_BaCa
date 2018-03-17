#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

std::string print(int set) { std::string ret = "XXXXXXXXXXXXXXXX"; Print(set, &ret); return ret; }

using namespace testing;

TEST(PrintTest, forEmptySet_returnSpecialCase_word_EMPTY_)
{
    EXPECT_EQ(strSet::empty + " ", print(intSet::allZero));
}

TEST(PrintTest, forNonEmptySet_returnBinaryRepresentation_noWhiteCharacters_exceptSpaceAtTheEnd)
{
    EXPECT_EQ(strSet::allOne + " ", print(intSet::allOne));
    EXPECT_EQ(strSet::alternateFrom0 + " ", print(intSet::alternateFrom0));
    EXPECT_EQ(strSet::alternateFrom1 + " ", print(intSet::alternateFrom1));
    EXPECT_EQ(strSet::custom10010 + " ", print(intSet::custom10010));
    EXPECT_EQ(strSet::custom01101 + " ", print(intSet::custom01101));
    EXPECT_EQ(strSet::custom11001 + " ", print(intSet::custom11001));
    EXPECT_EQ(strSet::custom10011 + " ", print(intSet::custom10011));
    EXPECT_EQ(strSet::custom00110 + " ", print(intSet::custom00110));
    EXPECT_EQ(strSet::custom01110 + " ", print(intSet::custom01110));
    EXPECT_EQ(strSet::custom00101 + " ", print(intSet::custom00101));
    EXPECT_EQ(strSet::custom11000 + " ", print(intSet::custom11000));
    EXPECT_EQ(strSet::elem4 + " ", print(intSet::elem4));
    EXPECT_EQ(strSet::elem3 + " ", print(intSet::elem3));
    EXPECT_EQ(strSet::elem2 + " ", print(intSet::elem2));
    EXPECT_EQ(strSet::elem1 + " ", print(intSet::elem1));
    EXPECT_EQ(strSet::elem0 + " ", print(intSet::elem0));
    EXPECT_EQ(strSet::notElem0 + " ", print(intSet::notElem0));
    EXPECT_EQ(strSet::notElem1 + " ", print(intSet::notElem1));
    EXPECT_EQ(strSet::notElem2 + " ", print(intSet::notElem2));
    EXPECT_EQ(strSet::notElem3 + " ", print(intSet::notElem3));
    EXPECT_EQ(strSet::notElem4 + " ", print(intSet::notElem4));
}
