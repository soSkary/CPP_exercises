add_library(modbus_device modbus_device.cpp)
target_include_directories(modbus_device PUBLIC ${CMAKE_SOURCE_DIR}/includes)

add_library(master_device master_device.cpp)
target_include_directories(master_device PUBLIC ${CMAKE_SOURCE_DIR}/includes)
