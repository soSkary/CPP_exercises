add_library(get_user_file get_user_file.cpp)
target_include_directories(get_user_file PUBLIC ${CMAKE_SOURCE_DIR}/includes)

add_library(dir_text_size dir_text_size.cpp)
target_include_directories(dir_text_size PUBLIC ${CMAKE_SOURCE_DIR}/includes)
