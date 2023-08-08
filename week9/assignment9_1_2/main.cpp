#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>

int int_func(int a, int b, int c)
{
    return a+b+c;
}

bool bool_func()
{
    return true;
}

char char_func()
{
    return 1;
}

double double_func()
{
    return 1.0;
}

std::string string_func()
{
    return "1";
}

std::unordered_map<int, std::string> uomap_func()
{
    return { {1, "1"} };
}

//Exercise 2
//Create a tuple to store the parameter info to
template <typename... Args>
struct func_traits
{
    using Tuple = std::tuple<Args...>;
    static constexpr auto sz = sizeof...(Args);

    template <std::size_t N>
    using nth = typename std::tuple_element<N, Tuple>::type;
    using first = nth<0>;
    using last = nth<sz - 1>;
};

template <typename R, typename... Args>
class caller
{
public:
    using return_type = R;
    caller(R(*)(Args... args)) {}

    static constexpr std::size_t argument_count{ sizeof...(Args) };
    static constexpr func_traits<Args...> function_traits{};
};

template <typename T>
void print_type_info(T&& function_to_check)
{
    std::cout << "func value_type: " << typeid(typename decltype(caller{ function_to_check })::return_type).name() << '\n';
    std::cout << "func argument_count: " << decltype(caller{ function_to_check })::argument_count << '\n';
    if (decltype(caller{ function_to_check })::argument_count != 0)
    {
        
        for (std::size_t i{ 0 }; i <= decltype(caller{ function_to_check })::argument_count; ++i)
        {
            std::cout << "argument " << i << " type: "
                << typeid(decltype(caller{ function_to_check })::function_traits::template nth<i>).name() << '\n';
        }
    }
}




int main()
{
    //Exercise 1a
    caller a{ int_func };
    caller b{ uomap_func };

    //Exercise 1b    
       
    print_type_info(int_func);
    //print_type_info(uomap_func);

    

    return 0;
}
