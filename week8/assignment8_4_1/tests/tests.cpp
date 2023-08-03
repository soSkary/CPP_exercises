#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "heap_array.hpp"
#include "instance_counter.hpp"

#include <iostream>
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
        CHECK(ha_int_sz.empty());
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

        CHECK(ha_int.back() == *(ha_int.end()-1));
        CHECK(ha_int.front() == ha_int.at(0));
        

    }

    SUBCASE("Testing sizing operations")
    {
        oskar::heap_array<int> ha_int{ 1,2,3,4,5,6,7,8,9,10 };
        CHECK(ha_int.size() == 10);
        CHECK(ha_int.capacity() == 10);
        std::cout << ha_int << '\n';
        
        ha_int.resize(15);
        CHECK(ha_int.capacity() >= 15);
        for (std::size_t i{ 0 }; i < 10; ++i)
        {
            CHECK(ha_int.at(i) == i + 1);
        }
        std::cout << ha_int << '\n';
        ha_int.reserve(50);
        CHECK(ha_int.capacity() == 50);
        std::cout << ha_int << '\n';
        ha_int.resize(50);
        std::cout << ha_int << '\n';
        CHECK(ha_int.capacity() == 50);
        for (std::size_t i{ 0 }; i < 10; ++i)
        {
            CHECK(ha_int.at(i) == i + 1);
        }

        ha_int.resize(25);
        CHECK(ha_int.size() == 25);
        CHECK(ha_int.capacity() == 50);

        std::cout << ha_int << '\n';
        ha_int.push_back(26);
        std::cout << ha_int << '\n';
        CHECK(ha_int.at(25) == 26);
        CHECK(ha_int.size() == 26);
        CHECK(ha_int.capacity() == 50);
        
        std::string test("oskar");
        oskar::heap_array<std::string> ha_str{ "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz", "åäö" };
        CHECK(ha_str.size() == 10);
        oskar::heap_array<int> ha_int2{ 1,2,3 };
        ha_int2.push_back(4);
        CHECK(ha_int2.back() == 4);
        
        ha_str.push_back(test);
        CHECK(ha_str.back() == test);
        CHECK(ha_str.size() == 11);
        
        CHECK(ha_str.pop_back() == test);
        CHECK(ha_str.size() == 10);
        CHECK(ha_str.back() == "åäö");

    }
    SUBCASE("Testing iterators")
    {
        oskar::heap_array<std::string> ha_str{ "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz", "åäö" };
        oskar::heap_array<std::string>::size_type index{ 0 };
        for (auto it{ ha_str.begin() }; it != ha_str.end(); ++it)
        {
            CHECK(*it == ha_str[index]);
            ++index;
        }
        index = 0;
        for (auto it{ ha_str.cbegin() }; it != ha_str.cend(); ++it)
        {
            CHECK(*it == ha_str[index]);
            ++index;
        }
        for (auto it{ ha_str.begin() }; auto& element : ha_str)
        {
            CHECK(it == &element);
            ++it;
        }
        for (auto it{ ha_str.cbegin() }; const auto& element : ha_str)
        {
            CHECK(it == &element);
            ++it;
        }
    }
    SUBCASE("Testing swapping and equality operators")
    {
        oskar::heap_array<std::string> ha_str{ "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz", "åäö" };
        oskar::heap_array<std::string> ha_str2(5);        
        oskar::heap_array<std::string> ha_str_copy{ ha_str };
        oskar::heap_array<std::string> ha_str2_copy{ ha_str2 };

        CHECK(ha_str == ha_str_copy);
        CHECK(ha_str2 == ha_str2_copy);
        CHECK(ha_str != ha_str2);
        CHECK(ha_str.capacity() == 10);
        CHECK(ha_str2.capacity() == 5);
        CHECK(ha_str2.size() == 0);
        CHECK(ha_str2.empty());
        CHECK(!ha_str2.is_null());

        oskar::swap(ha_str, ha_str2);
        //Swapping, so these should be opposite to first test
        CHECK(ha_str != ha_str_copy);
        CHECK(ha_str2 != ha_str2_copy);
        CHECK(ha_str != ha_str2);
        CHECK(ha_str == ha_str2_copy);
        CHECK(ha_str2.capacity() == 10);
        CHECK(ha_str.capacity() == 5);
        CHECK(ha_str.size() == 0);
        CHECK(ha_str.empty());
        CHECK(!ha_str.is_null());

        ha_str.swap(ha_str2);
        //Swapping again, so should be back to original
        CHECK(ha_str == ha_str_copy);
        CHECK(ha_str2 == ha_str2_copy);
        CHECK(ha_str != ha_str2);
        CHECK(ha_str.capacity() == 10);
        CHECK(ha_str2.capacity() == 5);
        CHECK(ha_str2.size() == 0);
        CHECK(ha_str2.empty());
        CHECK(!ha_str2.is_null());

        
        

    }

}

TEST_CASE("Testing instance counter")
{
    SUBCASE("Testing initialization")
    {
        {
            CHECK(instance_counter::instances == 0);
            instance_counter ic;
            {
                CHECK(instance_counter::instances == 1);
                instance_counter ic_print{ true };
                {
                    CHECK(instance_counter::instances == 2);
                    instance_counter ic_str{ "test" };
                    {
                        CHECK(instance_counter::instances == 3);
                        instance_counter ic_str_print{ "test_print", true };
                        {
                            CHECK(instance_counter::instances == 4);
                        }
                        CHECK(instance_counter::instances == 4);
                    }
                    CHECK(instance_counter::instances == 3);
                }
                CHECK(instance_counter::instances == 2);
            }
            CHECK(instance_counter::instances == 1);
        }
        CHECK(instance_counter::instances == 0);
        
    }
    SUBCASE("Testing moving instance_counters around")
    {
        {
            
            CHECK(instance_counter::instances == 0);

            instance_counter ic1("test1", true);
            CHECK(instance_counter::instances == 1);

            instance_counter ic2("test2", true);
            CHECK(instance_counter::instances == 2);

            instance_counter ic3("test3", true);
            CHECK(instance_counter::instances == 3);

            instance_counter ic_move1(std::move(ic1));
            ic_move1.data = "test_move1";
            CHECK(instance_counter::instances == 3);
            
            instance_counter ic_move2(std::move(ic2));
            ic_move2.data = "test_move2";
            CHECK(instance_counter::instances == 3);
            
            instance_counter ic_move3(std::move(ic3));
            ic_move3.data = "test_move3";
            CHECK(instance_counter::instances == 3);

            instance_counter ic_move_blank(std::move(ic1));
            ic_move_blank.data = "test_move_blank";
            CHECK(instance_counter::instances == 3);
        }
        CHECK(instance_counter::instances == 0);

    }
}
