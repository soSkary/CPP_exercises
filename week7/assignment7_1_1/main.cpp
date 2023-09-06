#include <iostream>
#include <type_traits>

namespace assignment
{
    //template functions to check if types are the same
    //if two different types, the first one is called, else, the second is called
    template <typename T, typename U>
    constexpr bool check_if_same_type(T&&, U&&)
    {
        return false;
    }

    template <typename T>
    constexpr bool check_if_same_type(T&&, T&&)
    {
        return true;
    }
    
    template <typename T>
    constexpr bool can_be_decayed_further()
    {
        return !(std::is_same_v<T, std::decay_t<T>>);
    }

}


int main()
{
    
    int a{ 1 };
    float b{ 1.0f };
    int c{ 2 };

    std::cout << "int a{ 1 };\n";
    std::cout << "float b{ 1.0f };\n";
    std::cout << "int c{ 2 };\n";


    std::cout << "a and b are of the same type: " << std::boolalpha << assignment::check_if_same_type(a, b)
        << '\n';
    std::cout << "b and c are of the same type: " << assignment::check_if_same_type(b, c) << '\n';
    std::cout << "a and c are of the same type: " << assignment::check_if_same_type(a, c) << '\n';

    std::cout << "int& can be decayed further: " << assignment::can_be_decayed_further<int&>() << '\n';
    std::cout << "const int can be decayed further: " << assignment::can_be_decayed_further<const int>() << '\n';
    std::cout << "int can be decayed further: " << assignment::can_be_decayed_further<int>() << '\n';

    return 0;
}
