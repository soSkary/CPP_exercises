
set(my_library_name figure)

add_library(${my_library_name} figure.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

