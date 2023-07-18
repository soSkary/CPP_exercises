#ifndef POSITIIVE_INTEGER_HPP
#define POSITIVE_INTEGER_HPP

#include <cstdint>
#include <stdexcept>

class positive_integer
{
public:
    positive_integer() : value{ 0 } { ++instances; }
    positive_integer(int initialization)
    {
        if (initialization < 0)
        {
            throw std::runtime_error("Can't initialize positive_integer with negative value");
        }
        value = initialization;
        ++instances;
    }
    positive_integer(const positive_integer& pos_int) : value{ pos_int.value } { ++instances; }

    //Default the copy assignment operator
    positive_integer& operator=(const positive_integer& pos_int) = default;

    //Overload operator<<
    friend std::ostream& operator<<(std::ostream& out, const positive_integer& pos_int);
    //Overloading operator+
    friend positive_integer operator+(const positive_integer& pos_int1, const positive_integer& pos_int2);
    friend positive_integer operator+(const positive_integer& pos_int, const int integer);
    friend positive_integer operator+(const int integer, const positive_integer& pos_int);

    //Overloading operator-
    friend positive_integer operator-(const positive_integer& pos_int1, const positive_integer& pos_int2);
    friend positive_integer operator-(const positive_integer& pos_int, const int integer);
    friend int operator-(const int integer, const positive_integer& pos_int);

    //Member functions
    void print() const;
    u_int16_t amount_of_class_instances() const;

private:
    uint16_t value;
    static inline uint16_t instances{0};
};


#endif
