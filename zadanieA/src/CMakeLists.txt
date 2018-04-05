project(zadanieA)

include_directories(.)

add_library(zadanieA STATIC
        BitSetLib.hpp
        BitSetLib.cpp
        set/SetUtils.hpp
        set/SetUtils.cpp
        math/MathUtils.hpp
        math/MathUtils.cpp
        )

target_link_libraries(zadanieA logger)
