#include "customFunc.h"


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

