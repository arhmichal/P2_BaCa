#include "Logger.hpp"
#include "Addition.hpp"

namespace MyMathOnStrings
{

using namespace Utils;

std::string add(const std::string& num1, const std::string& num2)
{
    std::string n1 = normalizeNumber(num1);
    std::string n2 = normalizeNumber(num2);
    ARHLOG_DBG << "(const std::string& " << n1 << ", const std::string& " << n2 << ")";
    if (sign(n1) == sign(n2))
        return normalizeResult(sign(n1) + addAbs(absVal(n1), absVal(n2)));
    if (sign(n1) == "-")
        return sub(num2, num1);
    else
        return sub(num1, num2);
}

std::string addAbs(const std::string& num1, const std::string& num2)
{
    if (num1 < num2)
        return addAbs(num2, num1);
    if (num1.length() == 0)
        return "";
    if (num2.length() == 0)
        return num1;
    int sum = (at(num1, 0) - '0') + (at(num2, 0) - '0');
    bool carry = sum / 10 == 1;
    std::string digit = std::string() + (char)((sum % 10) + '0');
    std::string result = addAbs(trunkLastDigit(num1), trunkLastDigit(num2));
    return (carry ? addAbs(result, "1") : result) + digit;
}

std::string sub(const std::string& num1, const std::string& num2)
{
    std::string n1 = normalizeNumber(num1);
    std::string n2 = normalizeNumber(num2);
    ARHLOG_DBG << "(const std::string& " << n1 << ", const std::string& " << n2 << ")";
    return normalizeResult(subAbs(absVal(n1), absVal(n2)));
}

std::string subAbs(const std::string& positive, const std::string& negative)
{
    if (positive == negative)
        return "0";
    bool positiveIsBigger = (positive.length() > negative.length());
    if (positive.length() == negative.length())
        positiveIsBigger = positive > negative;

    if (positiveIsBigger)
        return addAbs(positive, flipU10(extendToLength(negative, positive.length()))).substr(1);
    else
        return "-" + flipU10(addAbs(positive, flipU10(negative)));
}

}
