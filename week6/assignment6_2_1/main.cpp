#include "positive_integer.hpp"
#include <iostream>

int main()
{
    //Exercise 1
    try
    {
        std::cout << "EXERCISE 1\n\n";
        positive_integer pos_int{ };
        std::cout << "Should be 0: " << pos_int << '\n';
        positive_integer pos_int1{ 42 };
        std::cout << "Should be 42: ";
        pos_int1.print();
        std::cout << '\n';

        positive_integer pos_int2{ pos_int1 };
        std::cout << "Should also be 42: ";
        pos_int2.print();
        std::cout << '\n';

        //This should throw an exception:
        positive_integer pos_int_negative{ -34 };
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n\n\n";

    //Exercise 2

    std::cout << "EXERCISE 2\n\n";
    positive_integer pos_int1{ 20 };
    positive_integer pos_int2{ 40 };

    pos_int1 = pos_int1 + pos_int2;
    std::cout << "pos_int1{ 20 } + pos_int2{ 40 } equals: " << pos_int1 << '\n';
    
    pos_int1 = pos_int1 + 20;
    std::cout << "pos_int1{ 60 } + 20 equals: " << pos_int1 << '\n';

    pos_int1 = 20 + pos_int1;
    std::cout << "pos_int1{ 80 } + 20 equals: " << pos_int1 << '\n';
    std::cout << "Should equal to 100\n\n";

    pos_int1 = pos_int1 - pos_int2;
    std::cout << "pos_int1{ 100 } - pos_int2{ 40 } equals: " << pos_int1 << '\n';

    pos_int1 = pos_int1 - 20;
    std::cout << "pos_int1{ 60 } - 20 equals: " << pos_int1 << '\n';

    std::cout << "20 - pos_int1{ 40 } equals: " << 20 - pos_int1 << '\n';

    std::cout << "\n\n\n";

    //Exercise 3
    std::cout << "EXERCISE 3\n\n";
    std::cout << "The amount of instances of positive_integer: " << pos_int1.amount_of_class_instances() << '\n';
    std::cout << "This should be the same: " << pos_int2.amount_of_class_instances() << '\n';

    return 0;
}
