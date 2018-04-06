#include "Logger.hpp"
#include "Add.hpp"
#include "Utils.hpp"

namespace MathOnStrings
{

using namespace Utils;

namespace details
{

/** Preconditions
 * - each number is already u10-encoded, therefore
// * --- at least 3-digit long
// *     1 for sign
// *     1 for potencial overflow when adding
// *     at least 1 for numbers to add
// *     !!! IMPORTANT exactly 3 length also means recursion-break condition !!!
 * --- starts with bit-of-sign
 * --- contains only digits
 * - both are equal length
 ** Return
 * - returned number is equal length
 * --- for this to be true, the arguments need to already contain
 *     additional digit co contain potencial overflow
 * - returned is also u10-encoded
 */
std::string simpleAdd(const std::string& num1, const std::string& num2)
{
    if (num1.length() != num2.length())
        throw std::logic_error("numbers are not of equal length"); // sanity check
    const unsigned last = num1.length() - 1;
    std::string ret(last + 1, '0');
    int carry = 0;
    int sum;
    for (int i = last; i >= 0; i--)
    {
        sum = num1[i] - '0' + num2[i] - '0' + carry;
        carry = sum / 10;
        sum = sum % 10;
        ret[i] = sum + '0';
    }
    if (carry)
        ret = (char(carry + '0')) + ret;
    return ret;
}

std::string redirectingAdd(const std::string& n1, const std::string& n2)
{
    ARHLOG_DBG << "(const std::string& " << n1 << ", const std::string& " << n2 << ")";

    if (sign(n1) == sign(n2))
        return sign(n1) + simpleAdd(noSign(n1), noSign(n2));
    if (sign(n1) == "-")
        return pseudoSub(n2, n1);
    else
        return pseudoSub(n1, n2);
}

std::string redirectingSub(const std::string& numPositive, const std::string& numNegative)
{
    ARHLOG_DBG << "(const std::string& " << numPositive << ", const std::string& " << numNegative << ")";

    std::string positive = noSign(numPositive);
    std::string negative = noSign(numNegative);

    if (positive == negative) // comparision without a sign
        return "0";

    std::string added = simpleAdd(U10::encodeU10(numPositive), U10::encodeU10(numNegative));
    if (added[0] == '2')
        added[0] = '0';
    if (positive > negative) // comparision without a sign
        // this is STRING comparision BUT
        // alphabetical order (when comparing strings) and precondition (equal length) ensure this
        // returns mathematically correct answer
        return added;
    else
        return U10::decodeU10(added);
}

std::string pseudoSub(const std::string& positiveNum, const std::string& negativeNum)
{
    ARHLOG_DBG << "(const std::string& " << positiveNum << ", const std::string& " << negativeNum << ")";

    std::string n1 = normalizeNumber(positiveNum);
    std::string n2 = normalizeNumber(negativeNum);
    unsigned length = std::max(n1.length(), n2.length());
    n1 = normalizeNumber(n1, length);
    n2 = normalizeNumber(n2, length);

    return details::redirectingSub(n1, n2);
}

} // namespace details

std::string add(const std::string& num1, const std::string& num2)
{
    ARHLOG_DBG << "(const std::string& " << num1 << ", const std::string& " << num2 << ")";

    std::string n1 = normalizeNumber(num1);
    std::string n2 = normalizeNumber(num2);
    unsigned length = std::max(n1.length(), n2.length());
    n1 = normalizeNumber(n1, length);
    n2 = normalizeNumber(n2, length);

    return normalizeResult(details::redirectingAdd(n1, n2));
}

}
