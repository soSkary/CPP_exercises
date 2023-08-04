add_executable(tests tests.cpp)
target_link_libraries(tests PUBLIC memerror1 memerror2 memerror3)
target_include_directories(tests PUBLIC doctest ${CMAKE_SOURCE_DIR}/include)
