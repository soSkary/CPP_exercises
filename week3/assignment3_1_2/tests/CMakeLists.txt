
add_executable(tests tests.cpp)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/external ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(tests PUBLIC weather weather_logs utility_functions)
