#pragma once

#include <string>

namespace MathOnStrings
{
namespace Utils
{

std::string sign(const std::string& num);
std::string noSign(const std::string& num);
std::string stripFrontZeros(const std::string& digitsOnly);
std::string extendToLength(const std::string& digitsOnly, unsigned length = 0);
std::string normalizeNumber(const std::string& num, unsigned length = 0);
std::string normalizeResult(const std::string& num);

//char at(const std::string& num, int position);
//std::string trunkLastDigit(const std::string& num);

}
namespace U10
{

std::string decodeU10(const std::string& num);
std::string encodeU10(const std::string& num);
std::string encodeSign(const std::string& numSign);
std::string encodeDigits(const std::string& digitsOnly);
//std::string flipU10(const std::string& num);
//std::string flipCompleatTo9(const std::string& num);

}
}
