/*
Exercise 1:

Write a simple C++ program that takes a file name as a command-line argument 
and prints the contents of the file to the console.
Make sure to handle errors, like if the file doesn't exist.
Use CMake to build your program.
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "file_io.h"



void print_file_contents(const std::string& file_path, const bool lines,const bool words, const bool characters)
{
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
    unsigned int line_count{ 0 };
    unsigned int word_count{ 0 };
    unsigned int character_count{ 0 };

    while (std::getline(file_input, line))
    {
        //Check if we wan't to count the lines, or output file
        if (lines)
        {
            ++line_count;
        }
        //Check if we wan't to count characters or words
        if (words || characters)
        {
            //Create a stringstream, so we can loop through the lines word for word
            std::stringstream stream_dump{line};
            std::string line_dump;
            //Loop word for word and count characters and words (not spaces)
            while (stream_dump >> line_dump)
            {
                ++word_count;
                character_count += line_dump.size();
            }
        }
        else
        {
            std::cout << line << '\n';
        }
    }
    if (lines)
    {
        std::cout << "\nThe file " << file_path << " contains "
            << line_count << " lines.\n";
    }
    if (words)
    {
        std::cout << "\nThe file " << file_path << " contains "
            << word_count << " words.\n";
    }
    if (characters)
    {
        std::cout << "\nThe file " << file_path << " contains "
            << character_count << " characters.\n";
    }
        //Close file and reaffirm it to user
    file_input.close();
    std::cout << "\nClosed file: " << file_path << '\n';
}


