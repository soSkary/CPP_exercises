#ifndef POSITIIVE_INTEGER_HPP
#define POSITIVE_INTEGER_HPP

#include <cstdint>
#include <stdexcept>

class positive_integer
{
public:
    positive_integer() : value{ 0 } { ++instances; }
    positive_integer(const positive_integer& pos_int) : value{ pos_int.value } { ++instances; }
    positive_integer(int initialization);
    ~positive_integer() { --instances; }
    
    //Default the copy assignment operator
    positive_integer& operator=(const positive_integer& pos_int) = default;

    //Member functions
    void print() const;
    u_int16_t amount_of_class_instances() const;

    //Overload operator<<
    friend std::ostream& operator<<(std::ostream& out, const positive_integer& pos_int);
    //Overload operator+
    friend positive_integer operator+(const positive_integer& pos_int1, const positive_integer& pos_int2);
    friend positive_integer operator+(const positive_integer& pos_int, const int integer);
    friend positive_integer operator+(const int integer, const positive_integer& pos_int);

    //Overload operator-
    friend positive_integer operator-(const positive_integer& pos_int1, const positive_integer& pos_int2);
    friend positive_integer operator-(const positive_integer& pos_int, const int integer);
    friend int operator-(const int integer, const positive_integer& pos_int);

private:
    uint16_t value;
    static inline uint16_t instances{0};
};


#endif
