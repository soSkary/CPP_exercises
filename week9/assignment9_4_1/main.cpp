#include "animals.hpp"

#include <iostream>
#include <string>
#include <variant>
#include <vector>

//Exercise 1
void print_figure_type(std::variant<int, std::string, float>& figure)
{
    if (std::holds_alternative<int>(figure))
    {
        std::cout << "int";
    }
    else if (std::holds_alternative<std::string>(figure))
    {
        std::cout << "std::string";
    }
    else
    {
        std::cout << "float";
    }
}

// helper type for the Exercise2
template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

int main()
{
    //Exercise 1
    std::cout << "Exercise 1\n\n";
    std::variant<int, std::string, float> figure{ 26 };

    std::cout << "figure type: ";
    print_figure_type(figure);
    std::cout << "\nfigure value: " << std::get<int>(figure) << "\n\n";


    figure = "Matti";
    
    std::cout << "figure type: ";
    print_figure_type(figure);
    std::cout << "\nfigure value: " << std::get<std::string>(figure) << "\n\n";

    figure = 42.1f;

    std::cout << "figure type: ";
    print_figure_type(figure);
    std::cout << "\nfigure value: " << std::get<float>(figure) << "\n\n";

    //Exercise 2

    std::cout << "\nExercise 2\n\n";
    
    std::variant<bird, parrot, dog, fish> animal1;

    animal1 = bird{};

    std::variant<bird, parrot, dog, fish> animal2{ parrot{} };

    std::variant<bird, parrot, dog, fish> animal3{ dog{} };

    std::variant<bird, parrot, dog, fish> animal4{ fish{} };

    std::vector<std::variant<bird, parrot, dog, fish>> animal_vector{ animal1, animal2, animal3, animal4 };
    
    //Using the void visitor
    std::cout << "Using the void visitor\n";
    
    for (auto& animal_variant : animal_vector)
    {
        std::visit([](auto&& animal)
            {
                std::cout << animal.name << " has " << animal.number_of_legs()
                    << " legs and says: \"" << animal.make_sound() << "\"\n";
            }, animal_variant);
    }

    std::cout << "\nUsing a type-matching visitor\n";
    
    for (auto& animal_variant : animal_vector)
    {
        std::visit(overloaded
            {
                [](bird&)   { std::cout << "This is a bird!\n";     },
                [](parrot&) { std::cout << "This is a parrot!\n";   },
                [](dog&)    { std::cout << "This is a dog!\n";      },
                [](fish&)   { std::cout << "This is a fish!\n";     }
            }, animal_variant);
    }



    
    return 0;
}
