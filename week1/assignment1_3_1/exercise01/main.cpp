#include <iostream>

void print_value()
{
    int a{ 25 };
    std::cout << a << '\n';
}

int main()
{
    print_value();

    return 0;
}


/*
Discussion:
The variable a, declared and initialized inside print_value()
can only be accessed inside the function itself. The function can be
accessed from everywhere withing the program, as it has global scope
and program lifetime.
*/
