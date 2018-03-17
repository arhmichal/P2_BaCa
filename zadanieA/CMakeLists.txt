project(ZadanieA_UT)

add_subdirectory(src)
include_directories(src)
include_directories(UT)

add_executable(ZadanieA_UT
        #        UT/otherTests.cpp
        UT/OrderTest.cpp
        UT/SetArythmeticsTest.cpp
        UT/ComparationTest.cpp
        UT/SetCreationTest.cpp
        UT/ElementOperationsTest.cpp
        UT/PrintTest.cpp
        UT/CommonValues.hpp
        )

target_link_libraries(ZadanieA_UT zadanieA gtest_main gtest gmock)
