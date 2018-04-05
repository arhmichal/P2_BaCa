#pragma once

#include <string>

namespace MyMathOnStrings
{
namespace Utils
{

std::string normalizeNumber(const std::string& num);
std::string removePrefixZeros(const std::string& digitsOnly);
std::string sign(const std::string& num);
std::string absVal(const std::string& num);
std::string normalizeResult(const std::string& num);
char at(const std::string& num, int position);
std::string trunkLastDigit(const std::string& num);
std::string flipU10(const std::string& num);
std::string flipCompleatTo9(const std::string& num);
std::string extendToLength(const std::string& num, const int length);

}
}
