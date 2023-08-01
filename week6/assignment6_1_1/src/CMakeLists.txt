add_library(exercise1 exercise1.cpp)
target_include_directories(exercise1 PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(exercise2 exercise2.cpp)
target_include_directories(exercise2 PUBLIC ${CMAKE_SOURCE_DIR}/include)
