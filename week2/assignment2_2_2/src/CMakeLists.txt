add_library(math_operations math_operations.cpp)
target_include_directories(math_operations PUBLIC ${CMAKE_SOURCE_DIR}/includes)


add_library(caesar_cipher caesar_cipher.cpp)
target_include_directories(caesar_cipher PUBLIC ${CMAKE_SOURCE_DIR}/includes)
