#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "pascals_triangle.h"


TEST_CASE("Testing pascals_triangle.cpp")
{
    CHECK(get_pascal_number(1,3,1) == 2);
    CHECK(get_pascal_number(4,5,4) == 1);
    CHECK(get_pascal_number(21,8,3) == 35);
   

    
}
