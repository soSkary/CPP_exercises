
#include "customFunc.h"

#include <iostream>





int main ()
{
    std::string test { "Oskar" };

    std::cout << "test before reversal: " << test << '\n';

    test = reverseString(test);

    std::cout << "test after reversal: " << test << '\n';
    
    return 0;
}
