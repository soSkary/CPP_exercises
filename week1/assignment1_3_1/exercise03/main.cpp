#include <iostream>

void calculate()
{
    int a{ 10 };
    std::cout << "calculate() a: " << a << '\n';
}

int main()
{
    int a{ 5 };
    std::cout << "main() a: " << a << '\n';
    calculate();

    return 0;
}
/*
Discussion:
    Local scope is accessable only inside the code block,
    global scope is accessable everywhere within the program.
*/
