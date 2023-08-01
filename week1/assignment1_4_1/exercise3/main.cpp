/*
Exercise 3
Write a C++ program that calculates the sum of two integers. 
Implement a function called sum() that takes two integers as input and returns their sum. 
Use an assert statement to check that the sum is positive. 
If the assertion fails, display an error message indicating that the sum is not positive. 
Compile the program with the NDEBUG macro defined and observe the behaviour when the assertion fails.
*/

#define NDEBUG
#include <cassert>
#include <iostream>

int sum(int a, int b)
{
    assert((a + b)> 0 && "Sum can't be a negative value");
    return (a + b);
}

int main()
{
    //test pattern
    std::cout << "Sum of 2 + 4 = "  <<  sum(2, 4)   << '\n';
    std::cout << "Sum of -2 + 4 = " <<  sum(-2, 4)  << '\n';
    std::cout << "Sum of 4 + 4 = "  <<  sum(4, 4)   << '\n';
    std::cout << "Sum of 6 + 4 = " <<   sum(6, 4)   << '\n';

    //this should fail
    std::cout << "Sum of -6 + 4 = " <<  sum(-6, 4)   << '\n';
}


/*
Discussion:

When the NDEBUG macro is applied, the asserts are inactivated, and the code will run through,
even if asserts we're false.
If NDEBUG is not applied, then the code will abort if asserts are false.
*/
