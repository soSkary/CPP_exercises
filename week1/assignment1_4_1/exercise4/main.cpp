o/*
 *Exercise 4
 *Write a C++ program that performs division of two numbers. 
 *Implement a function called divide() that takes two integers as input and returns their division result. 
 *Use an assert statement to check that the second number (denominator) is not zero. 
 *If the assertion fails, display an error message indicating that division by zero is not allowed. 
 *Compile the program both with and without the NDEBUG macro defined and observe the behavior when the assertion fails in each case.
 */

#define NDEBUG
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>

//Function that divides the first int with the second
//Asserting that the denominator is not 0
double divide(int numerator, int denominator)
{
	assert(denominator != 0 && "Can't divide with zero!");
	//when making the division a double operator, the compiler wont abort the process
	return static_cast<double>(numerator)/denominator;
}	

int main()
{
	//Set cout to only display two decimal places
	std::cout << std::fixed << std::setprecision(2);
	//Test pattern
	std::cout << "Dividing: 10 / 2 = " << divide(10, 2) << '\n';
	std::cout << "Dividing: 15 / 4 = " << divide(15, 4) << '\n';
	std::cout << "Dividing: 1423 / 9231 = " << divide(1423, 9231) << '\n';

	//Should fail
	std::cout << "Dividing: 61 / 0 = " << divide(61, 0) << '\n';
	if (std::isnan(divide(61,0)) || std::isinf(divide(61,0)))
		std::cout << "divide(61, 0) returned a NaN/Inf\n";
	
	return 0;

}
/*
 * Discussion:
 *
 * The assert will fail at the last division, as it will evaluate to false.
 * If the NDEBUG macro is applied, there will be a runtime-error, as division
 * by zero isn't allowed. ("Floating point exception")
 */
