/*
Exercise 5:
Create a vector of pairs where each pair contains a string and an integer
(like a name and an age).
Sort the vector based on the integer.
*/

#include "exercises.h"

#include <algorithm>
#include <iostream>

void sort_arr(std::vector<std::pair<std::string, int>>& arr)
{
    std::sort(arr.begin(), arr.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
        {
            return a.second < b.second;
        }
    );
}

void print_arr(const std::vector<std::pair<std::string, int>>& arr)
{
    for (const auto& pair : arr)
    {
        std::cout << pair.first << " | " << pair.second << '\n';
    }
}
