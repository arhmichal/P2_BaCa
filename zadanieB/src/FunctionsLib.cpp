#include "FunctionsLib.hpp"

std::string Sum(int, const std::string*)
{
    return "";
}

std::string Sum(int, ...)
{
    return "";
}

void Sum(std::string*, int, const std::string*)
{
    return;
}

void Sum(std::string*, int, ...)
{
    return;
}

void Sum(std::string&, int, const std::string*)
{
    return;
}

void Sum(std::string&, int, ...)
{
    return;
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
    return;
}

void Mult(std::string*, int, ...)
{
    return;
}

void Mult(std::string&, int, const std::string*)
{
    return;
}

void Mult(std::string&, int, ...)
{
    return;
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
    return;
}

void Operation(std::string*, std::string(*)(int, const std::string*), ...)
{
    return;
}

void Operation(std::string&, std::string(*)(int, const std::string*), const std::string*)
{
    return;
}

void Operation(std::string&, std::string(*)(int, const std::string*), ...)
{
    return;
}
