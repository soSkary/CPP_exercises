/*

Exercise 1:

Create an array with 10 random numbers in it. Your program should also be able to output the elements in the array.

*/


#include "random.h"

#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    /*
    Short program for creating an int array, printing it's contains and filling
    it with random numbers, using lambda functions.
    */

    std::array<int, 10> arr{};

    //Lambda functions for getting a random number between 0 and 100
    //and for printing
    auto random_nr = [](int& n) { n = Random::get(0, 100);};
    auto print = [](const int& n) { std::cout << n << ' ';};

    std::cout << "Printing values of arr before randomizing:\n";
    std::for_each(arr.begin(), arr.end(), print);

    
    std::cout << "\n\n";
    std::for_each(arr.begin(), arr.end(), random_nr);

    std::cout << "Printing values of arr after randomizing:\n";
    std::for_each(arr.begin(), arr.end(), print);

    std::cout << 'n';
    
    return 0;
}
