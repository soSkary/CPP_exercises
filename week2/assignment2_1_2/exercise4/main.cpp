/*
Exercise 4:

Create a std::list<int> with 10 elements. Use std::adjacent_find to find the first two adjacent elements that are equal. If no such elements exist, print a suitable message.
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <random>

int main()
{
     //Create a random number for seeding
    std::random_device rd;
    //Get 8 random integers for our seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    //Initialize Mersenne Twister with the seeder
    std::mt19937 mt{ ss };
    //Create a reusable random number generator for numbers between 0 and 100
    std::uniform_int_distribution random_0_10{0, 10};

    //Create an empty list of size 10
    std::list<int> list(10);

    //Fill the list with random numbers and print it
    for (auto& number : list)
    {
        number = random_0_10(mt);
        std::cout << number << ' ';
    }
    std::cout << "\n\n";

    //Find first adjacent values
    auto match{ std::adjacent_find(list.begin(), list.end()) };

    if (match == list.end())
    {
        std::cout << "Couldn't find adjacent elements that are equal!\n\n";
    }
    else
    {
        std::cout << "The first equal adjacent elements in the list hold the value " << *match
            << "\nand can be found at index " << std::distance(list.begin(), match) << "\n\n";
    }

    return 0;
}
