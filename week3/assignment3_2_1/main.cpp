
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print_cities(std::vector<std::string> cities, std::vector<std::string> visited_cities)
{

    if (visited_cities.size() == cities.size()+1)
    {
        for (const auto& city : visited_cities)
        {
            std::cout << city << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i{0}; i < cities.size();++i)
    {
        if (std::find(visited_cities.begin(), visited_cities.end(), cities.at(i)) != visited_cities.end())
        {
            continue;
        }
        else
        {
            visited_cities.push_back(cities.at(i));
            print_cities(cities, visited_cities);
            
        }
    }
}


int main()
{
    std::vector<std::string> cities{"New York", "Amsterdam", "Helsinki", "Durban"};
    std::vector<std::string> visited_cities{"Panama"};
    print_cities(cities, visited_cities);
}
