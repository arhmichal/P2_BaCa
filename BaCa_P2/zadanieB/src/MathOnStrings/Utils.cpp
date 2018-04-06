#include "Logger.hpp"
#include "Utils.hpp"
#include "Add.hpp"

namespace MathOnStrings
{
namespace Utils
{

std::string sign(const std::string& num)
{
    return (num[0] == '-') ? "-" : "+";
}

std::string noSign(const std::string& num)
{
    return (num[0] == '+' or num[0] == '-') ? num.substr(1) : num;
}

std::string stripFrontZeros(const std::string& digitsOnly)
{
    int firstNonZero = digitsOnly.find_first_not_of('0');
    if (digitsOnly.length() <= firstNonZero)
        return "0";
    return digitsOnly.substr(firstNonZero);
}

std::string extendToLength(const std::string& digitsOnly, unsigned length)
{
    if (length < digitsOnly.length())
        length = digitsOnly.length();
    if (length == digitsOnly.length())
        return digitsOnly;
    std::string ret(length, '0');
    for (int i = 0; i < digitsOnly.length(); i++)
        ret[length - 1 - i] = digitsOnly[digitsOnly.length() - 1 - i];
    return ret;
}

/// returns in format [+-]\d*
std::string normalizeNumber(const std::string& num, unsigned length)
{
    std::string numSign = sign(num);
    std::string numDigits = stripFrontZeros(noSign(num));
    if (numDigits == "0")
        numSign = "+";
    return numSign + extendToLength(numDigits, length);
}

/// return in format -?[1-9]\d*
std::string normalizeResult(const std::string& num)
{
    std::string nNum = normalizeNumber(num);
    if (noSign(nNum) == "0")
        return "0";
    return (nNum[0] == '+') ? nNum.substr(1) : nNum;
}

}

namespace U10
{

using namespace Utils;

std::string decodeU10(const std::string& num) // TODO
{
    if (num[0] == '1')
        return "-" + encodeDigits(num.substr(1));
    else
        return num;
}

std::string encodeU10(const std::string& num)
{
    if (sign(num) == "-")
        return encodeSign(sign(num)) + encodeDigits(noSign(num));
    else
        return encodeSign(sign(num)) + noSign(num);
}

std::string encodeSign(const std::string& numSign)
{
    return (numSign == "-") ? "1" : "0";
}

std::string encodeDigits(const std::string& digitsOnly)
{
    std::string ret = digitsOnly;
    for (int i = 0; i < ret.length(); i++)
        ret[i] = '9' - ret[i] + '0';
    std::string one(ret.length(), '0');
    one[one.length() - 1] = '1';
    return details::simpleAdd(ret, one);
}

//char at(const std::string& num, int position)
//{
//    if (num.length() <= position)
//        return '0';
//    return (num[num.length() - 1 - position]);
//}
//
//std::string trunkLastDigit(const std::string& num)
//{
//    return (num.length() == 0 or num.length() == 1) ? "" : num.substr(0, num.length() - 1);
//}
//
//std::string flipU10(const std::string& num)
//{
//    return add(flipCompleatTo9(num), "1");
//}
//
//std::string flipCompleatTo9(const std::string& num)
//{
//    std::string ret = num;
//    for (int i = 0; i < ret.length(); i++)
//        ret[i] = '9' - ret[i] + '0';
//    return ret;
//}

}
}
