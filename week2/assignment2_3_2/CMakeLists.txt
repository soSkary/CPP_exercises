cmake_minimum_required(VERSION 3.22)

project(industrial_sensors)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(ExecutableName main)

add_executable(${ExecutableName} main.cpp)

add_subdirectory(src)

target_include_directories(${ExecutableName} PUBLIC includes)
target_link_libraries(${ExecutableName} PUBLIC sensor_data)
