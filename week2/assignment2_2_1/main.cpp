#include "food.h"
#include "utils.h"

#include <iostream>


int main()
{
    //Create initial menu to pass to program
    std::vector<Food> menu
    {
        { "Mac n' Cheese", 12.50, { "Macaroni", "Cheese", "Cream", "Butter" } },
        { "Cheeseburger", 10.00, { "Minced beef", "Wheat bun", "Cheese", "Onions" } },
        { "Steak and fries", 15.00, {"Beef steak", "Potato", "Pepper"} }
        };

    //Go to the management menu, where you can add foods to menu and see ingredients
    Menu::management_menu(menu);

    //Go to ordering menu, and return a vector consisting of the order and price
    std::vector<std::string> order{Menu::user_menu(menu)};

    //Print every item consisting of food and price on current order
    for (const auto& item : order)
    {
        std::cout << item << '\n';
    }

    return 0;

    
}
