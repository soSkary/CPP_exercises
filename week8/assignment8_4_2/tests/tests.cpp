#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "memerror1.hpp"
#include "memerror2.hpp"
#include "memerror3.hpp"

TEST_CASE("Memerrors")
{
    SUBCASE("Memerror1")
    {
        large_object a;
        large_object b;
        large_object c = a;

        CHECK(object_storage.at(0).name == "object number 0");
        CHECK(object_storage.at(1).name == "object number 1");
        CHECK(object_storage.at(2).name == "object number 0");
    }
}
