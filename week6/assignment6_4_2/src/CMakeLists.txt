add_library(object object.cpp)
target_include_directories(object PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(c_file_functionality c_file_functionality.cpp)
target_include_directories(c_file_functionality PUBLIC ${CMAKE_SOURCE_DIR}/include)
