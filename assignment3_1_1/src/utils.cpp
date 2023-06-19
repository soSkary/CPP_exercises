#include "utils.h"

#include <stdexcept>

int division(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw std::runtime_error("Can't divide by zero!\n");
    }
    return dividend / divisor;
}
