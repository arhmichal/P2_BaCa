#include <iostream>
#include <string>
#include <sstream>

void Emplace(std::string, int*);
void Insert(std::string, int*);
void Erase(std::string, int*);
void Print(int, std::string*);
bool Emptiness(int);
bool Nonempty(int);
bool Member(std::string, int);
bool Disjoint(int, int);
bool Conjunctive(int, int);
bool Equality(int, int);
bool Inclusion(int, int);
void Union(int, int, int*);
void Intersection(int, int, int*);
void Symmetric(int, int, int*);
void Difference(int, int, int*);
void Complement(int, int*);
bool LessThen(int, int);
bool LessEqual(int, int);
bool GreatEqual(int, int);
bool GreatThen(int, int);

namespace math
{

bool odd(unsigned x);

unsigned addOne(unsigned x);
unsigned add(unsigned x, unsigned toAdd, unsigned alreadyAdded);
unsigned add(unsigned x, unsigned toAdd);

unsigned subOne(unsigned x);
unsigned sub(unsigned x, unsigned toSub, unsigned alreadySubbed);
unsigned sub(unsigned x, unsigned toSub);

}

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
