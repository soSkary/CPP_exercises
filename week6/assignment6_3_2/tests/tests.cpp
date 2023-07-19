#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "positive_integer.hpp"

#include <iostream>
#include <limits>

TEST_CASE("Testing positive integer")
{
    positive_integer pos_int{ 50 };
    SUBCASE("Testing amount of instances")
    {
        //1 positive_integer in this scope
        CHECK(pos_int.amount_of_class_instances() == 1);
        {
            positive_integer pos_int1{ 2 };
            CHECK(pos_int.amount_of_class_instances() == 2);
            positive_integer pos_int2{ 21 };
            CHECK(pos_int.amount_of_class_instances() == 3);
            //3 positive_integer in this scope
        }
        //should still be 1 positive_integer in this scope
        CHECK(pos_int.amount_of_class_instances() == 1);
    }
    SUBCASE("Testing bounds checking")
    {
        CHECK_THROWS_AS(pos_int = -5, const std::exception&);
        CHECK_THROWS_AS(pos_int = (std::numeric_limits<uint16_t>::max() + 1), const std::exception&);
    }
    SUBCASE("Logical operations")
    {
        positive_integer pos_int1{0};        
        CHECK(pos_int1 == 0);
        pos_int1 = 37;
        bool pos_int_bool{ pos_int1 < 56 };
        
        CHECK(pos_int_bool);
        pos_int_bool = pos_int1 > 36;
        CHECK(pos_int_bool);
        pos_int_bool = static_cast<bool>(pos_int1);
        CHECK(pos_int_bool);
        pos_int1 = 0;
        pos_int_bool = static_cast<bool>(pos_int1);
        CHECK(!pos_int_bool);
    }
}
