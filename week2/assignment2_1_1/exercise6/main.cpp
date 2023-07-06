/*
Exercise 6:

Create a function that will output the smallest and largest number in the list.
*/
#include "random.h"

#include <iostream>
#include <list>


int sort_get_smallest_number(std::list<int>& list)
{
    list.sort();
    return list.front();
}

int sort_get_largest_number(std::list<int>& list)
{
    list.sort();
    return list.back();
}


int main()
{
    //create a list of integers
    std::list<int> list;

    //loop for a random number of times between 100 and 10000
    //and fill list with random numbers between 0 and 10000
    int random_nr{ Random::get(100, 10000) };

    for (int i{ 0 }; i < random_nr; ++i)
    {
        list.push_back(Random::get(0, 10000));
    }

    //print values in list in rows of 20 numbers.
    for (int counter{ 1 }; const auto l : list)
    {
        std::cout << l << ' ';
        if (counter == 20)
        {
            std::cout << '\n';
            counter = 1;
        }
        else
        {
            ++counter;
        }
    }
    std::cout << "\n\n";
    
    //get (and sort) the biggest and smallest values of list
    std::cout << "The biggest number of the list is: " << sort_get_largest_number(list) << '\n'
        << "The smallest value of the list is: " << sort_get_smallest_number(list) << '\n';

    

    return 0;
}
