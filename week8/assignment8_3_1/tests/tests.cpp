#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "heap_array.hpp"

#include <iostream>
#include <numeric>
#include <vector>

TEST_CASE("Testing heap_array template class")
{
    SUBCASE("Testing constructors and assignment operators")
    {
        oskar::heap_array<int> ha_int;
        oskar::heap_array<int> ha_int_sz(10);
        oskar::heap_array<int> ha_int_list{ 1,2,3,4,5,6,7,8,9,10 };
        oskar::heap_array<int> ha_int_copy{ha_int_list};
        
        oskar::heap_array<int> ha_int_redundant{ 1,2,3,4,5,6,7,8,9,10 };
        oskar::heap_array<int> ha_int_move{ std::move(ha_int_redundant) };
        CHECK(ha_int.empty());
        CHECK(!ha_int_sz.empty());
        CHECK(!ha_int_list.empty());
        CHECK(!ha_int_copy.empty());
        CHECK(ha_int_redundant.empty());
        CHECK(!ha_int_move.empty());

        ha_int_redundant = ha_int_copy;
        CHECK(ha_int_redundant == ha_int_copy);

        ha_int_move = std::move(ha_int_redundant);
        CHECK(ha_int_move == ha_int_copy);
        CHECK(ha_int_redundant.empty());

    }
    SUBCASE("Testing initialization and accessing elements")
    {
        oskar::heap_array<int> ha_int{ 1,2,3,4,5,6,7,8,9,10 };
        CHECK(ha_int[0] == ha_int.at(0));
        
        for (std::size_t i{ 0 }; i < 10; ++i)
        {
            CHECK(ha_int.at(i) == i + 1);
        }

        CHECK_THROWS(ha_int.at(10));

        CHECK(*ha_int.data() == ha_int.at(0));

    }
    
    SUBCASE("Testing sizing operations")
    {
        oskar::heap_array<int> ha_int{ 1,2,3,4,5,6,7,8,9,10 };
        CHECK(ha_int.size() == 10);
        CHECK(ha_int.capacity() == 10);

        ha_int.resize(15);
        CHECK(ha_int.capacity() > 15);
        for (std::size_t i{ 0 }; i < 10; ++i)
        {
            CHECK(ha_int.at(i) == i + 1);
        }

        ha_int.reserve(50);
        ha_int.resize(50);
        std::iota(ha_int.begin(), ha_int.end(), 1);
        std::cout << ha_int;
        
        CHECK(ha_int.capacity() == 50);
        for (std::size_t i{ 0 }; i < 10; ++i)
        {
            CHECK(ha_int.at(i) == i + 1);
        }

        ha_int.resize(25);
        CHECK(ha_int.size() == 25);
        CHECK(ha_int.capacity() == 50);

        ha_int.push_back(26);
        CHECK(ha_int.at(25) == 26);
        CHECK(ha_int.size() == 26);
        CHECK(ha_int.capacity() == 50);
        

    }
}
