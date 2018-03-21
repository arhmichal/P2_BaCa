#include <iostream>
#include <string>
#include <cstdarg>

std::string Sum(int numOfArgs, const std::string* args);
std::string Sum(int numOfArgs, ...);
void Sum(std::string* ret, int numOfArgs, const std::string* args);
void Sum(std::string* ret, int numOfArgs, ...);
void Sum(std::string& ret, int numOfArgs, const std::string* args);
void Sum(std::string& ret, int numOfArgs, ...);

std::string Mult(int numOfArgs, const std::string* args);
std::string Mult(int numOfArgs, ...);
void Mult(std::string* ret, int numOfArgs, const std::string* args);
void Mult(std::string* ret, int numOfArgs, ...);
void Mult(std::string& ret, int numOfArgs, const std::string* args);
void Mult(std::string& ret, int numOfArgs, ...);

std::string Operation(std::string(*fun)(int, const std::string*), int numOfArgs, const std::string* args);
std::string Operation(std::string(*fun)(int, const std::string*), int numOfArgs, ...);
void Operation(std::string* ret, std::string(*fun)(int, const std::string*), int numOfArgs, const std::string* args);
void Operation(std::string* ret, std::string(*fun)(int, const std::string*), int numOfArgs, ...);
void Operation(std::string& ret, void(*fun)(std::string*, int, const std::string*), int numOfArgs, const std::string* args);
void Operation(std::string& ret, void(*fun)(std::string*, int, const std::string*), int numOfArgs, ...);
