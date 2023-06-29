#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H


//Templates - so they should be defined in header, as the compiler will need to see the full definition!
template <typename T>
T add(const T a, const T b)
{
    return a + b;
}

template <typename T>
T subtract(const T a, const T b)
{
    return a - b;
}

template <typename T>
T multiply(const T a, const T b)
{
    return a * b;
}

template <typename T>
T divide(const T a, const T b)
{
    return a / b;
}

char get_user_char();
double get_user_double();
double get_operation_and_values();


#endif
