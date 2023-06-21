#include "math_utils.h"
#include <stdexcept>

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("Can't divide by zero");
    }
        return a / b;
}
