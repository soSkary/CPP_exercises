#ifndef MODBUS_DEVICE_H
#define MODBUS_DEVICE_H

#include <vector>

struct Data_register
{
    unsigned int m_adress{};
    unsigned int m_value{};
};

struct Modbus_device
{
    unsigned int m_id{};
    bool m_is_master{};

    Data_register m_data_register{};
};

std::vector<Modbus_device> create_modbus_group();
void store_modbus_to_csv(const std::vector<Modbus_device>& data);
void store_slaves_to_csv(const std::vector<Modbus_device>& data);
#endif //MODBUS_DEVICE_H
