#include "animal.hpp"
#include "text_parsing.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::string address{ "animals.csv" };

    std::vector<std::unique_ptr<animal>> animal_ptr_vec{create_vec_of_animal_ptr_from_file(address)};
   
    for (const auto& animal_ptr : animal_ptr_vec)
    {
        std::cout << animal_ptr->name << " the " << animal_ptr->type
            << (animal_ptr->breathes_air() ? " breathes air," : " doesn't breathe air, ")
            << "has " << animal_ptr->number_of_legs() << " legs and says: " << animal_ptr->make_sound() << '\n';
    }


    /*
    We can use the virtual functions, and dynamic polymorphism, with pointers, as
    references can't be saved inside a container.

    We can't do this using static polymorphism as all the information needed is not known during
    compile time (as we read the types from disk during runtime)
    */

    return 0;
}
