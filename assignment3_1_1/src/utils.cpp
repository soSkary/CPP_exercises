#include "utils.h"

#include <algorithm>
#include <stdexcept>

int division(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw std::runtime_error("Can't divide by zero.\n");
    }
    return dividend / divisor;
}


int find_max_value_in_list(const std::list<int>& list)
{
    if (list.size() == 0)
    {
        throw std::runtime_error("List is empty.\n");
    }
    else if (list.size() == 1)
    {
        return 0;
    }
    else
    {
    int max_value{0};
    for (const auto& elem: list)
    {
        if (elem > max_value)
        {
            max_value = elem;
        }
    }
        
    return max_value;
    }
}
