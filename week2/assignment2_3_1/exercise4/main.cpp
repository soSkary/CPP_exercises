/*
Exercise 4:

Create a vector of strings and sort them in lexicographical order.
Also, sort them based on the string length.
*/


#include "exercises.h"
#include <algorithm>
#include <iostream>

void sort_arr(std::vector<std::string>& arr)
{
    std::sort(arr.begin(), arr.end());
}

//Sort array according to string size, using a lambda function
void sort_arr_string_size(std::vector<std::string>& arr)
{
    std::sort(arr.begin(), arr.end(),
        [](const std::string& a, const std::string& b)
        {
            return a.size() < b.size();
        });
}

void print_arr(const std::vector<std::string>& arr)
{
    for (const auto& elem : arr)
    {
            std::cout << elem << '\n';
    }
}
