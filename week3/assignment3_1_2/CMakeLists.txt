
cmake_minimum_required(VERSION 3.24.2)
set(CMAKE_CXX_STANDARD 20)    
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(executable_name main)

project(assignment3_1_2)
    
add_executable(${executable_name} main.cpp)
    
add_subdirectory(src)
    
target_include_directories(${executable_name} PUBLIC /include)
    
target_link_libraries(${executable_name} PUBLIC utility_functions weather weather_logs)

add_subdirectory(tests)

