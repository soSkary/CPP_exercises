#include "c_file_functionality.hpp"

#include <iostream>

c_file_functionality::c_file_functionality(const std::string& user_file_name)
: file_name{user_file_name}
{
    file_handle = std::fopen(user_file_name.c_str(), "r");
    if (!file_handle)
    {
        std::perror("Failed to open file!");
    }
    else
    {
        std::cout << "Opened file " << file_name << " in the constructor.\n";
    }
}

c_file_functionality::~c_file_functionality()
{
    fclose(file_handle);
    std::cout << "Closed file " << file_name << " in the destructor.\n";
}

void c_file_functionality::read_next_line_of_file()
{
    std::string text_line;
    //we want an integer to handle EOF
    int symbol;

    while ((symbol = std::fgetc(file_handle)) != EOF)
    {
        if (symbol == '\n')
        {
            break;
        }
        text_line.push_back(static_cast<char>(symbol));
    }
    std::cout << text_line << '\n';
}

uint32_t c_file_functionality::check_file_size()
{
    //A variable for the current position, to store, so we can set it back after checking file size
    fpos_t current_position;
    std::fgetpos(file_handle, &current_position);

    //Seek to the end of the file
    std::fseek(file_handle, 0, SEEK_END);
    //Return the positon in bits
    uint32_t file_size = std::ftell(file_handle);

    std::fsetpos(file_handle, &current_position);

    return file_size;
}
