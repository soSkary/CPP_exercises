#include <iostream>

void conditional_func()
{
    int a{ 25 };

    std::cout << "a before conditional: " << a << '\n';
    
    if (a < 50)
    {
        //square a
        a *= a;
    }

    std::cout << "a after conditional: " << a << '\n';
}

int main()
{
    conditional_func();

    return 0;
}
/*
Discussion:
    Conditionals have local scope, so they can access the outside scope, but
    the outside can't access them directly. The scope is similar to that of a
    normal block.

    One thing about conditionals:
    if (a==1)
        a = 2 //if you use a conditional without the code blocks, only the first
                line after the conditional will be executed inside the conditional
*/
