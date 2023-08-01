cmake_minimum_required(VERSION 3.24.2)
    
    project(assignment2_4_2)
    
    set(Executable_name main)

    add_executable(${Executable_name} main.cpp)
    
    add_subdirectory(src)
    
    target_include_directories(${Executable_name} PUBLIC includes)
    
    target_link_libraries(${Executable_name} PUBLIC modbus_device master_device)
