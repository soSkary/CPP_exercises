#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "grid_2d.hpp"

#include <cstdint>
#include <string>


TEST_CASE("Testing grid_2d")
{
    grid_2d::grid_2d<int> test{ 3, 3, { 0, 1, 2, 3, 4, 5, 6, 7, 8 } };
    SUBCASE("Testing initialization and indexing")
    {
        
        CHECK(test.at(0, 0) == 0);
        CHECK(test.at(0, 1) == 1);
        CHECK(test.at(0, 2) == 2);
        CHECK(test.at(1, 0) == 3);
        CHECK(test.at(1, 1) == 4);
        CHECK(test.at(1, 2) == 5);
        CHECK(test.at(2, 0) == 6);
        CHECK(test.at(2, 1) == 7);
        CHECK(test.at(2, 2) == 8);

        
        CHECK_THROWS(test.at(-1, 0));
        CHECK_THROWS(test.at(-1, 3));
        CHECK_THROWS(test.at(0, 3));
        CHECK_THROWS(test.at(0, -1));
        CHECK_THROWS(test.at(1, 3));
        CHECK_THROWS(test.at(1, -1));
        CHECK_THROWS(test.at(2, 3));
        CHECK_THROWS(test.at(2, -1));
        CHECK_THROWS(test.at(3, 0));
        CHECK_THROWS(test.at(3, -1));

        //Creating an empty grid
        grid_2d::grid_2d<std::string> test2;
        //Checking that can't access it, as it's empty
        CHECK_THROWS(test2.at(0, 0));

    }

    SUBCASE("Testing resizing the grid")
    {
        //Creating an empty grid
        grid_2d::grid_2d<std::string> test_string;
        //Checking that can't access it, as it's empty
        CHECK_THROWS(test_string.at(0, 0));

        test_string.resize(2, 10);

        CHECK(test_string.size() == 20);
        char c{ 'a' };
        for (auto& element : test_string)
        {
            element = c++;
        }
        std::cout << test_string << '\n';
        
        
        CHECK( test_string.at(0, 0) == "a" );
        CHECK( test_string.at(1, 0) == "k" );
        CHECK_THROWS(test_string.at(2, 0));
        CHECK_THROWS(test_string.at(0, 10));

        test_string.resize(2, 5);

        CHECK(test_string.size() == 10);
        CHECK_THROWS(test_string.at(2, 0));
        CHECK_THROWS(test_string.at(0, 5));
        CHECK( test_string.at(0, 0) == "a" );
        CHECK( test_string.at(1, 0) == "k" );

        test_string.resize(2, 10);
        
        std::cout << test_string << '\n';

        CHECK(test_string.size() == 20);
        CHECK_THROWS(test_string.at(2, 0));
        CHECK_THROWS(test_string.at(0, 10));
        CHECK( test_string.at(0, 0) == "a" );
        CHECK( test_string.at(1, 0) == "k" );

        //Checking default initialization
        CHECK(test_string.at(0, 9) == std::string{});
        CHECK(test_string.at(1, 5) == std::string{});

        
        grid_2d::grid_2d<int> test_int{ 5, 4, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19} };
        CHECK_THROWS(test_int.at(0, 4));
        CHECK_THROWS(test_int.at(5, 0));

        CHECK(test_int.at(0, 3) == 3);
        CHECK(test_int.at(1, 3) == 7);
        CHECK(test_int.at(2, 3) == 11);
        CHECK(test_int.at(3, 3) == 15);
        CHECK(test_int.at(4, 3) == 19);

        std::cout << test_int << '\n';

        test_int.resize(2, 2);
        CHECK_THROWS(test_int.at(0, 2));
        CHECK_THROWS(test_int.at(2, 0));
        CHECK_THROWS(test_int.at(-1, 2));

        CHECK(test_int.at(0, 0) == 0);
        CHECK(test_int.at(0, 1) == 1);
        CHECK(test_int.at(1, 0) == 4);
        CHECK(test_int.at(1, 1) == 5);
    }
    SUBCASE("Testing data() and empty() ")
    {        
        CHECK(*(test.data()) == 0);
        CHECK(*(test.data() + 3) == test.at(1, 0));

        grid_2d::grid_2d<int> test_null;
        CHECK(test_null.empty());
        CHECK(test_null.data() == nullptr);
    }
    SUBCASE("Testing iterators")
    {
        int a{ 0 };
        for (auto it{ test.begin() }; it != test.end(); ++it)
        {
            CHECK(*(it) == a++);
        }
        a = 0;
        for (auto it{ test.cbegin() }; it != test.cend(); ++it)
        {
            CHECK(*(it) == a++);
        }

        CHECK(test.back() == 8);
        CHECK(test.front() == 0);
    }
    SUBCASE("Max size")
    {
        CHECK(test.max_size() >= test.size());
        grid_2d::grid_2d<int8_t> test_s_ints;
        grid_2d::grid_2d<int64_t> test_l_ints;

        CHECK(test_s_ints.max_size() > test_l_ints.max_size());
        std::cout << "test_s_ints.max_size(): " << test_s_ints.max_size()
            << "\ntest_l_ints.max_size(): " << test_l_ints.max_size() << '\n';
    }


}
