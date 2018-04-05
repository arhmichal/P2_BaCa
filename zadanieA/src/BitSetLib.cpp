#include "BitSetLib.hpp"
#include "set/SetUtils.hpp"
#include "math/MathUtils.hpp"

// string jest formatu "\s*[01]{5}\s*", przekonwertuj do inta
void Emplace(std::string in, int* out) // TODO length dependency
{
    if (in.length() == 0)
        return;
    if (not isalnum(in.at(0)))
    {
        if (in.length() > 1)
            Emplace(std::string(&in.at(1)), out);
        return;
    }
    if (in.length() < 5)
        return;
    *out = 0;
    set::push_back(*out, in.at(0));
    set::push_back(*out, in.at(1));
    set::push_back(*out, in.at(2));
    set::push_back(*out, in.at(3));
    set::push_back(*out, in.at(4));
}

// string jest formatu "\s*[01]{5}\s*", przekonwertuj do inta i dopisz do podanego inta
void Insert(std::string in, int* out)
{
    if (in.length() == 0)
        return;
    if (not isalnum(in.at(0)))
    {
        if (in.length() > 1)
            Insert(std::string(&in.at(1)), out);
        return;
    }
    if (in.length() < 5)
        return;

    int addingSet = 0;
    Emplace(in, &addingSet);
    Union(addingSet, *out, out);

    if (in.length() > 5)
        Insert(std::string(&in.at(5)), out);
}

//str to be removed from int*
void Erase(std::string in, int* out)
{
    if (in.length() == 0)
        return;
    if (not isalnum(in.at(0)))
    {
        if (in.length() > 1)
            Erase(std::string(&in.at(1)), out);
        return;
    }
    if (in.length() < 5)
        return;

    int toRemove = 0;
    Emplace(in, &toRemove);
    Difference(*out, toRemove, out);

    if (in.length() > 5)
        Erase(std::string(&in.at(5)), out);
}

//int przepisz do str jako bity, spacja na końcu, "zbiór pusty jest opisany sowem "empty""
void Print(int set, std::string* out)
{
    static unsigned stackDepth = 0;
    stackDepth = math::addOne(stackDepth);

    if (stackDepth == 1u)
        *out = "";

    if (Emptiness(set) && (stackDepth == 1u))
    {
        *out = "empty ";
    }
    else if (stackDepth > 5u)
    {
        *out = "";
    }
    else // if (Nonempty(set))
    {
        std::string last = math::odd(set) ? "1" : "0";
        set = set >> 1;

        Print(set, out);

        std::stringstream ss;
        ss << *out << last << (stackDepth == 1u ? " " : "");
        *out = ss.str();
    }

    stackDepth = math::subOne(stackDepth);
}

//return isEmpty(set)
bool Emptiness(int set)
{
    return Equality(set, 0b0);
}

//return not isEmpty(set)
bool Nonempty(int set)
{
    return not Emptiness(set);
}

//return set.contains(element)
bool Member(std::string element, int set)
{
    int e = 0;
    Emplace(element, &e);
    return Inclusion(e, set);
}

//zwruć czy zbiory są rozłączne
bool Disjoint(int set1, int set2)
{
    return Equality(set::intersect(set1, set2), 0b0);
}

//czy przecięcie jest niepuste - czy nie-rozłączne
bool Conjunctive(int set1, int set2)
{
    return not Disjoint(set1, set2);
}

//return set1==set2
bool Equality(int set1, int set2)
{
    return set1 == set2;
}

//return subset jest podzbiorem superset'u
bool Inclusion(int subset, int superset)
{
    return Equality(set::intersect(subset, superset), subset);
}

//suma zbiorów
void Union(int set1, int set2, int* out)
{
    *out = set::sum(set1, set2);
}

//przecięcie zbiorów
void Intersection(int set1, int set2, int* out)
{
    *out = set::intersect(set1, set2);
}

//różnica symetryczna = (A-B) + (B-A)
void Symmetric(int set1, int set2, int* out)
{
    *out = set::symmetricDifference(set1, set2);
}

//różnica zbiorów = A - B
void Difference(int set1, int set2, int* out)
{
    *out = set::difference(set1, set2);
}

//dopełnienie zbioru
void Complement(int set, int* out)
{
    *out = set::invert(set);
}

bool LessThen(int set1, int set2)
{
    if (set::setSize(set1) != set::setSize(set2))
        return set::setSize(set1) < set::setSize(set2);
    return set1 < set2;
}

bool LessEqual(int set1, int set2)
{
    if (Equality(set1, set2))
        return true;
    return LessThen(set1, set2);
}

bool GreatEqual(int set1, int set2)
{
    if (Equality(set1, set2))
        return true;
    return GreatThen(set1, set2);
}

bool GreatThen(int set1, int set2)
{
    return not LessEqual(set1, set2);
}
