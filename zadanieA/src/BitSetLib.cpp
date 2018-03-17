#include "BitSetLib.hpp"

// string jest formatu "\s*[01]{5}\s*", przekonwertuj do inta
void Emplace(std::string in, int* out)
{
    return;
}

// string jest formatu "\s*[01]{5}\s*", przekonwertuj do inta i dopisz do podanego inta
void Insert(std::string in, int* out)
{
    return;
}

//str to be removed from int*
void Erase(std::string in, int* out)
{
    return;
}

//int przepisz do str jako bity, spacja na końcu, "zbiór pusty jest opisany sowem "empty""
void Print(int set, std::string* out)
{
    return;
}

//return isEmpty(set)
bool Emptiness(int set)
{
    return false;
}

//return not isEmpty(set)
bool Nonempty(int set)
{
    return false;
}

//return set.contains(element)
bool Member(std::string element, int set)
{
    return false;
}

//zwruć czy zbiory są rozłączne
bool Disjoint(int set1, int set2)
{
    return false;
}

//czy przecięcie jest niepuste - czy nie-rozłączne
bool Conjunctive(int set1, int set2)
{
    return false;
}

//return set1==set2
bool Equality(int set1, int set2)
{
    return false;
}

//return subset jest podzbiorem superset'u
bool Inclusion(int subset, int superset)
{
    return false;
}

//suma zbiorów
void Union(int set1, int set2, int* out)
{
    return;
}

//przecięcie zbiorów
void Intersection(int set1, int set2, int* out)
{
    return;
}

//różnica symetryczna = (A-B) + (B-A)
void Symmetric(int set1, int set2, int* out)
{
    return;
}

//różnica zbiorów = A - B
void Difference(int set1, int set2, int* out)
{
    return;
}

//dopełnienie zbioru
void Complement(int set, int* out)
{
    return;
}

bool LessThen(int set1, int set2)
{
    return false;
}

bool LessEqual(int set1, int set2)
{
    return false;
}

bool GreatEqual(int set1, int set2)
{
    return false;
}

bool GreatThen(int set1, int set2)
{
    return false;
}
