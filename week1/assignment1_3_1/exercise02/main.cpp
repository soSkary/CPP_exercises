#include <iostream>

int main()
{
    while (true)
    {
        int meaning_of_life{ 42 };

        std::cout << "The meaning of life is " << meaning_of_life << '\n';

        if (meaning_of_life == 42)
            break;
    }
    return 0;
}
/*
Discussion:
    If you try to access the variable outside of the loop,
    you will get a compile error, as the variable is not defined.
*/
