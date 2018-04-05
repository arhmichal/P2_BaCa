#include "Logger.hpp"
#include "Utils.hpp"
#include "Addition.hpp"

namespace MyMathOnStrings
{
namespace Utils
{

std::string sign(const std::string& num)
{
    return ('-' == num[0]) ? "-" : "+";
}

std::string absVal(const std::string& num)
{
    return (num[0] == '+' or num[0] == '-') ? ("" + num.substr(1)) : num;
}

/// returns in format [+-][1-9]\d*
std::string normalizeNumber(const std::string& num)
{
    return sign(num) + removePrefixZeros(absVal(num));
}

std::string removePrefixZeros(const std::string& digitsOnly)
{
    int firstNonZero = digitsOnly.find_first_not_of('0');
    if (digitsOnly.length() <= firstNonZero)
        return "0";
    return digitsOnly.substr(firstNonZero);
}

/// return in format -?[1-9]\d*
std::string normalizeResult(const std::string& num)
{
    std::string nNum = normalizeNumber(num);
    if (absVal(nNum) == "0")
        return "0";
    return (nNum[0] == '+') ? nNum.substr(1) : nNum;
}

char at(const std::string& num, int position)
{
    if (num.length() <= position)
        return '0';
    return (num[num.length() - 1 - position]);
}

std::string trunkLastDigit(const std::string& num)
{
    return (num.length() == 0 or num.length() == 1) ? "" : num.substr(0, num.length() - 1);
}

std::string flipU10(const std::string& num)
{
    return add(flipCompleatTo9(num), "1");
}

std::string flipCompleatTo9(const std::string& num)
{
    std::string ret = num;
    for (int i = 0; i < ret.length(); i++)
        ret[i] = '9' - ret[i] + '0';
    return ret;
}

std::string extendToLength(const std::string& num, const int length)
{
    if (num.length() > length)
        return num;
    std::string ret = std::string(length, '0');
    for (int i = 0; i < num.length(); i++)
        ret[ret.length() - 1 - i] = at(num, i);
    return ret;
}

}
}
