#include "modbus_device.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

std::vector<Modbus_device> create_modbus_group()
{
    static unsigned int id{ 0 };

    std::vector<Modbus_device> return_vector(11);
    return_vector.at(0) = { id++, true, { 0,0 } };

    unsigned int dummy_address{ 1 };
    unsigned int dummy_value{ 0 };
    for (auto it{ return_vector.begin() + 1 }; it != return_vector.end();++it)
    {
        *it = { id++, false, { dummy_address, dummy_value} };
        dummy_address += 1000;
        dummy_value += 500;
    }

    return return_vector;
}

void store_modbus_to_csv(const std::vector<Modbus_device>& data)
{
    //create a path to directory where to save device info
    fs::path storage_path{"modbus_device_storage/"};
    //check if folder exists already, and create it if not
    if (!fs::exists(storage_path))
    {
        fs::create_directory(storage_path);
    }
    //append filename to path
    storage_path /= "devices.csv";

    //check if file exists, and if not write the header row to file
    if (!fs::exists(storage_path))
    {
        std::ofstream file_output(storage_path, std::ios::out);
        if (!file_output)
        {
            std::cout << "Error! Couldn't create file, returning!\n";
            return;
        }
        file_output << "device_id,is_master\n";
        
    }

    //when file exists, open in append mode 
    std::ofstream file_output(storage_path, std::ios::app);
    if (!file_output)
    {
        std::cout << "Error! Couldn't open file for writing, returning!\n";
        return;
    }
    //Loop through the vector and write to file
    for (const auto& elem : data)
    {
        file_output << std::boolalpha << elem.m_id << ',' << elem.m_is_master << '\n';
    }
    //close file
    file_output.close();
    std::cout << "Saved data to file " << storage_path << " and closed file.\n";    
}

void store_slaves_to_csv(const std::vector<Modbus_device>& data)
{
    //create a path to directory where to save device info
    fs::path storage_path{"modbus_device_storage/"};
    //check if folder exists already, and create it if not
    if (!fs::exists(storage_path))
    {
        fs::create_directory(storage_path);
    }
    //append filename to path
    storage_path /= "registers.csv";

    //check if file exists, and if not write the header row to file
    if (!fs::exists(storage_path))
    {
        std::ofstream file_output(storage_path, std::ios::out);
        if (!file_output)
        {
            std::cout << "Error! Couldn't create file, returning!\n";
            return;
        }
        file_output << "device_id,register_adress,register_value\n";
        file_output.close();
        file_output.clear();

    }

    //when file exists, open in trunc mode for demo, as input is static
    std::ofstream file_output(storage_path, std::ios::app);
    if (!file_output)
    {
        std::cout << "Error! Couldn't open file for writing, returning!\n";
        return;
    }
    //Loop through the vector and write to file
    for (const auto& elem : data)
    {
        //if device is slave, write id, adress and value to file
        if (!elem.m_is_master)
        {
            file_output << std::boolalpha << elem.m_id << ','
                << elem.m_data_register.m_adress << ','
                << elem.m_data_register.m_value << '\n';
        }
    }
    //close file
    file_output.close();
    std::cout << "Saved data to file " << storage_path << " and closed file.\n";
}
