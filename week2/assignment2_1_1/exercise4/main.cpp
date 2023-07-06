/*
Exercise 4:

Create a  program that that prints out the product of all elements in an array
*/


#include <iostream>
#include <vector>

int product_of_array(std::vector<int>& arr)
{
    int sum{1};
    for (auto a : arr)
    {
        sum *= a;
    }
    return sum;
}

int main()
{
    //create an array of integers
    std::vector<int> arr{ 1, 5, 258, 2, 492 };

    std::cout << "The array consists of: ";
    for (const auto a : arr)
    {
        std::cout << a << ' ';
    }

    std::cout << "\nThe sum of the elements in the array is " << product_of_array(arr) << '\n';

    return 0;
}
