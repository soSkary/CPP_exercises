#include "customFunc.h"

#include <algorithm>            //for std::any_of
#include <cctype>               //for std::isupper and std::islower

std::string reverseString(const std::string& str)
{
    if (str.size() == 1 || str.empty())
    {
        return str;
    }
    else
    {
        std::string returnStr{};
        for (auto revIt{ str.rbegin()}; revIt != str.rend(); ++revIt)
        {
            returnStr.push_back( *revIt );
        }
        return returnStr;
    }
}

bool passwordVerifier(const std::string& password)
{
    //Various if statements, and if all passed, password is valid and return true, else return false

    if (password.size() < 8)
    {
        return false;
    }
    //Check if none of characters is uppercase
    else if (!std::any_of(password.begin(), password.end(), [](unsigned char c) {
        return std::isupper(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is lowercase
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::islower(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is numeric
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::isdigit(c);}
    ))
    {
        return false;
    }
    //Check if none of characters is special character
    else if (!std::any_of(password.begin(), password.end(),
        [](unsigned char c) {return std::ispunct(c);}
    ))
    {
        return false;
    }
    else
    {
        return true;
    }
}
