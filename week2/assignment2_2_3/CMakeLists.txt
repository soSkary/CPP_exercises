cmake_minimum_required(VERSION 3.22)

project(2D_board_game)

add_executable(game main.cpp)



add_subdirectory(libs)

target_include_directories(game PUBLIC includes libs)

target_link_libraries(game board)
