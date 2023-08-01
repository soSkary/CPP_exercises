#include "string_utils.h"
#include <algorithm>
#include <cctype>


std::string reverse_string(std::string str)
{
    std::string reversed;
    for (auto r_it{ str.rbegin() }; r_it != str.rend(); ++r_it)
    {
        reversed += *r_it;
    }
    return reversed;
}
std::string to_lower_case(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
        {
            return std::tolower(c);
        }
    );
    return str;
}

bool is_palindrome(std::string str)
{
    str = to_lower_case(str);
    auto forward = str.begin();
    auto backward = str.rbegin();
    for (std::size_t counter{ 0 }; counter < str.size() / 2; ++counter)
    {
        if (*forward != *backward)
        {
            return false;
        }
    }
    return true;
}

