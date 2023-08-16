#include "my_allocator.hpp"

#include <vector>
#include <iostream>
int main()
{
    
    std::vector<int, oskar::allocator<int, 64>> my_vec;
    int a{ 1 };
    for (std::size_t i{ 0 }; i < 64; ++i)
    {
        my_vec.push_back(a++);
    }

    for (const auto& elem : my_vec)
        std::cout << elem << '\n';
}
