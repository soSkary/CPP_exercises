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
    void print_ingredients();
    void add_ingredients();

    friend std::ostream& operator<<(std::ostream& ostream, const Food& food);
};



#endif //FOOD_H
