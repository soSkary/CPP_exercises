
set(my_library_name exercises)

add_library(${my_library_name} exercises.cpp)
target_include_directories(${my_library_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

