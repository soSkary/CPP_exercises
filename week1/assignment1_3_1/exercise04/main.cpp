#include <iostream>

int main()
{
    int a{ 25 };
    std::cout << "before code block, outside a: " << a << '\n';
    {
        int a{ 50 };
        std::cout << "inside code block a: " << a << '\n';
    }
    std::cout << "after code block, outside a: " << a << '\n';

    return 0;
}

/*
Discussion:
    Variables declared inside a block, has local scope. If there's a variable
    with the same name, the variable in the outside block will be hidden
    behind the variable inside the inner block.
*/
