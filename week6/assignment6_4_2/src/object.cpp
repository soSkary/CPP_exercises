#include "object.hpp"
#include "c_file_functionality.hpp"

#include <cassert>
#include <charconv>
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
//could be removed, as operator<< is overloaded
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
//overloaded operator << for streaming out an object
std::ostream& operator<<(std::ostream& out, const object& obj)
{
    out << "type: ";
    switch (obj.get_type())
    {
    case tag::integer:
        out << "robot, identifier: " << obj.robot_identifier();
        break;
    case tag::character:
        out << "person, identifier: " << obj.person_identifier();
        break;
    case tag::floating_point:
        out << "alien, identifier: " << obj.alien_identifier();
        break;
    }
    return out;
}
//for checking if string is float
bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}
//for checking if string is int
bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

object object::create_from_string(std::string_view input)
{
    bool str_is_int{ is_int(input) };
    bool str_is_float{ is_float(input) };
    assert(!input.empty() && "can't create_from_string() - input empty!");

    if (!str_is_float && !str_is_int)
    {
        return object{ input.front() };
    }
    if (str_is_int)
    {
        return object{ std::stoi(static_cast<std::string>(input)) };
    }
    else //str_is_float
    {
        return object{ std::stof(static_cast<std::string>(input)) };
    }
}

//use c_file_functionality to create a group of objects from a file
object_group object_group_from_file(const std::string& open_file_named)
{
    object_group new_object_group;
    c_file_functionality open_file{ open_file_named };
    std::string read_object{ open_file.read_line() };

    while (!read_object.empty())
    {
        new_object_group.push_back(object::create_from_string(read_object));
        read_object = open_file.read_line();
    }

    return new_object_group;
}

void print_object_group(const object_group& obj_grp)
{
    for (const auto& elem : obj_grp)
    {
        std::cout << elem << '\n';
    }
}
