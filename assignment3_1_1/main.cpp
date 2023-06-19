#include "utils.h"

#include <iostream>
#include <stdexcept>

int main()
{
    /*
    Exercise 1
    */
    try
    {
       int result_of_division{ division(23, 0) };
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
        return 1;
    }

    return 0;
}
