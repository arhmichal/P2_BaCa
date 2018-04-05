#pragma once

namespace set
{

const unsigned invert(unsigned set1);
const unsigned sum(unsigned set1, unsigned set2);
const unsigned intersect(unsigned set1, unsigned set2);
const unsigned symmetricDifference(unsigned set1, unsigned set2);
const unsigned difference(unsigned set1, unsigned set2);

const unsigned setSize(unsigned set);

int push_back(int& out, char charValue);

}
