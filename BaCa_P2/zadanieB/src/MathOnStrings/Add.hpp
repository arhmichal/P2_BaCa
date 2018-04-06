#pragma once

#include <string>

namespace MathOnStrings
{
namespace details
{
std::string simpleAdd(const std::string&, const std::string&);
std::string redirectingAdd(const std::string&, const std::string&);
std::string redirectingSub(const std::string&, const std::string&);
std::string pseudoSub(const std::string&, const std::string&);
}

std::string add(const std::string&, const std::string&);

}
