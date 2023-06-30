cmake_minimum_required(VERSION 3.22)

project(assignment2_3_1)

add_subdirectory(exercise1)
add_subdirectory(exercise2)
add_subdirectory(exercise3)
add_subdirectory(exercise4)
add_subdirectory(exercise5)
add_subdirectory(exercise6)
add_subdirectory(exercise7)

add_executable(${PROJECT_NAME} main.cpp exercises.h)

target_link_libraries(${PROJECT_NAME} exercise1 exercise2 exercise3 exercise4 exercise5 exercise6 exercise7)
