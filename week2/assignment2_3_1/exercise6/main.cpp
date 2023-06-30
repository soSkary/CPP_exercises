/*
Exercise 6:

Use std::partial_sort to find the top 5 elements from a vector of integers.
The vector should have at least 20 elements.
*/

#include "exercises.h"

#include <algorithm>
#include <functional>
#include <iostream>

void sort_arr(std::vector<int>& arr)
{
    std::sort(arr.begin(), arr.end());
}

void sort_arr_descending(std::vector<int>& arr)
{
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}

//Creates a copy and returns a sorted vector of integers
std::vector<int> create_sorted_arr(const std::vector<int>& arr)
{
    std::vector<int> return_vector{arr};
    sort_arr(return_vector);

    return return_vector;
}

std::vector<int> find_top_five(const std::vector<int>& arr)
{
    if (arr.size() < 5)
    {
        std::cout << "Vector too small ( <5 ), can't find top five. Returning a sorted vector instead!\n";
        return std::vector<int> { create_sorted_arr(arr) };
    }
    else
    {
        std::vector<int> return_arr{arr};
        std::partial_sort(return_arr.begin(), return_arr.begin() + 5, return_arr.end(), std::greater<int>());
        return_arr.resize(5);
        return return_arr;
    }
}

void print_arr(const std::vector<int>& arr)
{
    int counter{ 0 };
    for (const auto& elem : arr)
    {
        if (counter < 10)
        {
            std::cout << elem << ' ';
            ++counter;
        }
        else
        {
            std::cout << elem << '\n';
            counter = 0;
        }
    }
}
