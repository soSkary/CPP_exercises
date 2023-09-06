#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


//Exercise1
/*************************************************/
void func1()
{
    std::cout << "func1\n";
}
void func2()
{
    std::cout << "func2\n";
}
void func3()
{
    std::cout << "func3\n";
}
/*************************************************/

//Exercise2
/*************************************************/
namespace oskar
{
    
    constexpr double add(double a, double b)
    {
        return a + b;
    }

    constexpr double subtract(double a, double b)
    {
        return a - b;
    }
    constexpr double multiply(double a, double b)
    {
        return a * b;
    }
    constexpr double divide(double a, double b)
    {
        return a / b;
    }
    constexpr double power(double a, double b)
    {
        return std::pow(a, b);
    }
    constexpr double remainder(double a, double b)
    {
        return std::remainder(a, b);
    }

}
double parse_line(const std::string& line, std::unordered_map<char, std::function<double(double, double)>>& func_map)
{
    auto operator_location{ line.find_first_of(' ') };
    ++operator_location;

    char oper{ line.at(operator_location) };
    double a{ std::stod(line.substr(0, operator_location - 1)) };
    double b{ std::stod(line.substr(operator_location+2, line.size()-operator_location -2)) };

    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == '%')
    {
        return func_map.at(oper)(a, b);
    }

    std::cout << "Operator not identified, returning -9999.99\n";
    return -9999.99;
}

int main(int argc, char* argv[])
{
    //Exercise 1
    /***********************************************/
    std::vector<std::function<void()>> func_vec
    {
        func1, func2, func3
    };

    if (argc > 1)
    {
        for (int i{ 1 }; i < argc; ++i)
        {
            std::string argument{ argv[i] };
            if (argument == "func1")
            {
                func_vec.at(0)();
            }
            if (argument == "func2")
            {
                func_vec.at(1)();
            }
            if (argument == "func3")
            {
                func_vec.at(2)();
            }
        }

    }
    else
    {
        std::cout << "No command line arguments present.\n";
    }
    /***********************************************/

    
    //Exercise 2
    /***********************************************/
 
    std::unordered_map<char, std::function<double(double, double)>> func_map
    {
        {'+', oskar::add},
        {'-', oskar::subtract},
        {'*', oskar::multiply},
        {'/', oskar::divide},
        {'^', oskar::power},
        {'%', oskar::remainder}
    };

    std::string operation1{ "1.0 + 1.0" };  // 2.0
    std::string operation2{ "10.0 - 0.1" }; // 9.9
    std::string operation3{ "1.1 * 2.0" };  // 2.2
    std::string operation4{ "3.4 / 2.0" };  // 1.7
    std::string operation5{ "3.3 ^ 2.0" };  // 10.89
    std::string operation6{ "3.4 % 2.0" };  // -0.6
    
    double func_result1{ parse_line(operation1, func_map) };
    double func_result2{ parse_line(operation2, func_map) };
    double func_result3{ parse_line(operation3, func_map) };
    double func_result4{ parse_line(operation4, func_map) };
    double func_result5{ parse_line(operation5, func_map) };
    double func_result6{ parse_line(operation6, func_map) };

    std::cout << "func1: " << func_result1 << "\nfunc2: " << func_result2
        << "\nfunc3: " << func_result3 << "\nfunc4: " << func_result4
        << "\nfunc5: " << func_result5 << "\nfunc6: " << func_result6 << '\n';

    return 0;
}
