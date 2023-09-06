#include "object.hpp"
#include "c_file_functionality.hpp"
#include <iostream>

int main()
{
//Exercise 1 - overloading operator <<
    std::cout << "Exercise 1\n\n";
    object robot(12);
    object person('c');
    object alien(43.21f);

    std::cout << robot << '\n';
    std::cout << person << '\n';
    std::cout << alien << '\n';


    //Exercise 2 - create right type from string
    std::cout << "\n\n";
    std::cout << "Exercise 2\n\n";

    object robot2{ object::create_from_string("13") };
    object person2{ object::create_from_string("thomas") };
    object alien2{ object::create_from_string("44.21") };

    std::cout << robot2 << '\n';
    std::cout << person2 << '\n';
    std::cout << alien2 << '\n';

    //Exercise 3 - 4 - read from file, create a container of objects and print it out
    std::cout << "\n\n";
    std::cout << "Exercise 3 & 4\n\n";
    
    object_group obj_grp{ object_group_from_file("objects.txt") };

    print_object_group(obj_grp);
    
    return 0;
}
