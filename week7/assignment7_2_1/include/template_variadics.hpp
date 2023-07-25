#ifndef TEMPLATE_VARIADICS_HPP
#define TEMPLATE_VARIADICS_HPP

#include <cstdint>
#include <iostream>
#include <type_traits>
#include <vector>

//Exercise 1a
inline void print_1a(int value)
{
    std::cout << "A sole value left: " << value << '\n';
}
template <typename... Ts>
void print_1a(const int value, const Ts&... pack)
{
    std::cout << "sizeof...(pack) " << sizeof...(pack) << " value: " << value << '\n';
    return print_1a(pack...);
}

//Exercise 1b

template <typename... Ts>
void print_1b(const int value, const Ts&... pack)
{
    if constexpr (sizeof...(pack) > 0)
    {
        std::cout << "sizeof...(pack) " << sizeof...(pack) << " value: " << value << '\n';
        return print_1b(pack...);
    }
    std::cout << "This is the last call: " << value << '\n';
    return;
}

//Exercise 2

template <typename T, typename... Ts>
auto sum(T&& value, Ts&&... values)
{
    T return_value{ value };
    //cout only for exercise purpose
    std::cout << "Sizeof...(values): " << sizeof...(values) << " current value: " << value << '\n';
    //a if constexpr pattern for checking the size of parameter pack, and if value is of arithmetic type
    if constexpr (std::is_arithmetic_v<std::decay_t<T>> && sizeof...(values) > 0)
        return return_value + (sum(values...));
    else if constexpr (sizeof...(values) > 0)
        return 0 + sum(values...);
    else if constexpr (std::is_arithmetic_v<std::decay_t<T>>)
        return return_value;
    else
        return 0;
}

//Exercise 3
template <typename T>
constexpr bool same_type(T&&, T&&)
{
    return true;
}

template <typename T, typename U>
constexpr bool same_type(T&&, U&&)
{
    return false;
}

template <typename T, typename U, typename... Ts>
constexpr bool all_of_same_type(T&& first_value, U&& second_value, Ts&&... values)
{
    //Check that the parameter pack isn't empty
    if constexpr (sizeof...(values) > 0)
    {
        //if first and second value are of same type, continue recursively
        if (same_type(first_value, second_value))
            return all_of_same_type(second_value, values...);
        //else return false
        else
            return false;
    }
    //This checks the last two values, if all else are true
    else
        return same_type(first_value, second_value);
}

//Exercise 4

template <typename T, typename... Ts>
auto product_of_args_times_number_of_args(const T&& value, const Ts&&... args)
{
    //check if only one argument given
    if constexpr (sizeof...(args) == 0)
        return value;
    //get the number of arguments provided and return sum * n
    constexpr auto number_of_args{ static_cast<T>(sizeof...(args) + 1) };
    return ((value + (args + ...)) * number_of_args);
}

//Exercise 5
template <typename T, typename U, typename... Ts>
auto concatenate_containers(const T& first_cont, const U& second_cont, const Ts&... cont_pack)
{
    static_assert(std::is_same_v<typename T::value_type, typename U::value_type>, "Can't concat containers with different value_type!");
    
    //create a vector to return the concatenated container
    std::vector<typename T::value_type> return_vector(first_cont.size() + second_cont.size());
    //Copy over the first container to the first_vector
    auto index{ return_vector.begin() };
    for (const auto & element: first_cont)
    {
        *index = element;
        ++index;
    }

    for (const auto& element : second_cont)
    {
        *index = element;
        ++index;
    }
    if constexpr (sizeof...(cont_pack) > 0)
    {
        return concatenate_containers(return_vector, cont_pack...);
    }
    else
        return return_vector;
}

#endif
