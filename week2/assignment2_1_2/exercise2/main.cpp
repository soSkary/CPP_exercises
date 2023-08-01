/*
Exercise 2:

Create two std::vector<int> and fill them with random amount of random numbers. Use std::set_intersection to find common elements between them.
*/

#include "random.h"

#include <algorithm>
#include <iostream>
#include <vector>



int main()
{
    //Create a randomly-sized (between 0 and 100) array of integers
    std::vector<int> arr1(Random::get(0, 100));
    //Fill array with random numbers between 0 and 10
    for (auto& a : arr1)
    {
        a = Random::get(0, 10);
    }

    
    //Create a second randomly-sized (between 0 and 100) array of integers
    std::vector<int> arr2(Random::get(0, 100));
    //Fill array with random numbers between 0 and 10
    for (auto& a : arr2)
    {
        a = Random::get(0, 10);
    }

    //Sort arrays
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());


    //Create an array to output the common elements to 
    std::vector<int> common_arr{};

    //Copy the common elements to common_arr (set_intersection finds the intersection 
    //and pushes back to common arr using back_inserter)
    std::set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), std::back_inserter(common_arr));

    //Loop through the common elements
    for (const auto a: common_arr)
    {
        std::cout << a << ' ';
    }
    std::cout << "\n\n";

    std::cout << "The size of arr1: " << arr1.size() << "\nThe size of arr2: " << arr2.size() << '\n';
    std::cout << "Number of common elements: " << common_arr.size() << '\n'; 

    return 0;
}
