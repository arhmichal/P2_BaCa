#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

int emplace(const std::string& multipleSetsSource) { int ret = intSet::invalid; Emplace(multipleSetsSource, &ret); return ret; }

using namespace testing;

TEST(ElementOperationsTest, emplace_emptyString_returnsNoChanges)
{
    EXPECT_EQ(intSet::invalid, emplace(whitespaces::empty));
}

TEST(ElementOperationsTest, emplace_noValueOnlyWhitespaces_returnsNoChanges)
{
    EXPECT_EQ(intSet::invalid, emplace(whitespaces::noise));
}

void runEmplaceTests(const std::string& prefix, const std::string& sufix)
{
    EXPECT_EQ(intSet::allOne, emplace(prefix + strSet::allOne + sufix));
    EXPECT_EQ(intSet::alternateFrom0, emplace(prefix + strSet::alternateFrom0 + sufix));
    EXPECT_EQ(intSet::alternateFrom1, emplace(prefix + strSet::alternateFrom1 + sufix));
    EXPECT_EQ(intSet::custom10010, emplace(prefix + strSet::custom10010 + sufix));
    EXPECT_EQ(intSet::custom01101, emplace(prefix + strSet::custom01101 + sufix));
    EXPECT_EQ(intSet::custom11001, emplace(prefix + strSet::custom11001 + sufix));
    EXPECT_EQ(intSet::custom10011, emplace(prefix + strSet::custom10011 + sufix));
    EXPECT_EQ(intSet::custom00110, emplace(prefix + strSet::custom00110 + sufix));
    EXPECT_EQ(intSet::custom01110, emplace(prefix + strSet::custom01110 + sufix));
    EXPECT_EQ(intSet::custom00101, emplace(prefix + strSet::custom00101 + sufix));
    EXPECT_EQ(intSet::custom11000, emplace(prefix + strSet::custom11000 + sufix));
    EXPECT_EQ(intSet::elem4, emplace(prefix + strSet::elem4 + sufix));
    EXPECT_EQ(intSet::elem3, emplace(prefix + strSet::elem3 + sufix));
    EXPECT_EQ(intSet::elem2, emplace(prefix + strSet::elem2 + sufix));
    EXPECT_EQ(intSet::elem1, emplace(prefix + strSet::elem1 + sufix));
    EXPECT_EQ(intSet::elem0, emplace(prefix + strSet::elem0 + sufix));
    EXPECT_EQ(intSet::notElem0, emplace(prefix + strSet::notElem0 + sufix));
    EXPECT_EQ(intSet::notElem1, emplace(prefix + strSet::notElem1 + sufix));
    EXPECT_EQ(intSet::notElem2, emplace(prefix + strSet::notElem2 + sufix));
    EXPECT_EQ(intSet::notElem3, emplace(prefix + strSet::notElem3 + sufix));
    EXPECT_EQ(intSet::notElem4, emplace(prefix + strSet::notElem4 + sufix));
}

TEST(ElementOperationsTest, emplace_withNoWhitespaces)
{
    runEmplaceTests(whitespaces::empty, whitespaces::empty);
}

TEST(ElementOperationsTest, emplace_withWhitespaces_inPrefix)
{
    runEmplaceTests(whitespaces::noise, whitespaces::empty);
}

TEST(ElementOperationsTest, emplace_withWhitespaces_inSufix)
{
    runEmplaceTests(whitespaces::empty, whitespaces::noise);
}

TEST(ElementOperationsTest, emplace_withWhitespaces_inPrefixSufix)
{
    runEmplaceTests(whitespaces::noise, whitespaces::noise);
}
