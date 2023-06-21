
add_library(math_utils math_utils.cpp)
target_include_directories(math_utils PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(string_utils string_utils.cpp)
target_include_directories(string_utils PUBLIC ${CMAKE_SOURCE_DIR}/include)
