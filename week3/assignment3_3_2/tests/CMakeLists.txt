
add_executable(tests tests.cpp)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/external/include ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(tests PUBLIC math_utils string_utils)
