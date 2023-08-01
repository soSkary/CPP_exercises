#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>


struct Food
{
    std::string m_name{};
    double m_price{};
    std::vector<std::string> m_ingredients{};

    Food(const std::string& name, const double price);
    Food(const std::string& name, const double price, const std::vector<std::string>& ingredients);
    void print_ingredients() const;
    void add_ingredients();

    friend std::ostream& operator<<(std::ostream& ostream, const Food& food);
};

struct Order;

namespace Menu
{
    void management_menu(std::vector<Food>& menu);
    void add_food_to_menu(std::vector<Food>& menu);
    void print_menu_and_ingredients(const std::vector<Food>& menu);

    std::vector<std::string> user_menu(const std::vector<Food>& menu);
    void add_food_to_order(const std::vector<Food>& menu, Order& order);
    void print_current_order_status(const Order& order);
    void remove_food_from_order(Order& order);
    std::vector<std::string> print_order_to_string(const Order& order);
}

#endif //FOOD_H
