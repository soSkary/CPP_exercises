#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "utf_iterator.hpp"

TEST_CASE("Testing the utf-iterator")
{
    SUBCASE("Testing ascii values")
    {
        std::string ascii_string;
        char test_value{ 32 };
        
        while (test_value < 127)
        {
            ascii_string += test_value;
            ++test_value;
        }


        oskar::utf_iterator utf_it{ ascii_string.begin() };

        oskar::utf_iterator utf_end{ ascii_string.end() };


        std::cout << "ascii_string: " << ascii_string << '\n';

        //reset test_value
        test_value = 32;

        for (; utf_it != utf_end; ++utf_it)
        {
            CHECK(test_value == static_cast<char>(*utf_it));
            ++test_value;
        }
    }
    SUBCASE("Testing random unicode characters")
    {
        //Creating a string with characters ♠ ⚯ ᚠ 🙉 😾
        std::string unicode_characters{ "♠⚯ᚠ🙉😾" };
        oskar::utf_iterator utf_it{ unicode_characters.begin() };

        oskar::utf_iterator utf_end{ unicode_characters.end() };

        std::cout << unicode_characters << '\n';
        
        CHECK(*utf_it == 9824);
        ++utf_it;
        CHECK(*utf_it == 9903);
        ++utf_it;
        CHECK(*utf_it == 5792);
        ++utf_it;
        CHECK(*utf_it == 128585);
        ++utf_it;
        CHECK(*utf_it == 128574);
    
    }
    SUBCASE("Testing iterating from different locations")
    {
        std::string test_string("asdahjarasfhhasfajhfaojasfjbnfgsdhajbgasjhd");

        oskar::utf_iterator begin{ test_string.begin() };
        oskar::utf_iterator middle{ begin };
        oskar::utf_iterator end{ test_string.end() };
        
        for (int i{ 0 }; i < 22; ++i)
        {
            ++middle;
        }
        CHECK(static_cast<char>(*middle) == test_string.at(22));
        ++middle;
        ++middle;
        CHECK(static_cast<char>(*middle) == test_string.at(24));

        CHECK(static_cast<char>(*end) == '\0');

        ++end;
        
        CHECK(static_cast<char>(*end) == '\0');

    }

}
