cmake_minimum_required(VERSION 3.24)

project(assignment8_1_2)

set(exec_name main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${exec_name} main.cpp)
target_include_directories(${exec_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
