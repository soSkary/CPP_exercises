/*
Exercise 6:

Add a function that will output the smallest and largest number in the array.
*/

#include <algorithm>
#include <array>
#include <iostream>

int smallest_element_array(const std::array<int, 10>& arr)
{
    auto it{ std::min_element(arr.begin(), arr.end()) };
    return *it;
}

int largest_element_array(const std::array<int, 10>& arr)
{
    auto it{ std::max_element(arr.begin(), arr.end()) };
    return *it;
}

int main()
{
    std::array<int, 10> arr{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    std::cout << "The smallest element of the array is " << smallest_element_array(arr)
        << "\nThe largest element of the array is " << largest_element_array(arr) << '\n';

    return 0;

}
