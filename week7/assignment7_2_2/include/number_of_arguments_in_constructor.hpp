#ifndef NUMBER_OF_ARGS_IN_CONSTRUCTOR_HPP
#define NUMBER_OF_ARGS_IN_CONSTRUCTOR_HPP

#include <array>
#include <cstdint>

template <std::size_t T>
class exercise
{
public:
    template <typename... Ts>
    exercise(const Ts&&...) {}
    constexpr static int number_of_args{ T };

    int value;

    std::array<int, number_of_args> return_array() const;

};


//std::array requires at compile-time the number of elements
template <std::size_t T>
std::array<int, exercise<T>::number_of_args> exercise<T>::return_array() const
{
    std::array<int, number_of_args> return_array;
    for (auto& element : return_array)
    {
        static int a{ 1 };
        element = a++;
    }
    return return_array;
}

template <typename... Ts>
exercise(const Ts&&...) -> exercise<sizeof...(Ts)>;

#endif
