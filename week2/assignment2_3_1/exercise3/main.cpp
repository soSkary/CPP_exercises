/*
Exercise 3:

Create a vector of floating-point numbers and sort it.
Experiment with different sizes of vectors and number ranges.
*/
#include "exercises.h"

#include <algorithm>
#include <iostream>

void sort_arr(std::vector<double>& arr)
{
    std::sort(arr.begin(), arr.end());
}

void print_arr(const std::vector<double>& arr)
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
