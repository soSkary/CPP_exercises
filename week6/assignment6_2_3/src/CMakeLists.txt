
set(my_library_name object)

add_library(${my_library_name} object.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

