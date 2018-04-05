project(zadanieA)

add_library(zadanieA STATIC
        BitSetLib.hpp
        BitSetLib.cpp
        )

target_link_libraries(zadanieA logger)
