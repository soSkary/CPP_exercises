#include "exercises.h"
#include <iomanip>
#include <iostream>
#include <random>

//Random stuff to generate random numbers
std::random_device rd;

std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

std::mt19937 mt{ss};

std::uniform_int_distribution random_1_10{1, 10};
std::uniform_int_distribution random_10_50{10, 50};
std::uniform_int_distribution random_50_100{50, 100};
std::uniform_int_distribution random_0_1000{0, 1000};

std::uniform_real_distribution<double> random_double_0_10{0.0, 10.0};
std::uniform_real_distribution<double> random_double_0_100{0.0, 100.0};
std::uniform_real_distribution<double> random_double_0_1000{0.0, 1000.0};

void fill_with_random_nums(std::vector<double>& arr, int option = 1)
{
    if (option == 1)
    {
        for (auto& elem : arr)
        {
            elem = random_double_0_10(mt);
        }
    }
    else if (option == 2)
    {
        for (auto& elem : arr)
        {
            elem = random_double_0_100(mt);
        }
    }
    else
    {
        for (auto& elem : arr)
        {
            elem = random_double_0_1000(mt);
        }
    }
}
void fill_with_random_nums(std::vector<int>& arr)
{
 
        for (auto& elem : arr)
        {
            elem = random_0_1000(mt);
        }
    
}

int main()
{


    
    std::array<int, 10> arr{ 68, 29, 1, 90, 123, 67, 243, 12, 29, 3};
    //exercise 1
    std::cout << "EXERCISE 1:\n";
    std::cout << "Create an array of integers sized 10 and sort it\n";
    print_arr(arr);
    
    sort_arr(arr);
    std::cout << '\n';
    print_arr(arr);
    std::cout << "\n\n";
    
    //exercise 2
    std::cout << "EXERCISE 2:\n";
    std::cout << "Sorting the array in descending order\n";

    sort_arr_descending(arr);

    print_arr(arr);
    std::cout << "\n\n";

    //exercise 3
    std::cout << "EXERCISE 3:\n";
    std::cout << "Creating 3 vectors of doubles of random size "
        << "(1 - 10), (10-50) and (50-100)\n"
        << "Filling them with random numbers between "
        << "0 - 10, 0 - 100 and 0 - 1000\n";

    std::vector<double> vect1(random_1_10(mt));
    std::vector<double> vect2(random_10_50(mt));
    std::vector<double> vect3(random_50_100(mt));

    //Set cout to only display two decimal places
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Vector 1 size: " << vect1.size() << '\n';
    fill_with_random_nums(vect1, 1);
    print_arr(vect1);
    std::cout << "\n\n";

    std::cout << "Vector 2 size: " << vect2.size() << '\n';
    fill_with_random_nums(vect2, 2);
    print_arr(vect2);
    std::cout << "\n\n";

    std::cout << "Vector 1 size: " << vect3.size() << '\n';
    fill_with_random_nums(vect3, 3);
    print_arr(vect3);
    std::cout << "\n\n";

    //exercise4
    std::cout << "EXERCISE 4:\n";
    std::cout << "Creating a vector of strings, and sorting it alphabetically, "
        << "and according to string size\n";
    std::vector<std::string> string_arr
    {
        "poison", 
        "fish", 
        "hunter", 
        "troll", 
        "warmachine",
        "point", 
        "daughter", 
        "mayor", 
        "city", 
        "incomprehensible"
    };
    std::cout << "\nString array initial state:\n";
    print_arr(string_arr);
    std::cout << "\nSorted alphabetically:\n";
    sort_arr(string_arr);
    print_arr(string_arr);
    std::cout << "\nSorted according to string size:\n";
    sort_arr_string_size(string_arr);
    print_arr(string_arr);
    std::cout << "\n\n";

    //exercise5
    std::cout << "EXERCISE 5:\n";
    std::cout << "Create a vector of pairs containing a string and an integer.\n"
        << "Sort according to integer\n";
    std::vector<std::pair<std::string, int>> pair_arr
    {
        { "Jaakko", 25 },
        { "Maija",  28 },
        { "Tuomas", 32 },
        { "Neea",   27 },
        { "Aatami", 65 },
        { "Eeva",   65 },
        { "Rauno",  19 },
        { "Rauni",  20 }
    };
    std::cout << "\nPair array initial state:\n";
    print_arr(pair_arr);

    std::cout << "\nSorted according to integer:\n";
    sort_arr(pair_arr);
    print_arr(pair_arr);

    std::cout << "\n\n";

    //exercise6
    std::cout << "EXERCISE 6:\n";
    std::cout << "Create a vector of 50 - 100 random integers and find top 5\n";

    std::vector<int> vect4(random_50_100(mt));
    fill_with_random_nums(vect4);

    std::cout << "\n\nVect4 initial state:\n";
    print_arr(vect4);

    std::cout << "\n\nThe five largest numbers:\n";
    print_arr(find_top_five(vect4));

    std::cout << "\n\nThe initial vector sorted descending for checking that top five is correct:\n";
    sort_arr_descending(vect4);
    print_arr(vect4);

    std::cout << "\n\n";

    //exercise7
    std::cout << "EXERCISE 7:\n";
    std::cout << "Create a vector of pairs, including repeating first elements. Check if order preserved.\n";
    std::cout << "\n\nInitial state:\n";

    std::vector<std::pair<std::string, int>> pair_arr1
    {
        { "Aatami", 25 },
        { "Aatami", 28 },
        { "Aatami", 19 },
        { "Aatami", 56 },
        { "Eeva",   25 },
        { "Eeva",   28 },
        { "Eeva",   19 },
        { "Eeva",   56 },
        { "Jaakko", 25 },
        { "Jaakko", 28 },
        { "Jaakko", 19 },
        { "Jaakko", 56 },
        { "Maija",  25 },
        { "Maija",  28 },
        { "Maija",  19 },
        { "Maija",  56 },
        { "Neea",   25 },
        { "Neea",   28 },
        { "Neea",   19 },
        { "Neea",   56 },
        { "Rauni",  25 },
        { "Rauni",  28 },
        { "Rauni",  19 },
        { "Rauni",  56 },
        { "Rauno",  25 },
        { "Rauno",  28 },
        { "Rauno",  19 },
        { "Rauno",  56 },
        { "Tuomas", 25 },
        { "Tuomas", 28 },
        { "Tuomas", 19 },
        { "Tuomas", 56 }
    };
    print_arr(pair_arr1);
    std::vector<std::pair<std::string, int>> pair_arr1_copy{pair_arr1};

    std::cout << "\n\nSorted according to string with std::sort:\n";
    sort_arr(pair_arr1);
    print_arr(pair_arr1);
    
    std::cout << "\n\nSorted according to string with std::stable_sort:\n";
    sort_arr_maintain_relative_order(pair_arr1_copy);
    print_arr(pair_arr1_copy);

    std::cout << '\n';

    return 0;
}
