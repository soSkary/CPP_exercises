/*
Exercise 5
Write a C++ program that calculates the square root of a given number.
Implement a function called square_root() that takes a non-negative floating-point number as input and returns its square root.
Use an assert statement to check that the input number is non-negative.
If the assertion fails, display an error message indicating that the square root is not defined for negative numbers.
Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/

#define NDEBUG
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>

double square_root(double number)
{
    assert(number > 0 && "Square root can't be calculated for negative numbers\n");
    return std::sqrt(number);
}


int main()
{
    //Set cout precision to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    //Test pattern
    std::cout << "Square root of 1.00 = " << square_root(1.00) << '\n';
    std::cout << "Square root of 25.00 = " << square_root(25.00) << '\n';
    std::cout << "Square root of 45671.32 = " << square_root(45671.32) << '\n';

    //Should fail
    std::cout << "Square root of -1.00 = " << square_root(-1.00) << '\n';

    if (std::isnan(square_root(-1.00)))
        std::cout << "square_root(-1.00) returned not a number!\n";
    
    return 0;
}

/*
Discussion:

With the NDEBUG macro disabled, the assertion will abort the function when a negative
value is given as input.

With NDEBUG macro enabled, the result will be a not a number (NaN);
*/
