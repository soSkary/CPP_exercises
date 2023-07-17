#include "figure.hpp"

#include <iostream>

int main()
{
    Figure figure;
    //Setting tag and union to integer/robot
    figure.set_identifier(23);
    std::cout << "Testing getter " << figure.robot_identifier() << '\n';
    figure.print();

    //Setting tag and union to character/person
    figure.set_identifier('d');
    std::cout << "Testing getter " << figure.person_identifier() << '\n';
    figure.print();

    //Setting tag and union to floating_point/alien
    figure.set_identifier(53321.2f);
    std::cout << "Testing getter " << figure.alien_identifier() << '\n';
    figure.print();

    //This should fail
    std::cout << "This assertion should fail: " << figure.robot_identifier() << '\n';

    return 0;
}
