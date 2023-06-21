/*
Exercise 5:

Create a new program that will create a vector of random size, filled with random numbers between 1 and 100.
*/

#include <iostream>
#include <random>
#include <vector>

int main()
{
    //Create a random device for seeding
    std::random_device rd;
    //Get 8 random integers for our seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    //Initialize Mersenne Twister with the seeder
    std::mt19937 mt{ ss };
    //Create a reusable random number generator for numbers between 1 and 100
    std::uniform_int_distribution random_1_100{1, 100};
    //Create a reusable random number generator for numbers between 1 and 1000 000
    std::uniform_int_distribution random_1_1000000{1, 1000000};



    //Create a vector of random size (between 1 and 1 million)
    std::vector<int> random_arr(random_1_1000000(mt));

    //Fill random_arr with random numbers (between 1 and 100) and print them out
    for (auto& number : random_arr)
    {
        number = random_1_100(mt);
        std::cout << number << ' ';
    }
    std::cout << "\n\nThe size of the vector is: " << random_arr.size() << '\n';

    return 0;
}
