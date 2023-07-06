/*
Exercise 7:

Create a function that will remove all instances of a value from the vector and inform if the value was found and removed.
*/
#include "random.h"

#include <algorithm>
#include <iostream>
#include <vector>

bool found_and_removed(std::vector<int>& arr, const int target)
{
    int counter{ 0 };
    auto found{ std::find(arr.begin(), arr.end(), target) };
    if (found == arr.end())
    {
        std::cout << target << " could not be found in the given array.\n";
        return false;
    }

    while (found != arr.end())
    {
        ++counter;
        arr.erase(found);
        found = std::find(arr.begin(), arr.end(), target);
    }
    std::cout << counter << " instances of " << target << " was found and removed from the array\n";
    return true;
}

int main()
{
    //create a vector of integers sized 100 000
    std::vector<int> arr(100000);

    //Give all elements a random value between 0 and 10 000, and print the values in rows of 20

    int counter{ 0 };
    for (auto& a : arr)
    {
        a = Random::get(0, 10000);
        std::cout << a << ' ';
        ++counter;

        if (counter == 20)
        {
            std::cout << '\n';
            counter = 0;
        }
    }
    std::cout << "\n\n";

    //get random number to be removed from the array
    int number_to_be_removed{ Random::get(0, 10000) };

    //check if the number could be found in the array
    std::cout << std::boolalpha << found_and_removed(arr, number_to_be_removed) << '\n';

    std::cout << "The size of arr is " << arr.size() << '\n';
    return 0;

}
