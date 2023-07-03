#include "utils.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>

//A function for checking if an alphabetic character
bool character_is_alpha(const char c)
{
    return std::isalpha(static_cast<unsigned char>(c));
}



//Function to divide integers. If divisor == 0, throw exception
int division(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw std::runtime_error("Can't divide by zero.");
    }
    return dividend / divisor;
}
//Gives the max value of a list of integers. If list is empty, throw an exception
int find_max_value_in_list(const std::list<int>& list)
{
    if (list.size() == 0)
    {
        throw std::runtime_error("List is empty.");
    }
    else if (list.size() == 1)
    {
        return list.front();
    }
    else
    {
        int max_value{ 0 };
        
        for (const auto& elem : list)
        {
            if (elem > max_value)
            {
                max_value = elem;
            }
        }
        
        return max_value;
    }
}

//Function to loop throught a vector and print every element
void print_vector_strings(const std::vector<std::string>& vector_of_strings)
{
    for (auto it{ vector_of_strings.begin() }; it != vector_of_strings.end(); ++it)
    {
        if (it+1 == vector_of_strings.end())
        {
            std::cout << *it << '\n';
        }
        else
        {
            std::cout << *it << ", ";
        }
    }
}

//Function that prints the element at specified index, if index out of bound throw exception
void print_vector_strings(const std::vector<std::string>& vector_of_strings, std::size_t target_index)
{
    if (target_index < 0 || target_index >= vector_of_strings.size())
    {
        throw std::runtime_error("Index out of bounds.");
    }
    else
    {
        std::cout << vector_of_strings.at(target_index);
    }
}

//Function that changes the value of each character in a string. If character is not alphabetic, throw exception.
void process_data(std::string& string_to_process)
{
    for (auto& character : string_to_process)
    {
        if (!character_is_alpha(character))
        {
            throw std::runtime_error("Character isn't an alphabetic character.");
        }
        else
        {
            character -= 1;
        }
    }
}

//Function that processes an integer. Throws an exception if given negative value as input.
void process_data(int& int_to_process)
{
    if (int_to_process < 0)
    {
        throw std::runtime_error("Integer has a negative value.");
    }
    else
    {
        int_to_process = 42;
    }
}
