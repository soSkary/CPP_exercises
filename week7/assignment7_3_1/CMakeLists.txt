cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(assignment7_3_1)

add_compile_options(-Wall -Wextra -Wpedantic)

set(executable_name main)

add_executable(${executable_name} main.cpp)

target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
