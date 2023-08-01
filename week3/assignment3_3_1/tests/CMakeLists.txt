add_executable(test test_pascals_triangle.cpp)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/external)
target_link_libraries(test PUBLIC pascals_triangle)

