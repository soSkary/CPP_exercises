#include <iostream>
#include <string>

#include "utf_iterator.hpp"
#include "string_adaptor.hpp"

int main()
{
    //Exercise 1
    std::cout << "Exercise 1\n\n";
    std::string test_string{ "abcdefghijklmnopqrstuvxyzåäö😀" };


    std::cout << "Print the test_string: " << test_string << '\n';
    std::cout << "For range loop through it:\n";
    for (const auto& elem : test_string)
    {
        std::cout << elem;
    }
    std::cout << '\n';
    
    std::cout << "For auto it {.begin()}:\n";
    for (auto it{ test_string.begin() }; it != test_string.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << '\n';
    
    std::cout << "For std::size_t i{0}:\n";
    for (std::size_t i{ 0 }; i < test_string.size(); ++i)
    {
        std::cout << test_string[i];
    }
    std::cout << '\n';
    
    std::cout << "Print the underlying integer values:\n";
    for (const auto& elem : test_string)
    {
        std::cout << static_cast<int>(elem) << ' ';
    }
    std::cout << '\n';



    //Print the integer values of the char32_t values stored 
    oskar::utf_iterator utf_end{ test_string.end() };
    for (oskar::utf_iterator it{ test_string.begin() }; it != utf_end; ++it)
    {
        std::cout << *it << '\n';
    }
    std::cout << '\n';

    std::string normal_string{ "åäö" };
    oskar::utf_string super_string{ normal_string };
    
    std::cout << "normal_string.size(): " << normal_string.size() << '\n';
    std::cout << "super_string.size(): " << super_string.size() << '\n';

    
    
    return 0;

}



