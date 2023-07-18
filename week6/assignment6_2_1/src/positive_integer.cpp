#include "positive_integer.hpp"
#include <iostream>


std::ostream& operator<<(std::ostream& out, const positive_integer& pos_int)
{
    out << pos_int.value;
    return out;
}

positive_integer operator+(const positive_integer& pos_int1, const positive_integer& pos_int2)
{
    return pos_int1.value + pos_int2.value;
}

positive_integer operator+(const positive_integer& pos_int, const int integer)
{
    return pos_int.value + integer;
}

positive_integer operator+(const int integer, const positive_integer& pos_int)
{
    return operator+(pos_int, integer);
}

positive_integer operator-(const positive_integer& pos_int1, const positive_integer& pos_int2)
{
    int return_value{ pos_int1.value - pos_int2.value };
    if (return_value <= 0)
    {
        return 0;
    }
    return return_value;
}

positive_integer operator-(const positive_integer& pos_int, const int integer)
{
    int return_value{ pos_int.value - integer };
    if (return_value <= 0)
    {
        return 0;
    }
    return return_value;
}

int operator-(const int integer, const positive_integer& pos_int)
{
    return integer - pos_int.value;
}

void positive_integer::print() const
{
    std::cout << value;
}

u_int16_t positive_integer::amount_of_class_instances() const
{
    return instances;
}
