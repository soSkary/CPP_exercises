#include "my_allocator.hpp"

#include <iostream>
int main()
{

    oskar::allocator<int, 64> alloc;

    int* ptr{ alloc.allocate(1) };

    return 0;

}
