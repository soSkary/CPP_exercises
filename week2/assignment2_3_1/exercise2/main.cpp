/*
Exercise 2:

Use std::sort with std::greater<int>() to sort an array of integers in descending order.
*/



#include "exercises.h"

#include <algorithm>
#include <functional>

void sort_arr_descending(std::array<int, 10>& arr)
{
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}
