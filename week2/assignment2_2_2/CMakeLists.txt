cmake_minimum_required(VERSION 3.24.2)
    
    project(assignment2_2_2)
    
    set(Executable_name main)
    add_executable(${Executable_name} main.cpp)
    
    add_subdirectory(src)
    add_subdirectory(externals/cxxopts)
    
    target_include_directories(${Executable_name} PUBLIC includes externals/cxxopts/include)
    
    target_link_libraries(${Executable_name} PUBLIC cxxopts math_operations caesar_cipher)
    
