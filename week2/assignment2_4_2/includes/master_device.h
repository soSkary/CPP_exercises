#ifndef MASTER_DEVICE_H
#define MASTER_DEVICE_H

#include <string>

void simulate_master_read(const std::string& device_id, const std::string& register_address);
void simulate_master_write(const std::string& device_id, const std::string& register_address, const std::string& new_value);

#endif
