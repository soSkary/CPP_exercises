
set(my_library_name vector_3d)

add_library(${my_library_name} vector_3d.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

