
#include <iostream>
void second_func(int a);

void first_func()
{
    int a{ 25 };
    std::cout << "a inside first_func(): " << a << '\n';
    second_func(a);
    std::cout << "a again inside first_func(): " << a << '\n';
}

void second_func(int a)
{
    a *= a;
    std::cout << "a inside second_func(): " << a << '\n';
}

int main()
{
    first_func();

    return 0;
}

/*
Discussion:
    The lifetime of variables inside functions depends on a couple of thins:
    1) If a variable is declared inside a function, it has scope lifetime (same as function)
    2) If a variable is passed to the function as a copy, it has scope lifetime (same as function)
    3) If a variable is passed as (&)reference, or a (*)pointer, it has lifetime of the caller variable,
        as it is the same variable.

    The default is, that parameters are passed as a copy,  thus having scope lifetime.
*/
