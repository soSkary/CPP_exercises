/*
Exercise 3:

Create a program that has a function that returns the sum of all the elements in an array. The vector will be filled automatically with different numbers
*/


#include "random.h"

#include <iostream>
#include <numeric>
#include <vector>


int sum_of_array(const std::vector<int>& arr)
{
    //return the sum of arr
    return std::accumulate(arr.begin(), arr.end(), 0);
}

int main()
{
    //create a vector of ints sized 10
    std::vector<int> arr(10);

    //Fill vector with random numbers and print them
    std::cout << "Filling arr with random numbers: ";
    for (auto& a : arr)
    {
        a = Random::get(1, 100);
        std::cout << a << ' ';
    }
    std::cout << '\n';

    //sum the array
    std::cout << "The sum of elements in arr is " << sum_of_array(arr) << '\n';
    
    return 0;
}
