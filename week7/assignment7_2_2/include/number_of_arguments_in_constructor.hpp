#ifndef NUMBER_OF_ARGS_IN_CONSTRUCTOR_HPP
#define NUMBER_OF_ARGS_IN_CONSTRUCTOR_HPP

#include <array>

template <typename... Ts>
class exercise
{
public:
    exercise(const Ts&... args);
    constexpr static int number_of_args{static_cast<int>(sizeof...(Ts))};

    int value;
    int get_number_of_args() const { return number_of_args; }

    std::array<int, number_of_args> return_array() const;

};

template <typename... Ts>
exercise<Ts...>::exercise(const Ts&... args)
{
    //This is solely for purpose of compiler not giving -Wunused-value warning
    value = (args + ...);
}


//std:.array requires at compile-time the number of elements
template <typename... Ts>
std::array<int, exercise<Ts...>::number_of_args> exercise<Ts...>::return_array() const
{
    std::array<int, number_of_args> return_array;
    for (auto& element : return_array)
    {
        static int a{ 1 };
        element = a++;
    }
    return return_array;
}

#endif
