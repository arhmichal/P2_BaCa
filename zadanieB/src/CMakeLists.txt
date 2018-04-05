project(zadanieB)

add_library(zadanieB STATIC
        FunctionsLib.hpp
        FunctionsLib.cpp
        VariadicArgsUtils.hpp
        VariadicArgsUtils.cpp
        MyMathOnStrings/Utils.hpp
        MyMathOnStrings/Utils.cpp
        MyMathOnStrings/Addition.hpp
        MyMathOnStrings/Addition.cpp
        MyMathOnStrings/Multiplication.hpp
        MyMathOnStrings/Multiplication.cpp
        )

target_link_libraries(zadanieB logger)
