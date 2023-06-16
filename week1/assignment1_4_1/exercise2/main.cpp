/*
Exercise 2
Write a C++ program that calculates the factorial of a given number.
Implement a function called factorial() that takes an integer as input and returns its factorial.
Use an assert statement to check that the input number is non-negative.
If the assertion fails, display an error message indicating that the factorial is not defined for negative numbers.
Test your program with various input values, including both positive and negative numbers.
*/

#include <cassert>
#include <iostream>

//#define NDEBUG

//A function that takes an integer, and checks if it's a positive number
//Returns the factorial for valid cases
unsigned long long int factorial(int base)
{
    assert((base >= 0) && "Aborting factorial(), can't calculate for negative values");
    if (base == 0)
    {
        return base;
    }
    //using the base as the first number for the factorial, 
    //then in a loop multiply with one smaller number including when base is 2 (as x == x*1)
    unsigned long long int factorial{ static_cast<unsigned long long int>(base) };
    --base;
    for (; base > 1; --base)
    {
        factorial *= base;
    }
    return factorial;
}


int main()
{
    //testing the factorial() function
    
    std::cout << "Factorial of 3 = " << factorial(3) << '\n';
    assert((factorial(3) == 6) && "Function gives wrong return value! factorial(3) != 6");
    std::cout << "Factorial of 6 = " << factorial(6) << '\n';
    assert((factorial(6) == 720) && "Function gives wrong return value! factorial(6) != 720");
    std::cout << "Factorial of 12 = " << factorial(12) << '\n';
    assert((factorial(12) == 479001600) && "Function gives wrong return value! factorial(12) != 479001600");

    //testing negative number
    std::cout << "This should fail, as the assert inside should factorial() should "
        << "abort because of negative number" << factorial(-5);

    return 0;
}
