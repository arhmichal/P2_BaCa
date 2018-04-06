#pragma once

#include <string>

namespace MathOnStrings
{
namespace details
{
std::string simpleMult(const std::string&, const std::string&);
std::string mulByOneDigit(const std::string&, const std::string&);
}

std::string mult(const std::string&, const std::string&);

}
