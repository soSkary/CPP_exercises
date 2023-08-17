cmake_minimum_required(VERSION 3.24)

project(assignment10_4_1 LANGUAGES CXX)

find_package(fmt)
find_package(nlohmann_json 3.2.0 REQUIRED)


add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)



include(FetchContent)

# Also requires one of: libbfd (gnu binutils), libdwarf, libdw (elfutils)
FetchContent_Declare(backward
GIT_REPOSITORY https://github.com/bombela/backward-cpp
GIT_TAG v1.6)
FetchContent_MakeAvailable(backward)

option(BACKWARD_ON "Toggle if Backward stack tracing is on" OFF)
if(BACKWARD_ON)
    add_executable(main main.cpp ${BACKWARD_ENABLE})
    target_link_libraries(main PUBLIC fmt::fmt)
    add_backward(main)
else()
    add_executable(main main.cpp)
    target_link_libraries(main PUBLIC fmt::fmt)
endif()

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
