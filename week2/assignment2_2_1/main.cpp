#include "utilities/food.h"
#include "utilities/utils.h"

#include <iostream>

namespace Menu
{
    void menu(std::vector<Food>& menu)
    {
        while (true)
        {
            std::cout << "Menu:\n";
            int counter{ 0 };
            for (const auto& food : menu)
            {
                std::cout << counter << ") " << food << ", " << food.m_price << " €\n";
                ++counter;
            }
            std::cout << counter << ") " << "Add food to menu\n";
            int user_input(Utility::get_user_int());
            if (user_input < 0 || user_input > menu.size())
            {
                std::cout << "Invalid input, please try again!\n\n";
            }
            else if (user_input == menu.size())
            {
                std::cout << "Do something!\n";
            }
            else
            {
                
            }

        }
    }
}


int main()
{
    std::vector<Food> menu
    {
    { "Mac n' Cheese", 12.50, { "Macaroni", "Cheese", "Cream", "Butter" } },
    { "Cheeseburger", 10.00, { "Minced beef", "Wheat bun", "Cheese", "Onions" } },
    { "Steak and fries", 15.00, {"Beef steak", "Potato", "Pepper"}}
    };

    Menu::menu(menu);

    

    
}
