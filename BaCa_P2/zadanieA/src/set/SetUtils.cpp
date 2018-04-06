#include "SetUtils.hpp"
#include "math/MathUtils.hpp"

namespace set
{

const unsigned invert(const unsigned set1)
{
    return set1 ^ 0b11111u; // IMPORTANT length dependency
}

const unsigned sum(const unsigned set1, const unsigned set2)
{
    return set1 | set2;
}

const unsigned intersect(const unsigned set1, const unsigned set2)
{
    return set1 & set2;
}

const unsigned symmetricDifference(const unsigned set1, const unsigned set2)
{
    return set1 ^ set2;
}

const unsigned difference(const unsigned set1, const unsigned set2)
{
    return (set1 ^ set2) & set1;
}

const unsigned setSize(const unsigned set) // IMPORTANT length dependency
{
    unsigned size = 0;
    if (set&0b10000u) size = math::addOne(size);
    if (set&0b1000u) size = math::addOne(size);
    if (set&0b100u) size = math::addOne(size);
    if (set&0b10u) size = math::addOne(size);
    if (set&0b1u) size = math::addOne(size);
    return size;
}

int push_back(int& out, const char charValue)
{
    int num = charValue == '0' ? 0 : 1;
    out = (out << 1) | num;
    return out;
}

} // namespace set;
