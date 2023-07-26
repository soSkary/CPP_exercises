#include "safe_printf.hpp"
#include "number_of_arguments_in_constructor.hpp"
#include <iostream>

int main()
{
    //Exercise 1
    std::string wowzee{ "wowzee!" };
    safe_print::safe_printf("Scientific %e, String: %s, Int: %i ", 1.0f, wowzee, 15);
    std::cout << '\n';
    
    //This should fail
    try
    {
        safe_print::safe_printf("This should fail %s", 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //Exercise 2
    exercise<int, int, int> test{ 1,2,3 };

    std::cout << "number of arguments: " << test.get_number_of_args() << '\n';

    auto test_array{ test.return_array() };


    std::cout << "Printing out the test_array: ";
    for (const auto& element : test_array)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
