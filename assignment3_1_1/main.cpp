#include "utils.h"

#include <iostream>
#include <stdexcept>

int main()
{
    /*
    Exercise 1
    */
    // try
    // {
    //    int result_of_division1{ division(23, 1) };
    //    int result_of_division2{ division(23, 0) };
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
    //     return 1;
    // }
    /*
    Exercise 2
    */
    try
    {
        std::list<int> list{ 1, 54, 238, 892, 31, 2, 4129, 3418, 886, 9996, 1231, 515, 123, 515155, 12};
        std::cout << find_max_value_in_list(list) << '\n';
        list.clear();
        std::cout << find_max_value_in_list(list) << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
        return 1;
    }
    

    return 0;
}
