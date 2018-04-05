#include "VariadicArgsUtils.hpp"

namespace VariadicArgsUtils
{

std::string* createNewStringArrayFromVariadicArguments(int numOfArgs, ...)
{
    std::string* args = new std::string[numOfArgs];
    int index = 0;

    va_list variadicArgs;
    va_start(variadicArgs, numOfArgs);
    while ((index) < numOfArgs)
        args[index++] = std::string(*va_arg(variadicArgs, std::string*));
    va_end(variadicArgs);
    return args;
}

}
