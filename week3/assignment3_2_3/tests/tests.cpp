#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "exercises.h"
#include <string>

TEST_CASE("Testing recursive string reversal")
{
   
    CHECK(recursive_reverse_string("Tonttu") == "uttnoT");
    CHECK(recursive_reverse_string("T4king!Speci@ls") == "sl@icepS!gnik4T");
    CHECK(recursive_reverse_string("Spaces don't matter!") == "!rettam t'nod secapS");
};

TEST_CASE("Testing the greatest common divisor function")
{
    CHECK(greatest_common_divisor(12, 4) == 4);
    CHECK(greatest_common_divisor(4000, 222) == 2);
    CHECK(greatest_common_divisor(571, 23) == 1);
    CHECK(greatest_common_divisor(10000, 5000) == 5000);

}

TEST_CASE("Testing the power function")
{
    CHECK(my_power(10, 2) == 100);
    CHECK(my_power(78, 3) == 474552);
    CHECK(my_power(-3, 33) == -5559060566555523);
    CHECK(my_power(2, 62) == 4611686018427387904);
    CHECK(my_power(2, 0) == 1);
}
