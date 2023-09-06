#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

enum class tag {
    integer,
    character,
    floating_point
};


struct object
{

public:
    explicit object(const int identifier);
    explicit object(const char identifier);
    explicit object(const std::string& identifier);
    explicit object(const float identifier);

    tag get_type() const;

    //Getters for union
    int robot_identifier() const;
    char person_identifier() const;
    float alien_identifier() const;

    //Setters for tag and union
    void set_identifier(const int id);
    void set_identifier(const char first_letter);
    void set_identifier(const std::string& name);
    void set_identifier(const float wavelength);

    void print() const;


private:

    //Tag for keeping track of current union
    tag current_tag;
    union
    {
        int robot;
        char person;
        float alien;
    };
};



#endif
