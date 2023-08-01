#include <iostream>

void function_x()
{
    static unsigned long long int a{ 0 };
    std::cout << "At the beginning of function_x a is:\t" << a << '\n';
    if (a == 0 || a == 1)
        a += 1;
    else if (a >= 65536)
        a *= 2;
    else
        a = (a) * (a);
    std::cout << "At the end of function_x a is:\t\t" << a << '\n';
}

int main()
{
    std::cout << "Calling function_x() ten times, to demonstrate static variable.\n";
    for (int i{0}; i < 10; ++i)
    {
        std::cout << "ROUND " << i + 1 << "!\n";
        function_x();
    }

    return 0;
}


/*
Discussion:

    Static variables have program lifetime after they are created. So they retain
    their value between function calls. Also, static variables can be used, in
    certain situations, where you need a variable, but only one instance of it,
    and always creating it over and over is expensive (ie. for custom defined
    types).

    I also think there's static functions, but am not quite sure, that what or
    how they function (pun intended ;D ).

*/
