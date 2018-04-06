project(zadanieB)

include_directories(.)

add_library(zadanieB STATIC
        FunctionsLib.hpp
        FunctionsLib.cpp
        VariadicArgsUtils.hpp
        VariadicArgsUtils.cpp
        MathOnStrings/Utils.hpp
        MathOnStrings/Utils.cpp

        MathOnStrings/Add.hpp
        MathOnStrings/Add.cpp
        )

target_link_libraries(zadanieB logger)
