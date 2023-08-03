cmake_minimum_required(VERSION 3.24)

project(assignment8_3_1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(exec_name main)

option(USE_A_SAN "Use address sanitizer" OFF)

if (USE_A_SAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

add_compile_options(-Wall -Wextra -Wpedantic)

#add_executable( main.cpp)
#target_include_directories( PUBLIC /include)

add_subdirectory(tests)
