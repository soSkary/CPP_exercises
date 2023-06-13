#include "food.h"
#include "utils.h"

#include <iostream>

namespace Menu
{
    void add_food(std::vector<Food>& menu);
    
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
            std::cout << '\n';
            std::cout << "a) " << "Add food to menu\n";
            std::cout << "q) " << "Quit the menu\n";
            
            char choice(Utility::get_user_char());
            if (choice == 'a')
            {
                add_food(menu);
            }
            else if (choice == 'q')
            {
                return;
            }

        }
    }

    void add_food(std::vector<Food>& menu)
    {
        std::cout << "Please enter name of food: ";
        std::string name{Utility::get_user_string()};
        
        std::cout << "Please enter price of food: ";
        double price{ Utility::get_user_double() };
        
        menu.push_back(Food{ name, price });
        menu.back().add_ingredients();
    }
}


int main()
{
    std::vector<Food> menu
    {
        { "Mac n' Cheese", 12.50, { "Macaroni", "Cheese", "Cream", "Butter" } },
        { "Cheeseburger", 10.00, { "Minced beef", "Wheat bun", "Cheese", "Onions" } },
        { "Steak and fries", 15.00, {"Beef steak", "Potato", "Pepper"} }
        };

    Menu::menu(menu);

    

    
}
