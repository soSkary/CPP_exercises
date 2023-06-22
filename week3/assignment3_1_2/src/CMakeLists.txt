add_library(weather weather.cpp)
target_include_directories(weather PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(weather_logs weather_logs.cpp)
target_include_directories(weather_logs PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(utility_functions utility_functions.cpp)
target_include_directories(utility_functions PUBLIC ${CMAKE_SOURCE_DIR}/include)
