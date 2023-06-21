/*

Exercise 3:

Create a vector with 10 random elements in it. Rotate elements to the right by 3 positions with std::rotate.

*/

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>




int main()
{
    //Create a random number for seeding
    std::random_device rd;
    //Get 8 random integers for our seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    //Initialize Mersenne Twister with the seeder
    std::mt19937 mt{ ss };
    //Create a reusable random number generator for numbers between 0 and 100
    std::uniform_int_distribution random0_100{0, 100};

    //Create a dynamic array of 10 integers
    std::vector<int> arr(10);

    //Fill the array with random numbers and print it
    for (auto& a : arr)
    {
        a = random0_100(mt);
        std::cout << a << ' ';
    }
    std::cout << "\n\n";

    //Rotate the array to the right 3 positions using std::rotate
    std::rotate(arr.rbegin(), arr.rbegin() + 3, arr.rend());

    //Print the rotated array
    for (auto& a : arr)
    {
        std::cout << a << ' ';
    }
    std::cout << "\n\n";

    return 0;
}
