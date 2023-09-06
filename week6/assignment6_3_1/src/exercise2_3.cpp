#include "exercise2_3.hpp"
#include <iostream>

wings::wings()
{
    std::cout << "...grew wings!\n";
}

wings::~wings()
{
    std::cout << "...the wings withered away...\n";
}

void wings::what_are_you()
{
    std::cout << "I am wings!\n";
}

eyes::eyes()
{
    std::cout << "...got eyes to see with!\n";
}

eyes::~eyes()
{
    std::cout << "...became blind.\n";
}

void eyes::what_are_you()
{
    std::cout << "I am eyes!\n";
}

animal::animal()
{
    std::cout << "An animal was born!\n";
}

animal::~animal()
{
    std::cout << "The animal lived a long and prosperous life,"
        << "\nbut eventually died and moved on to a better place.\n";
}

void animal::what_are_you()
{
    std::cout << "I am an animal!\n";
}

bird::bird()
{
    std::cout << "\tIt's a bird!\n";
}

bird::~bird()
{
    std::cout << "\tIt's not a bird?!\n";
}

void bird::what_are_you()
{
    std::cout << "I am a bird!\n";
}

parrot::parrot()
{
    std::cout << "\t\tThe bird is a parrot!\n";
}

parrot::~parrot()
{
    std::cout << "\t\tThe bird is a parrot no more!\n";
}

// void parrot::what_are_you()
// {
//     std::cout << "I am a parrot!\n";
// }


dog::dog()
{
    std::cout << "\tIt's a dog!\n";
}

dog::~dog()
{
    std::cout << "\tIt's a dog no more!\n";
}

void dog::what_are_you()
{
    std::cout << "I am a dog!\n";
}
