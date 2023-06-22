
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print_cities(std::vector<std::string>& cities, std::size_t recursion)
{

    if (recursion == cities.size() -1)
    {
        for (const auto& city : cities)
        {
            std::cout << city << "   ";
        }
        std::cout << '\n';
        return;
    }
    for (std::size_t i{recursion}; i < cities.size(); ++i)
    {
        //Swap places between cities
        std::swap(cities.at(i), cities.at(recursion));
        //Recursively go through the cities
        print_cities(cities, recursion + 1);
        //Swap again to return order of cities to original
        std::swap(cities.at(i), cities.at(recursion));
    }
}


int main()
{    
    std::vector<std::string> cities{"Panama", "New York", "Amsterdam", "Helsinki", "Durban"};
    print_cities(cities, 1);
}
