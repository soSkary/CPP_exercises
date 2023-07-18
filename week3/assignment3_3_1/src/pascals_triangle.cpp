#include "pascals_triangle.h"
#include <iostream>

//a function for getting the next number in pascal triangle 
long get_pascal_number(int current_value, int row, int column)
{
    current_value = current_value * (row - column) / column;
    return current_value;
}

void print_pascals_triangle(int how_many_rows)
{
    //Print how_many_rows
    for (int row{ 1 }; row <= how_many_rows; ++row)
    {
        //Print spaces before number
        for (int space {0}; space < how_many_rows-row; ++space)
        {
            std::cout << "  ";
        }
        long val{ 1 };
        //Print number and count the next number
        for (int column{ 1 }; column <= row; ++column)
        {
            std::cout << val << "   ";

            val = get_pascal_number(val, row, column);
        }
        std::cout << '\n';
    }

}

