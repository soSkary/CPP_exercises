#ifndef OBJECT_TO_BE_COMPARED_HPP
#define OBJECT_TO_BE_COMPARED_HPP

#include "helper_class_templates.hpp"

class object_to_be_compared : public compare<object_to_be_compared>, public type<object_to_be_compared>
{
public:
    object_to_be_compared(int new_value) : value{ new_value } {}

    bool operator<(const object_to_be_compared& other) const
    {
        return value < other.value;
    }


private:
    int value;
};


#endif
