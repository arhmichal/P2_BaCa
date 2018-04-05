project(ZadanieA_UT)

add_subdirectory(src)
include_directories(src)
include_directories(UT)

add_executable(ZadanieA_UT
        UT/CommonValues.hpp
        UT/ComparationTest.cpp
        UT/ElementOperationsTest.cpp
        UT/MathTest.cpp
        UT/OrderTest.cpp
        UT/PrintTest.cpp
        UT/SetArythmeticsTest.cpp
        UT/SetCreationTest.cpp
        UT/SetTest.cpp
        )

target_link_libraries(ZadanieA_UT zadanieA gtest_main gtest gmock)
