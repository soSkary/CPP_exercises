#include "food.h"
#include "utils.h"

Food::Food(const std::string& name, const double price)
    : m_name{ name }, m_price{ price }
{}

Food::Food(const std::string& name, const double price, const std::vector<std::string>& ingredients)
    : m_name{ name }, m_price{ price }, m_ingredients{ ingredients }
{}

void Food::print_ingredients()
{
    if (m_ingredients.size() == 0)
    {
        std::cout << "No ingredients\n";
        return;
    }

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

void Food::add_ingredients()
{
    while (true)
    {
        std::cout << "Current ingredients:\n";
        print_ingredients();
        std::cout << "Press 'a' to add ingredient, 'q' to save ingredients and exit:\n";
        char choice{ Utility::get_user_char() };
        if (choice == 'q')
        {
            return;
        }
        else if (choice == 'a')
        {
            std::cout << "Please input name of ingredient to add:";
            std::string ingredient{Utility::get_user_string()};
            m_ingredients.push_back(ingredient);
        }

    }
}

std::ostream& operator<<(std::ostream& ostream, const Food& food)
{
    ostream << food.m_name;
    return ostream;
}
