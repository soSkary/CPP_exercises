#include "figure.hpp"

#include <cassert>
#include <iostream>


int Figure::robot_identifier() const
{
    assert(current_tag == Tag::integer && "Tag isn't integer");
    return robot;
}

char Figure::person_identifier() const
{
    assert(current_tag == Tag::character && "Tag isn't character");
    return person;
}

float Figure::alien_identifier() const
{
    assert(current_tag == Tag::floating_point && "Tag isn't floating_point");
    return alien;
}


void Figure::set_identifier(const int id)
{
    current_tag = Tag::integer;
    robot = id;
}

void Figure::set_identifier(const char first_letter)
{
    current_tag = Tag::character;
    person = first_letter;
}

void Figure::set_identifier(const float wavelength)
{
    current_tag = Tag::floating_point;
    alien = wavelength;
}

void Figure::print() const
{
    switch (current_tag)
    {
    case Tag::integer:
        std::cout << "The figure is of type robot, and has the identifier \'"
            << robot << "\' and has an int identifier\n";
        break;
    case Tag::character:
        std::cout << "The figure is of type person, and has the identifier \'"
            << person << "\' and has a char identifier\n";
        break;
    case Tag::floating_point:
        std::cout << "The figure is of type alien, and has the identifier \'"
            << alien << "\' and has a float identifier\n";
        break;
    default:
        std::cout << "error: Unknown type\n";
        break;
    }
}
