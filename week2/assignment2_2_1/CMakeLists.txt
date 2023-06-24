cmake_minimum_required(VERSION 3.24)

project(fuudoora    VERSION 099
                    DESCRIPTION "A food service program"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Creates an executable, but also defines a target
add_executable(${PROJECT_NAME} main.cpp)

#add a subdirectory containing it's own CMakeLists.txt and source files
add_subdirectory(utilities)

#Here I tell that the target ${PROJECT_NAME} will find #includes in path utilities
target_include_directories(${PROJECT_NAME} PUBLIC utilities)
#Here I tell which libaries to link with target ${PROJECT_NAME}
target_link_libraries(${PROJECT_NAME} PUBLIC food_utilities)


