#ifndef TEXT_PARSING_HPP
#define TEXT_PARSING_HPP

#include "animal.hpp"

#include <algorithm>
#include <fstream>
#include <ios>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

std::unique_ptr<animal> create_animal_ptr(const std::string& animal_type, const std::string& animal_name)
{
    //Check the type, and return an unique pointer with animal of type with supplied name
    if (animal_type == "bird")
        return std::make_unique<bird>(animal_name);
    else if (animal_type == "parrot")
        return std::make_unique<parrot>(animal_name);
    else if (animal_type == "dog")
        return std::make_unique<dog>(animal_name);
    else if (animal_type == "fish")
        return std::make_unique<fish>(animal_name);
    else
        throw std::runtime_error("Unidentified animal type");
}


std::vector<std::unique_ptr<animal>> create_vec_of_animal_ptr_from_file(const std::string& address)
{
    //Open file to be read
    std::ifstream read_line(address);
    if (!read_line)
    {
        throw std::runtime_error("Couldn't open file!");
    }
    std::vector<std::unique_ptr<animal>> vec_of_animal_ptr;

    //Parse the file line by line
    std::string line;
    while (std::getline(read_line, line, '\n'))
    {
        auto comma{ line.find(',') };
        if (comma == std::string::npos)
        {
            throw std::runtime_error("Parsing error");
        }
        //Use the comma found to separate type and name
        std::string type{ line.substr(0, comma) };
        std::string name{ line.substr(comma + 2, line.size() - 1) };

        //Create animal unique pointers and push them on the vector
        vec_of_animal_ptr.push_back(create_animal_ptr(type, name));
    }

    return vec_of_animal_ptr;

}


#endif
