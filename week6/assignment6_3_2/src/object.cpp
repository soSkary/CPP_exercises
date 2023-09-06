#include "object.hpp"

#include <cassert>
#include <iostream>

object::object(const int identifier) : current_tag{tag::integer}, robot{identifier} {}
object::object(const char identifier) : current_tag{tag::character}, person{identifier} {}
object::object(const std::string& identifier) : current_tag{ tag::character }
{
    person = identifier.at(0);
}
object::object(const float identifier) : current_tag{tag::floating_point}, alien{identifier} {}

tag object::get_type() const
{
    return current_tag;
}

int object::robot_identifier() const
{
    assert(current_tag == tag::integer && "current_tag isn't tag::integer\n");
    return robot;
}

char object::person_identifier() const
{
    assert(current_tag == tag::character && "current_tag isn't tag::character\n");
    return person;
}

float object::alien_identifier() const
{
    assert(current_tag == tag::floating_point && "current_tag isn't tag::floating_point\n");
    return alien;
}


void object::set_identifier(const int id)
{
    current_tag = tag::integer;
    robot = id;
}

void object::set_identifier(const char first_letter)
{
    current_tag = tag::character;
    person = first_letter;
}

void object::set_identifier(const std::string& name)
{
    assert(name.size() != 0 && "name doesn't exist\n");
    current_tag = tag::character;
    person = name.at(0);
}

void object::set_identifier(const float wavelength)
{
    current_tag = tag::floating_point;
    alien = wavelength;
}

void object::print() const
{
    switch (current_tag)
    {
    case tag::integer:
        std::cout << "The object is of type robot, has the identifier \'"
            << robot << "\' and has an int identifier\n";
        break;
    case tag::character:
        std::cout << "The object is of type person, has the identifier \'"
            << person << "\' and has a char identifier\n";
        break;
    case tag::floating_point:
        std::cout << "The object is of type alien, has the identifier \'"
            << alien << "\' and has a float identifier\n";
        break;
    }
}
