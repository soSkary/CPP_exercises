cmake_minimum_required(VERSION 3.22)

project(assignment2_4_1)

set(Executable_name main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${Executable_name} main.cpp)

add_subdirectory(src)
add_subdirectory(cxxopts)

target_link_libraries(${Executable_name} get_user_file cxxopts dir_text_size)

target_include_directories(${Executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/includes ${CMAKE_SOURCE_DIR}/cxxopts/include)
