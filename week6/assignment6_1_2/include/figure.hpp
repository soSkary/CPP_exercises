#ifndef FIGURE_H
#define FIGURE_H

enum class Tag {
    integer,
    character,
    floating_point
};


struct Figure
{

public:

    //Getters for union
    int robot_identifier() const;
    char person_identifier() const;
    float alien_identifier() const;

    //Setters for tag and union
    void set_identifier(const int id);
    void set_identifier(const char first_letter);
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
