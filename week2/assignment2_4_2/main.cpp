/*
A simple program simulating getting Modbus device data and saving it to a file.
Searching through the data to find a specific registry, and modifying a value in
a specific registry.
*/


#include "master_device.h"
#include "modbus_device.h"

#include <iostream>

int main()
{

    std::vector<Modbus_device> modbus_devices{create_modbus_group()};

    store_modbus_to_csv(modbus_devices);

    store_slaves_to_csv(modbus_devices);

    simulate_master_read("9", "8001");

    simulate_master_write("1", "1", "4111");

}
