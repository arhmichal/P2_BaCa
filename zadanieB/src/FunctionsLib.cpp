#include "FunctionsLib.hpp"

std::string Sum(int numOfArgs, const std::string* args)
{
    return "";
}

std::string Sum(int numOfArgs, ...)
{
    return "";
}

void Sum(std::string* ret, int numOfArgs, const std::string* args)
{
}

void Sum(std::string* ret, int numOfArgs, ...)
{
}

void Sum(std::string& ret, int numOfArgs, const std::string* args)
{
}

void Sum(std::string& ret, int numOfArgs, ...)
{
}


std::string Mult(int numOfArgs, const std::string* args)
{
    return "";
}

std::string Mult(int numOfArgs, ...)
{
    return "";
}

void Mult(std::string* ret, int numOfArgs, const std::string* args)
{
}

void Mult(std::string* ret, int numOfArgs, ...)
{
}

void Mult(std::string& ret, int numOfArgs, const std::string* args)
{
}

void Mult(std::string& ret, int numOfArgs, ...)
{
}


std::string Operation(std::string(*)(int numOfArgs, const std::string* args), const std::string* args)
{
    return "";
}

std::string Operation(std::string(*)(int numOfArgs, const std::string* args), ...)
{
    return "";
}

void Operation(std::string* ret, std::string(*)(int numOfArgs, const std::string* args), const std::string* args)
{
}

void Operation(std::string* ret, std::string(*)(int numOfArgs, const std::string* args), ...)
{
}

void Operation(std::string& ret, std::string(*)(int numOfArgs, const std::string* args), const std::string* args)
{
}

void Operation(std::string& ret, std::string(*)(int numOfArgs, const std::string* args), ...)
{
}
