/*
Exercise 1:

Create a vector<int> with 10 numbers in it. Use std::partition to separate the even and odd numbers. Print out the vector after partitioning.
*/

#include <algorithm>
#include <iostream>
#include <vector>


int main()
{

    std::vector<int> arr{ 123, 9451, 674, 7754, 8174766, 91956, 87184, 2938, 9, 56};

    //order the vector in even and odd numbers and
    //create a iterator to the dividing point of the partition
    auto partition{ std::partition(arr.begin(), arr.end(),[](int a) {return a % 2 == 0;}) };

    //Loop through and print the out the even partition of the array
    for (auto it{ arr.begin() }; it != partition; ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    //Loop through and print out the odd partition of the array
    for (auto it {partition}; it != arr.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';


    return 0;
}
