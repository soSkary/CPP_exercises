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
            std::cout << "Please input name of ingredient to add: ";
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

struct Order
{
    std::vector<Food> m_order;
    double m_order_total_price{0.00};
};


void Menu::management_menu(std::vector<Food>& menu)
{
    while (true)
    {
        std::cout << "\n\nMenu:\n";
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
            add_food_to_menu(menu);
        }
        else if (choice == 'q')
        {
            return;
        }

    }
}

void Menu::add_food_to_menu(std::vector<Food>& menu)
{
    std::cout << "Please enter name of food: ";
    std::string name{Utility::get_user_string()};
    
    std::cout << "Please enter price of food: ";
    double price{ Utility::get_user_double() };
    
    menu.push_back(Food{ name, price });
    menu.back().add_ingredients();
}

std::vector<std::string> Menu::print_order_to_string(const Order& order)
{
    std::vector<std::string> return_vector(order.m_order.size()+1);
    for (std::size_t counter{0}; const auto& item : order.m_order)
    {
        std::string order_string = item.m_name + " - ";
        order_string += std::to_string(item.m_price);
        return_vector.at(counter) = order_string;
        ++counter;
    }
    std::string total_value{"TOTAL VALUE OF ORDER: "};
    total_value += std::to_string(order.m_order_total_price);
    total_value += "€\n";
    return_vector.back() = total_value;
    return return_vector;
}

std::vector<std::string> Menu::user_menu(const std::vector<Food>& menu)
{
    Order order;
    while (true)
    {
        std::cout << "\n\nMenu:\n";
        int counter{ 0 };
        for (const auto& food : menu)
        {
            std::cout << counter << ") " << food << ", " << food.m_price << " €\n";
            ++counter;
        }
        std::cout << "\nCurrent order price: " << order.m_order_total_price << "€\n";
        std::cout << "a) Add food to order\n";
        std::cout << "r) Remove food from order\n";
        std::cout << "q) Place the order and quit the menu\n";
        
        char choice(Utility::get_user_char());
        switch (choice)
        {
            case 'a':
                add_food_to_order(menu, order);
                break;
            case 'r':
                remove_food_from_order(order);
                break;
            case 'q':
                return print_order_to_string(order);
            default:
                break;
        }
    }
}
void Menu::add_food_to_order(const std::vector<Food>& menu, Order& order)
{
    while (true)
    {
        
        std::cout << "\n\nMenu:\n";
        int counter{ 0 };
        for (const auto& food : menu)
        {
            std::cout << counter << ") " << food << ", " << food.m_price << " €\n";
            ++counter;
        }
        std::cout << "\nCurrent order price: " << order.m_order_total_price << "€\n";

        std::cout << "Please enter number of food from the menu: ";
        int choice{ Utility::get_user_int() };

        std::cout << "Please enter amount of dishes to place on order: ";
        int amount{ Utility::get_user_int() };
        if (amount == 0)
        {
            std::cout << "Can't add 0 dishes on order.\n";
        }
        else if (choice >= menu.size() || choice < 0 || amount < 0)
        {
            std::cout << "Invalid choice, try again!\n\n";
            continue;
        }
        else
        {
            for (int i{ 0 }; i < amount; ++i)
            {
                order.m_order.push_back(menu.at(choice));
                order.m_order_total_price += menu.at(choice).m_price;
            }

        }

        std::cout << "\nCurrent status of order:\n";
        for (const auto& food : order.m_order)
        {
            std::cout << food.m_name << " - " << food.m_price << "€\n";
        }
        std::cout << "Total price of order: " << order.m_order_total_price << "€\n\n";
        std::cout << "Do you want to add more items to your order?(y/n) ";
        char return_to_menu{ Utility::get_user_char() };
        Utility::to_lowercase(return_to_menu);
        if (return_to_menu == 'n')
        {
            return;
        }
    }
}

void Menu::remove_food_from_order(Order& order)
{
    std::cout << "\nCurrent status of order:\n";
    int counter{ 0 };
    for (int counter{ 0 }; const auto& food : order.m_order)
        {
        std::cout << counter << ") " << food.m_name << " - " << food.m_price << "€\n";
        ++counter;
    }
        std::cout << "Total price of order: " << order.m_order_total_price << "€\n\n";
        std::cout << "Which item do you want to remove from your order? (-1 to cancel)";
        int choice{ Utility::get_user_int() };
        if (choice < 0)
        {
            std::cout << "Canceling removal.\n";
            return;
        }
        if (choice > order.m_order.size())
        {
            std::cout << "Invalid choice, returning to menu.\n";
            return;
        }
        auto it = order.m_order.begin() + choice;
        order.m_order.erase(it);
}

