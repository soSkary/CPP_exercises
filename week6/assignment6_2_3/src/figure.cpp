#include "figure.hpp"

#include <cassert>
#include <iostream>

Object::Object(const int identifier) : current_tag{Tag::integer}, robot{identifier} {}
Object::Object(const char identifier) : current_tag{Tag::character}, person{identifier} {}
Object::Object(const float identifier) : current_tag{Tag::floating_point}, alien{identifier} {}

Tag Object::get_type() const
{
    return current_tag;
}

int Object::robot_identifier() const
{
    assert(current_tag == Tag::integer && "Tag isn't integer");
    return robot;
}

char Object::person_identifier() const
{
    assert(current_tag == Tag::character && "Tag isn't character");
    return person;
}

float Object::alien_identifier() const
{
    assert(current_tag == Tag::floating_point && "Tag isn't floating_point");
    return alien;
}


void Object::set_identifier(const int id)
{
    current_tag = Tag::integer;
    robot = id;
}

void Object::set_identifier(const char first_letter)
{
    current_tag = Tag::character;
    person = first_letter;
}

void Object::set_identifier(const float wavelength)
{
    current_tag = Tag::floating_point;
    alien = wavelength;
}

void Object::print() const
{
    switch (current_tag)
    {
    case Tag::integer:
        std::cout << "The Object is of type robot, has the identifier \'"
            << robot << "\' and has an int identifier\n";
        break;
    case Tag::character:
        std::cout << "The Object is of type person, has the identifier \'"
            << person << "\' and has a char identifier\n";
        break;
    case Tag::floating_point:
        std::cout << "The Object is of type alien, has the identifier \'"
            << alien << "\' and has a float identifier\n";
        break;
    default:
        std::cout << "error: Unknown type\n";
        break;
    }
}
