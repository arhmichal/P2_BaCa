#include <FunctionsLib.hpp>
#include <MathOnStrings/Add.hpp>

using namespace VariadicArgsUtils;
using namespace MathOnStrings;

std::string Sum(int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "(int numOfArgs, const std::string* args)";
    std::string ret = "0";
    while ((numOfArgs--) > 0)
        ret = add(ret, args[numOfArgs]);
    return ret;
}

std::string Sum(int numOfArgs, ...)
{
    ARHLOG_DBG<< "int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    std::string ret = Sum(numOfArgs, args);

    delete[] args;
    return ret;
}

void Sum(std::string* ret, int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "std::string* ret, int numOfArgs, const std::string* args)";
    *ret = Sum(numOfArgs, args);
}

void Sum(std::string* ret, int numOfArgs, ...)
{
    ARHLOG_DBG<< "std::string* ret, int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Sum(ret, numOfArgs, args);

    delete[] args;
}

void Sum(std::string& ret, int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "std::string& ret, int numOfArgs, const std::string* args)";
    ret = Sum(numOfArgs, args);
}

void Sum(std::string& ret, int numOfArgs, ...)
{
    ARHLOG_DBG<< "std::string& ret, int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Sum(ret, numOfArgs, args);

    delete[] args;
}





std::string Mult(int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "int numOfArgs, const std::string* args)";
    std::string ret = "0";
//    while ((numOfArgs--) > 0)
//        ret = mult(ret, args[numOfArgs]);
    return ret;
}

std::string Mult(int numOfArgs, ...)
{
    ARHLOG_DBG<< "int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    std::string ret = Mult(numOfArgs, args);

    delete[] args;
    return ret;
}

void Mult(std::string* ret, int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "std::string* ret, int numOfArgs, const std::string* args)";
    *ret = Mult(numOfArgs, args);
}

void Mult(std::string* ret, int numOfArgs, ...)
{
    ARHLOG_DBG<< "std::string* ret, int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Mult(ret, numOfArgs, args);

    delete[] args;
}

void Mult(std::string& ret, int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "std::string& ret, int numOfArgs, const std::string* args)";
    ret = Mult(numOfArgs, args);
}

void Mult(std::string& ret, int numOfArgs, ...)
{
    ARHLOG_DBG<< "std::string& ret, int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Mult(ret, numOfArgs, args);

    delete[] args;
}





std::string Operation(std::string(* fun)(int, const std::string*), int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "(std::string(* fun)(int, const std::string*), int numOfArgs, const std::string* args)";
    return fun(numOfArgs, args);
}

std::string Operation(std::string(* fun)(int, const std::string*), int numOfArgs, ...)
{
    ARHLOG_DBG<< "(std::string(* fun)(int, const std::string*), int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    std::string ret = Operation(fun, numOfArgs, args);

    delete[] args;
    return ret;
}

void Operation(std::string* ret, std::string(* fun)(int, const std::string*), int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "(std::string* ret, std::string(* fun)(int, const std::string*), int numOfArgs, const std::string* args)";
    *ret = fun(numOfArgs, args);
}

void Operation(std::string* ret, std::string(* fun)(int, const std::string*), int numOfArgs, ...)
{
    ARHLOG_DBG<< "(std::string* ret, std::string(* fun)(int, const std::string*), int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Operation(ret, fun, numOfArgs, args);

    delete[] args;
}

void Operation(std::string& ret, void(* fun)(std::string*, int, const std::string*), int numOfArgs, const std::string* args)
{
    ARHLOG_DBG<< "(std::string& ret, void(* fun)(std::string*, int, const std::string*), int numOfArgs, const std::string* args)";
    fun(&ret, numOfArgs, args);
}

void Operation(std::string& ret, void(* fun)(std::string*, int, const std::string*), int numOfArgs, ...)
{
    ARHLOG_DBG<< "(std::string& ret, void(* fun)(std::string*, int, const std::string*), int numOfArgs, ...)";

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    std::string* args = createNewStringArrayFromVariadicArguments(numOfArgs, variadicArgs);

    Operation(ret, fun, numOfArgs, args);

    delete[] args;
}
