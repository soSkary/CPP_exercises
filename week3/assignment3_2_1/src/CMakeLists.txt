
set(my_library_name my_lib)

add_library(${my_library_name} PUBLIC )
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

