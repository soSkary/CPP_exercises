#include "exercise1.hpp"
#include "exercise2_3.hpp"
#include <iostream>


int main()
{
    //EXERCISE 1

    std::cout << "EXERCISE 1\n\n";
    exercise1 ex1{ exercise1::create() };
    std::cout << "\n\n";

    std::cout << "EXERCISE 3(and 2)\n\n";

    {
        animal a;
        a.what_are_you();
    }
    std::cout << '\n';
    {
        bird b;
        b.what_are_you();
        b.w.what_are_you();
        b.e.what_are_you();
    }
    std::cout << '\n';
    {
        dog d;
        d.what_are_you();
        d.e.what_are_you();
    }
    std::cout << '\n';
    {

        //Commented out the parrot.what_are_you() to show how bird.what_are_you() is inherited.

        parrot p;
        p.what_are_you();
        p.e.what_are_you();
        p.w.what_are_you();
    }
    std::cout << '\n';

    return 0;
}
