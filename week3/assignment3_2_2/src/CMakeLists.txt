add_library(player_functions STATIC player_functions.cpp)
target_include_directories(player_functions PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(ai_functions STATIC ai_functions.cpp)
target_include_directories(ai_functions PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(game_functions STATIC game_functions.cpp)
target_include_directories(game_functions PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(board STATIC board.cpp)
target_include_directories(board PUBLIC ${CMAKE_SOURCE_DIR}/include)
