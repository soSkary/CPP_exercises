#include "exercises.h"
#include <algorithm>

std::string recursive_reverse_string(std::string str, int index)
{

    //Base case, check if we're over halfway through our string
    if (index > (str.size() - 1) / 2)
    {
        return str;
    }
    //If base case not met, swap at the same index from both ends of string
    std::swap(str.at(index), str.at(str.size() - index - 1));

    //recurse and add one to index
    str = recursive_reverse_string(str, index + 1);
    return str;
    
}

int greatest_common_divisor(int a, int b)
{
    //The base case, if either of the integers get down to zero the other is the answer
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    //get division and remainder
    int division{ a / b };
    int remainder{ a % b };

    //recurse with the value a split by value b and restructured
    int gcd = greatest_common_divisor((a - remainder) / division, remainder);
    return gcd;
}


long long my_power(long long base, int exponent)
{
    //Check the base case, if exponent reaches 0, return 1;
    if (exponent == 0)
    {
        return 1;
    }

    //recursively multiply base with return value of 
    return base *= my_power(base, exponent - 1);

}
