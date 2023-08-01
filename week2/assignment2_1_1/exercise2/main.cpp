/*
Exercise 2:

Add a function that receives an std::array and a number, and checks whether the number is in the array. The function should return a boolean value.
*/


#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>


bool nr_found_in_array(const std::array<int, 10> arr, const int target)
{
    auto found{ std::find(arr.begin(), arr.end(), target) };
    if (found != arr.end())
    {
        return true;
    }
    
    return false;
    
}

int main()
{
    
    std::array<int, 10> arr {};

    //fill array with numbers starting from 1
    std::iota(arr.begin(), arr.end(), 1);


    //print out the array
    for (auto a : arr)
    {
        std::cout << a << ' ';
    }
    
    //output booleans as true/false instead of 1/0
    std::cout << '\n' << std::boolalpha;

    //check if numbers are found in array
    std::cout << "Is  7 found in arr? " << nr_found_in_array(arr, 7) << '\n';
    std::cout << "Is  0 found in arr? " << nr_found_in_array(arr, 0) << '\n';
    std::cout << "Is -3 found in arr? " << nr_found_in_array(arr, -3) << '\n';
    std::cout << "Is 75 found in arr? " << nr_found_in_array(arr, 75) << '\n';

    return 0;
}
