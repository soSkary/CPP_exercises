#include "utility_functions.h"

#include <iostream>
#include <limits>


//constant to define how many lines to print to "clear screen"
const int clear_screen_newlines{ 3 };

//function for getting user input INT
int get_int_input()
{
    int value;
    while (true)
    {
        std::cout << "Input integer value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;

    }
}
//function for getting user input DOUBLE
double get_double_input()
{
    double value;
    while (true)
    {
        std::cout << "Input value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;

    }
}
//function for getting user input CHAR
char get_char_input()
{
    char value;
    while (true)
    {
        std::cout << "Input character: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;
    }
}
//function for getting user input STD::STRING
std::string get_string_input()
{
    std::string value;
    while (true)
    {
        std::cout << "Input string: ";
        std::getline(std::cin >> std::ws, value);
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;
    }
}
//function for clearing or refreshing screen
void clear_screen()
{
    for (int i{ 0 }; i < clear_screen_newlines; ++i)
    {
        std::cout << '\n';
    }
}
