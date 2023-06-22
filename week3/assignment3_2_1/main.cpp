
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

std::array<std::array<int, 5>, 5> cities_lookup{{
    //Panama, NY, Amsterdam, Helsinki, Durban
    { 0, 4460, 8440, 9240, 12950},              //Panama
    { 4460, 0, 5700, 6620, 12700 },             //NY
    { 8440,	5700,	0,	1520,	9760 },         //Amsterdam
    { 9240, 6620, 1520, 0, 10480 },             //Helsinki
    { 12950,	12700,	9760,	10480,	0 }     //Durban
}};

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

void print_shortest_route(std::vector<std::string>& cities, std::size_t recursion = 1, std::vector<std::pair<std::size_t std::size_t>>& routes)
{
     if (recursion == cities.size() -1)
    {
        for (const auto& city : cities)
        {
            std::cout << city << "   ";
        }
        std::cout << "| Distance: " << shortest_route << '\n';
        return;
    }
    for (std::size_t i{recursion}; i < cities.size(); ++i)
    {
        //Swap places between cities
        std::swap(cities.at(i), cities.at(recursion));

        shortest_route += cities_lookup.at(i).at(recursion);
        //Recursively go through the cities
        print_shortest_route(cities, recursion + 1, shortest_route);
        //Swap again to return order of cities to original
        std::swap(cities.at(i), cities.at(recursion));
    }   
}

int main()
{    
    std::vector<std::string> cities{"Panama", "New York", "Amsterdam", "Helsinki", "Durban"};
    //print_cities(cities, 1);
    //print_shortest_route(cities);

    std::cout << "Panama - Helsinki" << cities_lookup.at(0).at(3) << " |" << "Durban - Amsterdam " << cities_lookup.at(4).at(2) << '\n';
    std::cout << "Panama - Panama" << cities_lookup.at(0).at(0) << " |" << "NY - Durban " << cities_lookup.at(1).at(4) << '\n';
}
