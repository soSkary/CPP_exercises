#include "utils.h"
#include "banking_application.h"

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
    // try
    // {
    //     std::list<int> list{ 1, 54, 238, 892, 31, 2, 4129, 3418, 886, 9996, 1231, 515, 123, 515155, 12};
    //     std::cout << find_max_value_in_list(list) << '\n';
    //     list.clear();
    //     std::cout << find_max_value_in_list(list) << '\n';
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
    //     return 1;
    // }
/*
Exercise 3
*/
    // try
    // {
    //     std::vector<std::string> vector_of_strings{"Jukka", "Pekka", "Jarmo", "Jorma", "Rauno", "Jooseppi", "Tarmo"};

    //     print_vector_strings(vector_of_strings);
    //     print_vector_strings(vector_of_strings, 3);
    //     std::cout << '\n';
    //     print_vector_strings(vector_of_strings, 7);

    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
    //     return 1;
    // }

/*
Exercise 4
*/
// try
// {
    // std::string string1{"ThisShouldNotThrowAnException"};
    // std::cout << string1 << '\n';
    // process_data(string1);
    // std::cout << string1 << '\n';
    
    // string1 = "Now It should throw an exception!";
    // std::cout << string1 << '\n';
    // process_data(string1);

    // int meaning_of_life{ 1 };
    // std::cout << meaning_of_life << '\n';
    // process_data(meaning_of_life);
    // std::cout << meaning_of_life << '\n';

    // meaning_of_life *= -1;
    // std::cout << meaning_of_life << '\n';
    // process_data(meaning_of_life);
    
// }
// catch(const std::exception& e)
// {
//     std::cerr << "Std::runtime_error caught:\t" << e.what() << "\tExiting program.\n";
//     return 1;
// }

/*
Exercise 5
*/

    banking_application();

    return 0;
}
