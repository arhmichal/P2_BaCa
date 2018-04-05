#include "MathUtils.hpp"

namespace math
{

bool odd(const unsigned x)
{
    return (x & 0b1) == 0b1;
}

unsigned addOne(const unsigned x)
{
    if (not odd(x))
        return x | 0b1u;

    return addOne(x >> 1u) << 1u;
}

unsigned add(const unsigned x, const unsigned toAdd, const unsigned alreadyAdded)
{
    if (toAdd == 0 || alreadyAdded >= toAdd)
        return x;
    return add(addOne(x), toAdd, addOne(alreadyAdded));
}

unsigned add(const unsigned x, const unsigned toAdd)
{
    return add(x, toAdd, 0);
}

unsigned subOne(const unsigned x)
{
    if (x == 0)
        return x;
    if (odd(x))
        return (x >> 1) << 1;

    return (subOne(x >> 1) << 1) | 0b1u;
}

unsigned sub(const unsigned x, const unsigned toSub, const unsigned alreadySubbed)
{
    if (toSub == 0 || alreadySubbed >= toSub)
        return x;
    return sub(subOne(x), toSub, addOne(alreadySubbed));
}

unsigned sub(const unsigned x, const unsigned toSub)
{
    return sub(x, toSub, 0);
}

} // namespace math;
