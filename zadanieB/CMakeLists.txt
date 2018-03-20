project(ZadanieB_UT)

add_subdirectory(src)
include_directories(src)
include_directories(UT)

add_executable(ZadanieB_UT
        UT/EmptyTest.cpp
        )

target_link_libraries(ZadanieB_UT zadanieB gtest_main gtest gmock)
