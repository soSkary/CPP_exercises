cmake_minimum_required(VERSION 3.24)

project(assignment8_4_1 LANGUAGES CXX)

option(USE_G++ "Use g++ as compiler" OFF)
option(USE_A_SAN "Use address sanitizer" OFF)
option(USE_M_SAN "Use memory sanitizer" OFF)

#Choose which compiler g++ or clang++
if (USE_G++)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
else()
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
endif()

#Address sanitizer
if (USE_A_SAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

#Memory sanitizer, doesn't work on g++
if (USE_M_SAN AND NOT USE_G++)
    add_compile_options(-fsanitize=memory)
    add_link_options(-fsanitize=memory)
endif()


add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(memerror1 memerror1.cpp)
add_library(memerror2 memerror2.cpp)
add_library(memerror3 memerror3.cpp)

add_subdirectory(tests)

include_directories(${CMAKE_SOURCE_DIR}/include)


