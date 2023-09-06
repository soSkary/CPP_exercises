#ifndef MY_UTF_ITERATOR_HPP
#define MY_UTF_ITERATOR_HPP



#include <iostream>
#include <string>
#include <uchar.h>
#include <stdexcept>




//Simple way to check how many bytes the char is according to the first
//byte in the codepoint. Will fail if given wrong UTF format
constexpr std::size_t how_many_bytes(u_char c)
{
    if (c < 128)
    {
        return 1;
    }
    else if(c < 224)
    {
        return 2;
    }
    else if (c < 240)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}


//This decoding part I took "some" help from the internet
constexpr char32_t concat_chars_to_char32t(std::string::pointer char_ptr, std::size_t nr_of_bytes)
{
    if (nr_of_bytes == 1)
    {
        return static_cast<char32_t>(*char_ptr);
    }
    char32_t return_value = 0;
 
    char first_byte = *char_ptr;

    if (nr_of_bytes > 2)
    {
        if (nr_of_bytes > 3)
        {
            return_value = (first_byte & 0x07) << 18;
            char second_byte = *(char_ptr + 1);
            return_value += (second_byte & 0x3f) << 12;
            char third_byte = *(char_ptr + 2);
            return_value += (third_byte & 0x3f) << 6;;
            char fourth_byte = *(char_ptr + 3);
            return_value += (fourth_byte & 0x3f);
        }
        else
        {
            return_value = (first_byte & 0x0f) << 12;
            char second_byte = *(char_ptr + 1);
            return_value += (second_byte & 0x3f) << 6;
            char third_byte = *(char_ptr + 2);
            return_value += (third_byte & 0x3f);
        }
    }
    else
    {
        return_value = (first_byte & 0x1f) << 6;
        char second_byte = *(char_ptr + 1);
        return_value += (second_byte & 0x3f);
    }
    
 
    return return_value;
}

namespace oskar
{
    class utf_iterator
    {
    public:
        using value_type = char32_t;
        using reference = char32_t&;
        using const_reference = const char32_t&;

        constexpr utf_iterator(const std::string::iterator& str_it)
            : current{ &(*str_it) }, value{ concat_chars_to_char32t(current, how_many_bytes(*current)) } {}

        constexpr reference operator*() { return value; }
        constexpr const_reference operator*() const { return value; }

        constexpr utf_iterator& operator++();

        constexpr bool operator!=(const utf_iterator& other) const;


    private:
        std::string::pointer current;
        char32_t value;

    };

    
    constexpr utf_iterator& utf_iterator::operator++()
    {
        if (*current == '\0')
            return *this;
        else
        {
            current += how_many_bytes(*current);
            value = concat_chars_to_char32t(current, how_many_bytes(*current));
            return *this;
        }
    }

    constexpr bool utf_iterator::operator!=(const utf_iterator& other) const
    {
        return (current != other.current);
    }
}

std::ostream& operator<<(std::ostream& out, const char32_t& c32)
{
    out << static_cast<int>(c32);
    return out;
}



#endif
