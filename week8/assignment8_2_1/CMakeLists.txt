cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(assignment8_2_1)
set(exec_name main)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${exec_name} main.cpp)

