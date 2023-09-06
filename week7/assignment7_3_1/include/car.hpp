#ifndef EXERCISE_CAR_HPP
#define EXERCISE_CAR_HPP

#include "helper_class_templates.hpp"

#include <iostream>
#include <string>

class car : public compare<car>, public type<car>
{
public:
    car() = default;
    car(const std::string& new_make, const std::string& new_model, int new_year)
        : make{ new_make }, model{ new_model }, year{ new_year } {}

    constexpr bool operator<(const car& other) const
    {
        if (make == other.make)
        {
            if (model == other.model)
            {
                return year < other.year;
            }
            return model < other.model;
        }
        return make < other.make;
    }

    friend std::ostream& operator<<(std::ostream& out, const car& c);

private:
    std::string make;
    std::string model;
    int year;

};

inline std::ostream& operator<<(std::ostream& out, const car& c)
{
    out << c.make << ", " << c.model << ", " << c.year;
    return out;
}

#endif
