#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

enum class Tag {
    integer,
    character,
    floating_point
};


struct Object
{

public:
    explicit Object(const int identifier);
    explicit Object(const char identifier);
    Object(const std::string& identifier);
    explicit Object(const float identifier);

    Tag get_type() const;
    
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
    Tag current_tag;
    union
    {
        int robot;
        char person;
        float alien;
    };
};



#endif
