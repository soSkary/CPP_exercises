#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "memerror1.hpp"
#include "memerror2.hpp"
#include "memerror3.hpp"

#include <string>

TEST_CASE("Memerrors")
{
    SUBCASE("Memerror1")
    {
        large_object a;
        large_object b;
        large_object c = a;

        CHECK(large_object::object_storage.at(0).name == "object number 0");
        CHECK(large_object::object_storage.at(1).name == "object number 1");
        CHECK(large_object::object_storage.at(2).name == "object number 0");

    }

    SUBCASE("Memerror2")
    {
        flawed_array<int, 4> int_arr;

        for (auto& element : int_arr)
        {
            static int a{ 1 };
            element = a++;
        }
        
        CHECK(int_arr[0] == 1);
        CHECK(int_arr[1] == 2);
        CHECK(int_arr[2] == 3);
        CHECK(int_arr[3] == 4);

        flawed_array<std::string, 4> str_arr;

        //this will crash and burn
        // for (auto& element : str_arr)
        // {
        //     char c{ 'a' };
        //     element = c++;
        // }
    }

    SUBCASE("Memerror3")
    {
        cpp_wrapper a;
        cpp_wrapper b;
        auto c{ build_wrapper() };
        cpp_wrapper d{ std::move(c) };
    }

    
}
