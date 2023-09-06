#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
/****************************************/
/*Different dummy functions to test with*/
/****************************************/
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
/*************************************************/


//template class to deduce template types

template <typename R, typename... Args>
class caller
{
public:
    using return_type = R;
    caller(R(*)(Args... args)) {}

    static constexpr std::size_t argument_count{ sizeof...(Args) };



    //Exercise 2, save function argument types as a tuple, can be accessed with nth<N>
    using func_arg_types = std::tuple<Args...>;

    template <std::size_t N>
    using nth = typename std::tuple_element<N, func_arg_types>::type;

};

//Recursive template function to print the function argument types 
template <typename T, std::size_t N>
constexpr void print_argument_types()
{
    std::cout << "function argument number" << N << " type: "
        << typeid (typename T::template nth<N>).name()
        << '\n';

    if constexpr (N == T::argument_count-1)
    {
        return;
    }
    else
    {
        print_argument_types<T, N+1>();
    }
}

//Exercise 1c & 2
template <typename T>
constexpr void print_type_info(T&& function_to_check)
{
    std::cout << "func value_type: " 
    << typeid(typename decltype(caller{ function_to_check })::return_type).name() << '\n';
    std::cout << "func argument_count: " 
        << decltype(caller{ function_to_check })::argument_count << '\n';

    if constexpr (decltype(caller{ function_to_check })::argument_count > 0)
    {
        //Give the caller class as template parameter to recursive function   
        print_argument_types<decltype(caller{ function_to_check }), 0>();
    }
}



int main()
{
   // Exercise 1a
    caller a{ int_func };
    caller b{ uomap_func };

   // Exercise 1b, 1c & 2    
    print_type_info(int_func);
    print_type_info(uomap_func);

    return 0;
}
