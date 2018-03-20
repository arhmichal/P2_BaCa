#include "FunctionsLib.hpp"

std::string Sum(int noOfArgs, const std::string* args)
{
    std::cout << "DEBUG/ called Sum(" << noOfArgs << ", " << *args << ");\n";
    return "";
}

std::string Sum(int noOfArgs, ...)
{
    std::cout << "DEBUG/ called Sum(" << noOfArgs << ", ... );\n";
    va_list args;
    va_start(args, noOfArgs);
    va_end(args);
    return "";
}

void Sum(std::string* ret, int noOfArgs, const std::string* args)
{
    std::cout << "DEBUG/ called Sum(*ret, " << noOfArgs << ", " << *args << ");\n";
    *ret = Sum(noOfArgs, args);
}

void Sum(std::string* ret, int noOfArgs, ...)
{
    std::cout << "DEBUG/ called Sum(*ret, " << noOfArgs << ", ... );\n";
    va_list args;
    va_start(args, noOfArgs);
    *ret = Sum(noOfArgs, args);
    va_end(args);
}

void Sum(std::string& ret, int noOfArgs, const std::string* args)
{
    std::cout << "DEBUG/ called Sum(&ret, " << noOfArgs << ", " << *args << ");\n";
    ret = Sum(noOfArgs, args);
}

void Sum(std::string& ret, int noOfArgs, ...)
{
    std::cout << "DEBUG/ called Sum(&ret, " << noOfArgs << ", ... );\n";
    va_list args;
    va_start(args, noOfArgs);
    ret = Sum(noOfArgs, args);
    va_end(args);
}


std::string Mult(int, const std::string*)
{
    return "";
}

std::string Mult(int, ...)
{
    return "";
}

void Mult(std::string*, int, const std::string*)
{
}

void Mult(std::string*, int, ...)
{
}

void Mult(std::string&, int, const std::string*)
{
}

void Mult(std::string&, int, ...)
{
}


std::string Operation(std::string(*)(int, const std::string*), const std::string*)
{
    return "";
}

std::string Operation(std::string(*)(int, const std::string*), ...)
{
    return "";
}

void Operation(std::string*, std::string(*)(int, const std::string*), const std::string*)
{
}

void Operation(std::string*, std::string(*)(int, const std::string*), ...)
{
}

void Operation(std::string&, std::string(*)(int, const std::string*), const std::string*)
{
}

void Operation(std::string&, std::string(*)(int, const std::string*), ...)
{
}
