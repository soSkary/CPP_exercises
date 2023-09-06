
cmake_minimum_required(VERSION 3.24.2)
set(CMAKE_CXX_STANDARD 20)    
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(executable_name main)

project(assignment7_4_1)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${executable_name} main.cpp)
    
