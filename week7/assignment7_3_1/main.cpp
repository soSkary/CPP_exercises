#include "helper_class_templates.hpp"
#include "object_to_be_compared.hpp"
#include "car.hpp"

#include <iostream>

int main()
{
    std::cout << "EXERCISE 1\n\n";
    object_to_be_compared o_a{ 1 };
    object_to_be_compared o_b{ 2 };

    std::cout << std::boolalpha << "(o_a{ 1 } > o_b{ 2 }): " << (o_a > o_b) << '\n';
    std::cout << "(o_a{ 1 } < o_b{ 2 }): " << (o_a < o_b) << '\n';
    std::cout << "(o_a{ 1 } >= o_b{ 2 }): " << (o_a >= o_b) << '\n';
    std::cout << "(o_a{ 1 } >= o_a{ 1 }): " << (o_a >= o_a) << '\n';
    std::cout << "(o_a{ 1 } <= o_b{ 2 }): " << (o_a <= o_b) << '\n';
    std::cout << "(o_a{ 1 } <= o_a{ 1 }): " << (o_a <= o_a) << '\n';

    std::cout << "(o_a{ 1 } != o_b{ 2 }): " << (o_a != o_b) << '\n';
    std::cout << "(o_a{ 1 } == o_b{ 2 }): " << (o_a == o_b) << '\n';

    car car1{ "Toyota", "Camry", 2020 };
    car car2{ "Volkswagen", "Passat", 2021 };
    car car2_a{ "Volkswagen", "Polo", 2021 };
    car car2_b{ "Volkswagen", "Passat", 2022 };

    car car1_copy{ car1 };

    std::cout << car1 << " < " << car2 << ": " << (car1 < car2) << '\n';
    std::cout << car1 << " > " << car2 << ": " << (car1 > car2) << '\n';
    std::cout << car1 << " == " << car2 << ": " << (car1 == car2) << '\n';
    std::cout << car1 << " != " << car2 << ": " << (car1 != car2) << '\n';

    std::cout << car2 << " < " << car2_a << ": " << (car2 < car2_a) << '\n';
    std::cout << car2 << " < " << car2_b << ": " << (car2 < car2_b) << '\n';
    
    std::cout << car1 << " < " << car1_copy << ": " << (car1 < car1_copy) << '\n';
    std::cout << car1 << " > " << car1_copy << ": " << (car1 > car1_copy) << '\n';
    std::cout << car1 << " == " << car1_copy << ": " << (car1 == car1_copy) << '\n';
    std::cout << car1 << " != " << car1_copy << ": " << (car1 != car1_copy) << '\n';

    std::cout << "Integer is of type: " << typeid(int).name() << '\n';
    
    car1.get_type();
    o_a.get_type();
   

    return 0;
}
