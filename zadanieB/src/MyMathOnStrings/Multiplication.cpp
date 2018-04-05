#include "Logger.hpp"
#include "Multiplication.hpp"

namespace MyMathOnStrings
{

using namespace Utils;

std::string mult(const std::string& num1, const std::string& num2)
{
    std::string n1 = normalizeNumber(num1);
    std::string n2 = normalizeNumber(num2);
    if (n1[0] == n2[0])
        return sign(n1) + multAbs(absVal(n1), absVal(n2));
    return "-" + multAbs(absVal(n1), absVal(n2));
}

std::string multAbs(const std::string& num1, const std::string& num2)
{
    bool n1IsSmaller = num1 < num2;
    std::string smaller = n1IsSmaller ? num1 : num2;
    std::string bigger = n1IsSmaller ? num2 : num1;

    return num2; // TODO implement
}

}
