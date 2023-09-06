#ifndef UTF_STRING_ADAPTOR_HPP
#define UTF_STRING_ADAPTOR_HPP

#include "utf_iterator.hpp"

#include <string>

namespace oskar
{
    
    class utf_string
    {
    public:

        using iterator = utf_iterator;
        using const_iterator = const utf_iterator;
    
        constexpr inline utf_string(std::string& str)
            : underlying_string{ str }, first{str.begin()}, one_past_last{str.end()} {}

        constexpr inline iterator begin()                 { return first; }
        constexpr inline iterator end()                   { return one_past_last; }
        constexpr inline const_iterator begin() const     { return first; }
        constexpr inline const_iterator end() const       { return one_past_last; }

        constexpr inline std::string::size_type size() const
        {
            std::string::size_type size{ 0 };
            for (const auto& elem : *this)
            {
                ++size;
            }
            return size;
        }


    private:
        std::string& underlying_string;
        utf_iterator first;
        utf_iterator one_past_last;
    };

}

#endif
