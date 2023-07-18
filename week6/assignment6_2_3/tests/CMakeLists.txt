
add_executable(tests tests.cpp)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/external/include)

