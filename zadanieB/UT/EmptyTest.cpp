#include "gtest/gtest.h"
#include "FunctionsLib.hpp"

using namespace testing;

TEST(EmptyTest, fails)
{
    std::cout<<'\n';
//    ASSERT_TRUE(false);

    std::string a="abcd";
    int x = 113;
    int x1 = 113;
    int x2 = 114;
    std::string b="def";
    std::string g="ghi";

    int x3 = 115;
    int x4 = 116;

    std::string array[4] = {
        "qwe",
        "zxc",
        "asd",
        "yui"
    };

    std::cout << Sum(3, &a, &b, &g);
    std::cout << Sum(4, array);
}
