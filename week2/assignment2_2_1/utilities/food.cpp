#include "food.h"


void Food::print_ingredients()
{
    for (auto i{ m_ingredients.begin() }; ; ++i)
    {
        if (i+1 == m_ingredients.end())
        {
            std::cout << *i << ".\n";
            return;
        }
        else
        {
            std::cout << *i << ", ";
        }
    }
}

std::ostream& operator<<(std::ostream& ostream, const Food& food)
{
    ostream << food.m_name;
    return ostream;
}
