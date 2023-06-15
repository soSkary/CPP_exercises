/*
Exercise 1:

Write a simple C++ program that takes a file name as a command-line argument 
and prints the contents of the file to the console.
Make sure to handle errors, like if the file doesn't exist.
Use CMake to build your program.
*/
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "get_user_file.h"

namespace fs = std::filesystem;

void print_file_contents()
{
    
    std::cout << "Enter file path to open. We're currently at\n"
        << fs::current_path() << '\n';
    
    std::string file_path;
    std::getline(std::cin, file_path);

    std::ifstream file_input(file_path);

    //Check if opening of file not succesful
    if (!file_input)
    {
        std::cout << "\nCouldn't open the given file. Exiting function!\n";
        return;
    }
    //Reaffirm to user that file's been opened
    std::cout << "Opened file: " << file_path << '\n';

    //Loop through the file and print it out line by line
    std::string line;

    while (std::getline(file_input, line))
    {
        std::cout << line << '\n';
    }

    //Close file and reaffirm it to user
    file_input.close();
    std::cout << "\nClosed file: " << file_path << '\n';
}
