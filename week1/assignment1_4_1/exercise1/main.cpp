/*
Exercise 1

Write a C++ program that capitalizes the first letter of the string and sets the rest as lowercase letters.
Use the following main function and write a function that passes the assertions.
*/

#include <cassert>          //for assert
#include <cctype>           //for toupper and tolower
#include <iostream>
#include <string>
#include <string_view>

//macro for disabling asserts
//#define NDEBUG

//Function capitalize_string capitalizes the first character of every word. Return a sting. 
//Takes input as string_view, as it is only copied once so this is an effective way to do it. 
std::string capitalize_string(std::string_view unmodified)
{
    std::string capitalized{ unmodified };

    //Loop, and check with a bool, if should be capitalized or un-capitalized
    //A space tells that the next should be capitalized
    for (bool capitalize_next{ true }; auto & c : capitalized)
    {
        if (capitalize_next)
        {
            c = std::toupper(static_cast<unsigned char>(c));
            capitalize_next = false;
        }
        else if (c == ' ')
        {
            capitalize_next = true;
        }
        else
        {
            c = std::tolower(static_cast<unsigned char>(c));
        }
    }
    return capitalized;
}


int main() {
    assert("The String Challenge" == capitalize_string("the string challenge"));
    std::cout << "Test 1 passed" << std::endl;
    assert("This Is An Example, Should Work!" == capitalize_string("THIS IS an ExamplE, should wORk!"));
    std::cout << "Test 2 passed" << std::endl;

    return 0;
}
