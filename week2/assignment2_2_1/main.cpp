#include "food.h"
#include "utils.h"

#include <iostream>


int main()
{
    std::vector<Food> menu
    {
        { "Mac n' Cheese", 12.50, { "Macaroni", "Cheese", "Cream", "Butter" } },
        { "Cheeseburger", 10.00, { "Minced beef", "Wheat bun", "Cheese", "Onions" } },
        { "Steak and fries", 15.00, {"Beef steak", "Potato", "Pepper"} }
        };

    Menu::management_menu(menu);

    std::vector<std::string> order{Menu::user_menu(menu)};


    for (const auto& string : order)
    {
        std::cout << string << '\n';
    }

    return 0;

    
}
