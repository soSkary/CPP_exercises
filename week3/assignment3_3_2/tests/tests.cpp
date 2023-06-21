#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "math_utils.h"

#include <stdexcept>

TEST_CASE("Testing math_utils.cpp")
{
    CHECK(add(1, 2) == 3);
    CHECK(add(252, -752) == -500);
    CHECK(subtract(10, 2) == 8);
    CHECK(subtract(-10, 2) == -12);
    CHECK(multiply(3, 4) == 12);
    CHECK(multiply(370, 0) == 0);
    CHECK(multiply(-7, 8) == -56);
    CHECK(multiply(-7, -8) == 56);
    CHECK(divide(15, 3) == 5);
    CHECK(divide(-15, 3) == -5);
    CHECK_THROWS_AS(divide(1, 0), std::exception);
};
