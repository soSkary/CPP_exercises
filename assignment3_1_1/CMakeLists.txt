cmake_minimum_required(VERSION 3.24.2)
    
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(assignment3_1_1)
    
add_executable(${PROJECT_NAME} main.cpp)
    
add_subdirectory(src)
add_subdirectory(banking_application)
    
target_include_directories(${PROJECT_NAME} PUBLIC includes banking_application/include)
    
target_link_libraries(${PROJECT_NAME} PUBLIC utils banking_application)
    
