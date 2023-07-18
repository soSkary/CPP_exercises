#include "figure.hpp"

#include <iostream>

int main()
{
    int robot{ 23 };
    char person{ 'd' };
    float alien{ 53321.2f };

    //Creating object and initializing tag and union to integer/robot
    Object object{ robot };
    std::cout << "Testing getter " << object.robot_identifier() << '\n';
    object.print();

    //Setting tag and union to character/person
    object.set_identifier(person);
    std::cout << "Testing getter " << object.person_identifier() << '\n';
    object.print();

    //Setting tag and union to floating_point/alien
    object.set_identifier(alien);
    std::cout << "Testing getter " << object.alien_identifier() << '\n';
    object.print();

    //The copy constructor is prohibited with the explicit specifier
    //object = robot;

    Object string_object{ "Erkki" };
    std::cout << "Testing getter " << string_object.person_identifier() << '\n';
    string_object.print();

    //This should fail
   // std::cout << "This assertion should fail: " << object.robot_identifier() << '\n';

    return 0;
}


/*
    The explicit specifier prohibits copy-initialization and
    copy-list-initialization (not applicable here).

    There is no use for a explicit destructor here, as Object doesn't reserve
    or use any resources, and therefore doesn't have anything to release.
*/
