#ifndef SAFE_PRINTF_HPP
#define SAFE_PRINTF_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <type_traits>

namespace safe_print
{
    template <typename T, typename... Ts>
    void safe_printf(const std::string& fmt, const T& first_argument, const Ts&... args)
    {

        std::string::size_type index{ fmt.find_first_of('%') };
        if (index != std::string::npos)
        {
            switch (fmt.at(index + 1))
            {
            case 'c':
            case '%':
                if (!std::is_same_v<std::decay_t<T>, char>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << first_argument;
                break;
            case 'd':
            case 'i':
                if (!std::is_same_v<std::decay_t<T>, int>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << first_argument;
                break;
            case 'e':
                if (!std::is_same_v<std::decay_t<T>, float>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << std::scientific << first_argument << std::defaultfloat;
                break;
            case 'f':
                if (!std::is_same_v<std::decay_t<T>, float>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << std::fixed << std::setprecision(2) << first_argument << std::defaultfloat;
                break;
            case 'o':
                if (!std::is_same_v<std::decay_t<T>, int>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << std::oct << first_argument << std::dec;
                break;
            case 's':
                if (!std::is_same_v<std::decay_t<T>, std::string>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << first_argument << std::dec;
                break;
            case 'u':
                if (!std::is_same_v<std::decay_t<T>, unsigned int>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << first_argument;
                break;
            case 'x':
                if (!std::is_same_v<std::decay_t<T>, int>)
                {
                    throw std::runtime_error("type_check_failed safe_printf");
                }
                std::cout << fmt.substr(0, index) << std::hex << first_argument << std::dec;
                break;
            }

        }
        if constexpr (sizeof...(args) > 0)
        {
            return safe_printf(fmt.substr(index + 2, fmt.size() - 1), args...);
        }
        else
        {
            std::cout << fmt.substr(index + 2, fmt.size() - 1);
            return;
        }

    }
}


#endif
