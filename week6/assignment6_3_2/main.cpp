#include "c_file_functionality.hpp"
#include "object.hpp"
#include "positive_integer.hpp"

#include <iostream>

int main()
{

    try
    {
        c_file_functionality text_file("text.txt");

        std::cout << "File size: " << text_file.file_size() << " bytes\n";
        std::cout << text_file.read_line();

        std::cout << "File size: " << text_file.file_size() << " bytes\n";
        std::cout << text_file.read_line();
        std::cout << text_file.read_line();
        std::cout << "File size: " << text_file.file_size() << " bytes\n";
        std::cout << text_file.read_line();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    std::cout << '\n';


    int robot{ 23 };
    char person{ 'd' };
    float alien{ 53321.2f };

    //Creating object and initializing tag and union to integer/robot
    object object1{ robot };
    std::cout << "Testing getter " << object1.robot_identifier() << '\n';
    object1.print();

    //Setting tag and union to character/person
    object1.set_identifier(person);
    std::cout << "Testing getter " << object1.person_identifier() << '\n';
    object1.print();

    //Setting tag and union to floating_point/alien
    object1.set_identifier(alien);
    std::cout << "Testing getter " << object1.alien_identifier() << '\n';
    object1.print();

    //The copy constructor is prohibited with the explicit specifier
    //object1 = robot;

    object string_object{ "Erkki" };
    std::cout << "Testing getter " << string_object.person_identifier() << '\n';
    string_object.print();

    //This should fail
   // std::cout << "This assertion should fail: " << object.robot_identifier() << '\n';


    try
    {
        
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
