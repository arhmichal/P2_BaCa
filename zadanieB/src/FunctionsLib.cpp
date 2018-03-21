#include "FunctionsLib.hpp"

std::string Sum(const std::string& num1, const std::string& num2)
{
    std::cout << "DEBUG/ " << "return " << num1 << "+" << num2 << '\n';
    return num2; // TODO implement
}

std::string Sum(int numOfArgs, const std::string* args)
{
    std::string sum = "0";
    while((numOfArgs--) > 0)
        sum = Sum(sum, args[numOfArgs]);
    return sum;
}

std::string Sum(int numOfArgs, ...)
{
    std::string sum = "0";
    va_list args;
    va_start(args, numOfArgs);
    while((numOfArgs--) > 0)
        sum = Sum(sum, *va_arg(args, std::string*));
    va_end(args);
    return sum;
}

void Sum(std::string* ret, int numOfArgs, const std::string* args)
{
    *ret = Sum(numOfArgs, args);
}

void Sum(std::string* ret, int numOfArgs, ...)
{
    va_list args;
    va_start(args, numOfArgs);
    *ret = Sum(numOfArgs, args);
    va_end(args);
}

void Sum(std::string& ret, int numOfArgs, const std::string* args)
{
    ret = Sum(numOfArgs, args);
}

void Sum(std::string& ret, int numOfArgs, ...)
{
    va_list args;
    va_start(args, numOfArgs);
    ret = Sum(numOfArgs, args);
    va_end(args);
}


std::string Mult(const std::string& num1, const std::string& num2)
{
    std::cout << "DEBUG/ " << "return " << num1 << "+" << num2 << '\n';
    return num2; // TODO implement
}

std::string Mult(int numOfArgs, const std::string* args)
{
    std::string sum = "0";
    while((numOfArgs--) > 0)
        sum = Mult(sum, args[numOfArgs]);
    return sum;
}

std::string Mult(int numOfArgs, ...)
{
    std::string sum = "1";
    va_list args;
    va_start(args, numOfArgs);
    while((numOfArgs--) > 0)
        sum = Mult(sum, *va_arg(args, std::string*));
    va_end(args);
    return sum;
}

void Mult(std::string* ret, int numOfArgs, const std::string* args)
{
    *ret = Mult(numOfArgs, args);
}

void Mult(std::string* ret, int numOfArgs, ...)
{
    va_list args;
    va_start(args, numOfArgs);
    *ret = Mult(numOfArgs, args);
    va_end(args);
}

void Mult(std::string& ret, int numOfArgs, const std::string* args)
{
    ret = Mult(numOfArgs, args);
}

void Mult(std::string& ret, int numOfArgs, ...)
{
    va_list args;
    va_start(args, numOfArgs);
    ret = Mult(numOfArgs, args);
    va_end(args);
}


std::string Operation(std::string(*fun)(int, const std::string*), int numOfArgs, const std::string* args)
{
    return fun(numOfArgs, args);
}

std::string Operation(std::string(*fun)(int, const std::string*), int numOfArgs, ...)
{
}

void Operation(std::string* ret, std::string(*fun)(int, const std::string*), int numOfArgs, const std::string* args)
{
    *ret = fun(numOfArgs, args);
}

void Operation(std::string* ret, std::string(*fun)(int, const std::string*), int numOfArgs, ...)
{
}

void Operation(std::string& ret, void(*fun)(std::string*, int, const std::string*), int numOfArgs, const std::string* args)
{
    fun(&ret, numOfArgs, args);
}

void Operation(std::string& ret, void(*fun)(std::string*, int, const std::string*), int numOfArgs, ...)
{
    std::string* nextArg = NULL;
    va_list args;
    va_start(args, numOfArgs);
    while((numOfArgs--) > 0)
        nextArg = va_arg(args, std::string*);
    va_end(args);
}
