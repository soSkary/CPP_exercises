/*
Exercise 5:

Create a program that will ask the user for the size of a vector.
*/

#include <iostream>
#include <vector>

int get_vector_size()
{
    std::cout << "Please input size of dynamic array to create: ";
    int v_size;
    std::cin >> v_size;

    return v_size;
}


int main()
{
    //Create vector of user specified size
    std::vector<int> arr(get_vector_size());

    std::cout << "The size of the vector created is: " << arr.size() << '\n';

    
    return 0;
}
