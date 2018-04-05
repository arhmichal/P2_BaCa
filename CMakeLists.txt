cmake_minimum_required(VERSION 3.10)
project(BaCa_P2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(logger)
include_directories(logger)

add_subdirectory(googletest)
add_subdirectory(BaCa_P2)
