#include "gtest/gtest.h"
#include "BitSetLib.hpp"
#include "CommonValues.hpp"

int insert(const std::string& multipleSetsSource, int intoHere) { int ret = intoHere; Insert(multipleSetsSource, &ret); return ret; }
int erase(const std::string& multipleSetsSource, int fromHere) { int ret = fromHere; Erase(multipleSetsSource, &ret); return ret; }
bool member(const std::string& multipleSetsSource, int set) { return Member(multipleSetsSource, set); }

using namespace testing;

void runMemberTests(const std::string& prefix, const std::string& sufix)
{
    EXPECT_FALSE(member(prefix + strSet::elem2 + sufix, intSet::allZero));
    EXPECT_TRUE(member(prefix + strSet::elem2 + sufix, intSet::allOne));
    EXPECT_FALSE(member(prefix + strSet::elem2 + sufix, intSet::elem1));
    EXPECT_TRUE(member(prefix + strSet::elem2 + sufix, intSet::elem2));
    EXPECT_FALSE(member(prefix + strSet::elem2 + sufix, intSet::alternateFrom0));
    EXPECT_TRUE(member(prefix + strSet::elem2 + sufix, intSet::alternateFrom1));
    EXPECT_TRUE(member(prefix + strSet::elem2 + sufix, intSet::custom01101));
}

TEST(ElementOperationsTest, member_withNoWhitespaces)
{
    runMemberTests(whitespaces::empty, whitespaces::empty);
}

TEST(ElementOperationsTest, member_withWhitespaces_inPrefix)
{
    runMemberTests(whitespaces::noise, whitespaces::empty);
}

TEST(ElementOperationsTest, member_withWhitespaces_inSufix)
{
    runMemberTests(whitespaces::empty, whitespaces::noise);
}

TEST(ElementOperationsTest, member_withWhitespaces_inPrefixSufix)
{
    runMemberTests(whitespaces::noise, whitespaces::noise);
}

void runInsertTests(const std::string& prefix, const std::string& sufix)
{
    EXPECT_EQ(intSet::elem2, insert(prefix + strSet::elem2 + sufix, intSet::allZero));
    EXPECT_EQ(intSet::allOne, insert(prefix + strSet::elem2 + sufix, intSet::allOne));
    EXPECT_EQ(intSet::custom00110, insert(prefix + strSet::elem2 + sufix, intSet::elem1));
    EXPECT_EQ(intSet::elem2, insert(prefix + strSet::elem2 + sufix, intSet::elem2));
    EXPECT_EQ(intSet::custom01110, insert(prefix + strSet::elem2 + sufix, intSet::alternateFrom0));
    EXPECT_EQ(intSet::alternateFrom1, insert(prefix + strSet::elem2 + sufix, intSet::alternateFrom1));
    EXPECT_EQ(intSet::custom01101, insert(prefix + strSet::elem2 + sufix, intSet::custom01101));
}

TEST(ElementOperationsTest, insert_withNoWhitespaces)
{
    runInsertTests(whitespaces::empty, whitespaces::empty);
}

TEST(ElementOperationsTest, insert_withWhitespaces_inPrefix)
{
    runInsertTests(whitespaces::noise, whitespaces::empty);
}

TEST(ElementOperationsTest, insert_withWhitespaces_inSufix)
{
    runInsertTests(whitespaces::empty, whitespaces::noise);
}

TEST(ElementOperationsTest, insert_withWhitespaces_inPrefixSufix)
{
    runInsertTests(whitespaces::noise, whitespaces::noise);
}

void runInsertTestsWithMultipleValues(const std::string& values)
{
    EXPECT_EQ(intSet::custom01110, insert(values, intSet::allZero));
    EXPECT_EQ(intSet::allOne, insert(values, intSet::allOne));
    EXPECT_EQ(intSet::custom01110, insert(values, intSet::elem1));
    EXPECT_EQ(intSet::custom01110, insert(values, intSet::elem2));
    EXPECT_EQ(intSet::custom01110, insert(values, intSet::alternateFrom0));
    EXPECT_EQ(intSet::allOne, insert(values, intSet::alternateFrom1));
    EXPECT_EQ(intSet::notElem4, insert(values, intSet::custom01101));
}

TEST(ElementOperationsTest, insert_multipleValues_withWhitespaces)
{
    runInsertTestsWithMultipleValues(
        whitespaces::noise +
        strSet::elem2 +
        strSet::elem1 +
        whitespaces::noise +
        strSet::elem3 +
        whitespaces::noise);
}

void runEraseTests(const std::string& prefix, const std::string& sufix)
{
    EXPECT_EQ(intSet::allZero, erase(prefix + strSet::elem2 + sufix, intSet::allZero));
    EXPECT_EQ(intSet::notElem2, erase(prefix + strSet::elem2 + sufix, intSet::allOne));
    EXPECT_EQ(intSet::elem1, erase(prefix + strSet::elem2 + sufix, intSet::elem1));
    EXPECT_EQ(intSet::allZero, erase(prefix + strSet::elem2 + sufix, intSet::elem2));
    EXPECT_EQ(intSet::alternateFrom0, erase(prefix + strSet::elem2 + sufix, intSet::alternateFrom0));
    EXPECT_EQ(intSet::custom10001, erase(prefix + strSet::elem2 + sufix, intSet::alternateFrom1));
    EXPECT_EQ(intSet::custom01001, erase(prefix + strSet::elem2 + sufix, intSet::custom01101));
}

TEST(ElementOperationsTest, erase_withNoWhitespaces)
{
    runEraseTests(whitespaces::empty, whitespaces::empty);
}

TEST(ElementOperationsTest, erase_withWhitespaces_inPrefix)
{
    runEraseTests(whitespaces::noise, whitespaces::empty);
}

TEST(ElementOperationsTest, erase_withWhitespaces_inSufix)
{
    runEraseTests(whitespaces::empty, whitespaces::noise);
}

TEST(ElementOperationsTest, erase_withWhitespaces_inPrefixSufix)
{
    runEraseTests(whitespaces::noise, whitespaces::noise);
}

void runEraseTestsWithMultipleValues(const std::string& values)
{
    EXPECT_EQ(intSet::allZero, erase(values, intSet::allZero));
    EXPECT_EQ(intSet::custom10001, erase(values, intSet::allOne));
    EXPECT_EQ(intSet::allZero, erase(values, intSet::elem1));
    EXPECT_EQ(intSet::allZero, erase(values, intSet::elem2));
    EXPECT_EQ(intSet::allZero, erase(values, intSet::alternateFrom0));
    EXPECT_EQ(intSet::custom10001, erase(values, intSet::alternateFrom1));
    EXPECT_EQ(intSet::elem0, erase(values, intSet::custom01101));
}

TEST(ElementOperationsTest, erase_multipleValues_withWhitespaces)
{
    runEraseTestsWithMultipleValues(
        whitespaces::noise +
        strSet::elem2 +
        strSet::elem1 +
        whitespaces::noise +
        strSet::elem3 +
        whitespaces::noise);
}
