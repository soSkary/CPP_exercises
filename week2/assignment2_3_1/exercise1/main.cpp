/*
Exercise 1:

Write a program that sorts an array of integers in ascending order using std::sort
*/


#include "exercises.h"

#include <algorithm>
#include <iostream>

void sort_arr(std::array<int, 10>& arr)
{
    std::sort(arr.begin(), arr.end());
}

void print_arr(const std::array<int, 10>& arr)
{
    for (const auto& elem : arr)
    {
        std::cout << elem << ' ';
    }
}
