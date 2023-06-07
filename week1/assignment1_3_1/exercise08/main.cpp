#include <array>
#include <iostream>

void print_array(const int* array, int array_size)
{
    for (int i{ 0 }; i < array_size ; ++i)
    {
        std::cout << "int_array[" << i << "]: " << *(array+i) << '\n';
    }
}

void create_dyn_int_array()
{
    //create new dynamically allocated int array
    int length{ 5 };
    auto* int_array{ new int[length] {} };

    int value{ 5 };
    for (int i { 0 }; i < length ; ++i)
    {
        int_array[i] = value;
        --value;
    }

    print_array(int_array, length);

    delete[] int_array;
    
    //not really needed here, as the variable goes out of scope, 
    //but trying to build good habits vvvv

    int_array = nullptr;
}

int main()
{
    create_dyn_int_array();

    return 0;
}

/*
Discussion:
    Dynamic memory allocation extends the lifetime to be manually defined.
    But you have to keep in mind, that the scope is still the same! This
    leads to having to delete the dynamically allocated memory, before
    the pointer goes out of scope. Because otherwise it will lead to memory
    leaking, as you can't access the allocated memory location.
*/
