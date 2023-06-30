/*
Exercise 7:

Create a vector of pairs with repeating first elements.
After sorting, check if the pairs with equal first elements maintain their relative order.
*/

#include "exercises.h"

#include <algorithm>



void sort_arr_maintain_relative_order(std::vector<std::pair<std::string, int>>& arr)
{
    std::stable_sort(arr.begin(), arr.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });
}
