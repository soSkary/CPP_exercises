cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(assignment7_4_2)

set(executable_name main)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)

add_executable(${executable_name} main.cpp)
target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${executable_name} PUBLIC text_box)

