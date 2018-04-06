#include "Logger.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Utils.hpp"

namespace MathOnStrings
{

using namespace Utils;

namespace details
{

std::string simpleMult(const std::string& num1, const std::string& num2)
{
    std::string ret = "0";

    for (int i = 0; i < num2.length(); i++)
    {
        std::string digit = "x";
        digit[0] = num2[num2.length() - 1 - i];
        const std::string mulRes = mulByOneDigit(num1, digit);
        const std::string rowOfMagnitude = std::string(i, '0');
        const std::string numToAdd = mulRes + rowOfMagnitude;
        ret = add(ret, numToAdd);
    }

    return ret;
}

std::string mulByOneDigit(const std::string& num, const std::string& digitStr)
{
    int digit = digitStr[0] - '0';

    if (digit == 0) // optimization - works without this but helps with time
        return "0";
    if (digit == 1) // optimization - works without this but helps with time
        return num;

    std::string ret(num.length() + 1, '0');
    int pro = 0;
    int carry = 0;
    for (int i = 0; i < num.length(); i++)
    {
        pro = (num[num.length() - 1 - i] - '0') * digit + carry;
        carry = pro / 10;
        pro = pro % 10;
        ret[ret.length() - 1 - i] = char(pro + '0');
    }
    if (carry)
        ret[0] = char(carry + '0');
    return ret;
}

} // namespace details

std::string mult(const std::string& num1, const std::string& num2)
{
    ARHLOG_DBG << "(const std::string& " << num1 << ", const std::string& " << num2 << ")";

    std::string n1 = normalizeNumber(num1);
    std::string n2 = normalizeNumber(num2);
    std::string signMult = sign(n1) == sign(n2) ? "+" : "-";

    if (n1.length() < n2.length()) // slight optimization
        return normalizeResult(signMult + details::simpleMult(noSign(n2), noSign(n1)));
    else
        return normalizeResult(signMult + details::simpleMult(noSign(n1), noSign(n2)));
}

}
