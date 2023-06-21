
set(my_library_name math_utils)

add_library(${my_library_name} math_utils.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

