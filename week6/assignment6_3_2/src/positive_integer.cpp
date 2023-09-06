#include "positive_integer.hpp"
#include <iostream>
#include <limits>

//Define the MAX_VALUE for unsgined 16-bit integer
constexpr uint16_t MAX_VALUE{std::numeric_limits<uint16_t>::max()};

positive_integer::positive_integer(int initialization)
{
    if (initialization < 0)
        {
            throw std::runtime_error("Can't initialize positive_integer with negative value");
    }
    if (initialization > MAX_VALUE)
    {
        throw std::runtime_error("Integer used in initialization is too big");
    }
        value = initialization;
        ++instances;
}

//Overloaded ostream operator<<
std::ostream& operator<<(std::ostream& out, const positive_integer& pos_int)
{
    out << pos_int.value;
    return out;
}

//Overloaded operator+ with bounds checking
positive_integer operator+(const positive_integer& pos_int1, const positive_integer& pos_int2)
{
    int32_t return_value{pos_int1.value + pos_int2.value};
    if (return_value > MAX_VALUE)
    {
        return MAX_VALUE;
    }
    else
    {
        return pos_int1.value + pos_int2.value;
    }
}

positive_integer operator+(const positive_integer& pos_int, const int integer)
{
    int32_t return_value{pos_int.value + integer};
    if (return_value > MAX_VALUE)
    {
        return_value = MAX_VALUE;
    }
    if (return_value < 0)
    {
        return_value = 0;
    }
    return return_value;
}

positive_integer operator+(const int integer, const positive_integer& pos_int)
{
    return operator+(pos_int, integer);
}

//Overloaded operator- with bounds checking
positive_integer operator-(const positive_integer& pos_int1, const positive_integer& pos_int2)
{
    int32_t return_value{ pos_int1.value - pos_int2.value };
    if (return_value > MAX_VALUE)
    {
        return_value = MAX_VALUE;
    }
    if (return_value < 0)
    {
        return_value = 0;
    }
    return return_value;
}

positive_integer operator-(const positive_integer& pos_int, const int integer)
{
    int32_t return_value{ pos_int.value - integer };
    if (return_value > MAX_VALUE)
    {
        return_value = MAX_VALUE;
    }
    if (return_value < 0)
    {
        return_value = 0;
    }
    return return_value;
}

int operator-(const int integer, const positive_integer& pos_int)
{
    return integer - pos_int.value;
}

//Print function, uses the overloaded operator<<
void positive_integer::print() const
{
    std::cout << value;
}

u_int16_t positive_integer::amount_of_class_instances() const
{
    return instances;
}
