cmake_minimum_required(VERSION 3.24)

project(fuudoora    VERSION 0.01
                    DESCRIPTION "A food service program"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(utilities)
target_include_directories(utilities PUBLIC include)



