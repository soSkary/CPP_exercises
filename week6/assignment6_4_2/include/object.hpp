#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <string_view>
#include <vector>

enum class tag {
    integer,
    character,
    floating_point
};


class object
{

public:
    explicit object(const int identifier);
    explicit object(const char identifier);
    explicit object(const std::string& identifier);
    explicit object(const float identifier);

    static object create_from_string(std::string_view input);
    
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

std::ostream& operator<<(std::ostream& out, const object& obj);

using object_group = std::vector<object>;

object_group object_group_from_file(const std::string& open_file_named);
void print_object_group(const object_group& obj_grp);

#endif
