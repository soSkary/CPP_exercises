#include "math_operations.h"

#include <iostream>
#include <limits>

char get_user_char()
{
    while (true)
    {
        char value;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

double get_user_double()
{
    while (true)
    {
        double value;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}
//The main operator if command line arguments invalid
double get_operation_and_values()
{
    std::cout << "Please input which operation you want to use:(+ addition, - subtraction, * multiplication or / division): ";
    char operation{ get_user_char() };
    while (operation != '+' && operation != '-' && operation != '*' && operation != '/')
    {
        std::cout << "Invalid operation, please input +, -, * or / ";
        operation = get_user_char();
    }
    std::cout << "Please input first number to be operated on: ";
    double a{ get_user_double() };

    std::cout << "Please input second number to be operated on: ";
    double b{ get_user_double() };

    if (operation == '/');
    {
        while (b == 0.0)
        {
            std::cout << "Can't divide by zero, please input valid value for divider! ";
            b = get_user_double();
        }
    }
    double return_value;
    switch (operation)
    {
    case '+':
        return_value = add(a, b);
        break;
    case '-':
        return_value = subtract(a, b);
        break;
    case '*':
        return_value = multiply(a, b);
        break;
    case '/':
        return_value = divide(a, b);
        break;
    default:
        std::cout << "Error, invalid operator + - * /\n";
        break;
    }
    return return_value;
}



