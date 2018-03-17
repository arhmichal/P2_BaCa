#include "BitSetLib.hpp"

namespace math {

bool odd(unsigned x);

unsigned addOne(unsigned x);
unsigned add(unsigned x, unsigned toAdd, unsigned alreadyAdded);
unsigned add(unsigned x, unsigned toAdd);

unsigned subOne(unsigned x);
unsigned sub(unsigned x, unsigned toSub, unsigned alreadySubbed);
unsigned sub(unsigned x, unsigned toSub);

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

} using namespace math;

namespace set {

const unsigned invert(unsigned set1);
const unsigned sum(unsigned set1, unsigned set2);
const unsigned intersect(unsigned set1, unsigned set2);
const unsigned symmetricDifference(unsigned set1, unsigned set2);
const unsigned difference(unsigned set1, unsigned set2);
const unsigned setSize(unsigned set);
int push_back(int& out, char charValue);

const unsigned invert(const unsigned set1)
{
    return set1 ^ 0b11111u; // TODO length dependency
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

const unsigned setSize(const unsigned set) // TODO length dependency
{
    unsigned size = 0;
    if (set&0b10000u) size = addOne(size);
    if (set&0b1000u) size = addOne(size);
    if (set&0b100u) size = addOne(size);
    if (set&0b10u) size = addOne(size);
    if (set&0b1u) size = addOne(size);
    return size;
}

int push_back(int& out, const char charValue)
{
    int num = charValue == '0' ? 0 : 1;
    out = (out << 1) | num;
    return out;
}

} using namespace set;

// LIB ===========================================================

/*
    implementacja operacji na zbiorach 5-elementowych {0,1} jako INT'ów
    nie można urzywać:
    - operator[] i równowarznych
    - słów kluczowych pętli FOR, WHILE, GOTO
    - rekordów <?> czyli CLASS, STRUCT
    - operator+ operator-
    - poleceń obsługi pamięci dynamicznej <?>
    - typów własnych zmiennych innych niż INT
    - własnych identyfikatorów <?> zaczynających się od '_'
    - kontenerów i szablonów

    porządek zbiorów:
    - większa liczność > mniejsza liczność
    - warzniejszy bit > mniej warzny

    inne obostrzenia
    - nie można includować czegoś innego niż IOSTREAM, STRING, SSTREAM
    - String mogą urzywać tylko Emplace, Insert, Erase, Print, Member
    - na String można wołać tylko .at() i .length()
    - Sstream może być urzyte tylko przez Print
    - na Sstream można wołać tylko .str()
    - wszystko zakodzić w pliku .cpp
    - w pierwszej linii 'nagłówek" czyli komentarz z imieniem i nazwiskiem autora
*/

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
    push_back(*out, in.at(0));
    push_back(*out, in.at(1));
    push_back(*out, in.at(2));
    push_back(*out, in.at(3));
    push_back(*out, in.at(4));
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
    stackDepth = addOne(stackDepth);

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
        std::string last = odd(set) ? "1" : "0";
        set = set >> 1;

        Print(set, out);

        std::stringstream ss;
        ss << *out << last << (stackDepth == 1u ? " " : "");
        *out = ss.str();
    }

    stackDepth = subOne(stackDepth);
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
    return Equality(intersect(set1, set2), 0b0);
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
    return Equality(intersect(subset, superset), subset);
}

//suma zbiorów
void Union(int set1, int set2, int* out)
{
    *out = sum(set1, set2);
}

//przecięcie zbiorów
void Intersection(int set1, int set2, int* out)
{
    *out = intersect(set1, set2);
}

//różnica symetryczna = (A-B) + (B-A)
void Symmetric(int set1, int set2, int* out)
{
    *out = symmetricDifference(set1, set2);
}

//różnica zbiorów = A - B
void Difference(int set1, int set2, int* out)
{
    *out = difference(set1, set2);
}

//dopełnienie zbioru
void Complement(int set, int* out)
{
    *out = invert(set);
}

bool LessThen(int set1, int set2)
{
    if (setSize(set1) != setSize(set2))
        return setSize(set1) < setSize(set2);
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
