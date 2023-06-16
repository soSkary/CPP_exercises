#include "master_device.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

//Function to simulate the master device reading a a register from slave device.
void simulate_master_read(const std::string& device_id, const std::string& register_address)
{
    //Try to open the file
    std::ifstream file_input("modbus_device_storage/registers.csv");

    //Check if open was succesfull
    if (!file_input.is_open())
    {
        std::cout << "Couldn't open file modbus_device_storage/registers.csv ,returning to main.\n";
        return;
    }

    //variables for reading file line by line, and then word by word
    std::string id;
    std::string address;
    std::string value;
    
    
    //a check variable to end loop early, if value found
    bool value_recovered{ false };

    //here id is getting used only to dump the header of csv-file
    std::getline(file_input, id);
    
    //read file in a loop, word for word, delimited by a comma, comma and new line
    while (file_input.good())
    {
        std::getline(file_input, id, ',');
        std::getline(file_input, address, ',');
        std::getline(file_input, value);
       
        //check if given id and registry is found
        if (device_id == id && register_address == address)
        {
            std::cout << "The value at device id " << id << ", register " << address
                << ": " << value << '\n';
            value_recovered = true;
            break;
        }
    }
    if (!value_recovered)
    {
        std::cout << "Couldn't find device id " << device_id << ", register "
            << register_address << ".\n";
    }
}

void simulate_master_write(const std::string& device_id, const std::string& register_address, const std::string& new_value)
{
    //Try to open the file for reading
    std::ifstream file_read("modbus_device_storage/registers.csv", std::ios::in);

    //Ensure that open was succesfull
    if (!file_read.is_open())
    {
        std::cout << "Couldn't open file modbus_device_storage/registers.csv ,returning to main.\n";
        return;
    }

    //Variables for reading word by word, one line at a time
    std::string id;
    std::string address;
    std::string value;

    //String to store the modified data to be written to file, if id and registry is found
    std::string modified_stream;

    //Check variable to indicate, if value found
    bool value_recovered{ false };

    //get a line at time from registers.csv
    while (file_read.good())
    {
        std::getline(file_read, id, ',');
        std::getline(file_read, address, ',');
        std::getline(file_read, value);

        //to check if last line was the last of the file, check that id is not empty
        if (id.empty())
        {
            break;
        }
        //Check if given id and registry found, and if, modify the value to the new given value
        if (device_id == id && register_address == address)
        {
            std::cout << "The value at device id " << id << ", register " << address
                << ": " << value << " changed from initial to: " << new_value << '\n';
            value = new_value;
            value_recovered = true;
        }
        //append the whole line to the variable holding the modified string
        modified_stream += id + ',' + address + ',' + value + '\n';
    }
    if (!value_recovered)
    {
        std::cout << "Couldn't find device id " << device_id << ", register "
            << register_address << ".\n";
        return;
    }
    else
    {
        //If operation was succesful, close the instream, open an outstream
        //that truncates the existing contents
        file_read.close();
        std::ofstream file_write("modbus_device_storage/registers.csv", std::ios::trunc);

        //Write modified content to the file
        for (const auto& elem : modified_stream)
        {
            file_write << elem;
        }
        file_write.close();
    
    }
}


