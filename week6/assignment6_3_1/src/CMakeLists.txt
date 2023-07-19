
set(my_library_name exercise1)

add_library(${my_library_name} ${my_library_name}.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(exercise2_3 exercise2_3.cpp)
target_include_directories(exercise2_3 PUBLIC ${CMAKE_SOURCE_DIR}/include)
