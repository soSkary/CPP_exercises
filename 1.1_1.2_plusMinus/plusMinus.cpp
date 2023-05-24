#include <iostream>
#include <limits>

template <typename T>
T plusMinus (T first, T second, char oper)
{
    while (true)
    {
        switch (oper)
        {
            case '+':
                return first + second;
            case '-':
                return first - second;
            default:
            std::cout << "Invalid operator, returning 0";
            return 0;
        }
    }
}
double getNumber()
{
    double input{};
    while (true)
    {
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
            continue;
        }
        break;
    }
    return input;
}

char getOperator()
{
    char input{};
    while (true)
    {
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        if (input != '+' && input != '-')
        {
            std::cout << "Invalid operator, please input + or -: ";
            continue;
        }
        break;
    }
    return input;
}

int main ()
{
std::cout << "Please, input first number to be operated on: ";
double first {getNumber()};

std::cout << "Please, input operator for addition (+) or subtraction (-): ";
char oper {getOperator()};

std::cout << "Please, input second number to be operated on: ";
double second {getNumber()};



std::cout << first << ' ' << oper << ' ' << second << " = " << plusMinus(first, second, oper) << '\n';

return 0;

}