
cmake_minimum_required(VERSION 3.24.2)
set(CMAKE_CXX_STANDARD 20)    
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(executable_name main)

project(assignment6_1_2)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${executable_name} main.cpp)
    
add_subdirectory(src)
    
target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    
target_link_libraries(${executable_name} PUBLIC figure)

#add_subdirectory(tests)

