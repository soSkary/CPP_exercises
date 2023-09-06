cmake_minimum_required(VERSION 3.24)

project(assignment9_3_1 LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(main main.cpp)

add_subdirectory(tests)
