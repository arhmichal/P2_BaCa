#pragma once

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
