#ifndef HELPER_CLASS_TEMPLATES_HPP
#define HELPER_CLASS_TEMPLATES_HPP

#include <iostream>
#include <typeinfo>


template <typename Derived>
struct compare
{

};

template <typename Derived>
struct type
{
    constexpr void get_type() const
    {
        std::cout << "Class is of type: " << typeid(Derived).name() << '\n';
    }
};


//Overloading operators for compare, to function as a common class to inherit comparing operators from
//This way I only have to define operator< inside all derived classes, and these will take care of the rest 
template <typename Derived>
constexpr bool operator>(const compare<Derived>& lhs, const compare<Derived>& rhs)
{
    return static_cast<const Derived&>(rhs) < static_cast<const Derived&>(lhs);
}

template <typename Derived>
constexpr bool operator!=(const compare<Derived>& lhs, const compare<Derived>& rhs)
{
    return (static_cast<const Derived&>(lhs) < static_cast<const Derived&>(rhs))
        || (static_cast<const Derived&>(lhs) > static_cast<const Derived&>(rhs));
}

template <typename Derived>
constexpr bool operator==(const compare<Derived>& lhs, const compare<Derived>& rhs)
{
    return !(static_cast<const Derived&>(lhs) != static_cast<const Derived&>(rhs));
}

template <typename Derived>
constexpr bool operator<=(const compare<Derived>& lhs, const compare<Derived>& rhs)
{
    return !(static_cast<const Derived&>(lhs) > static_cast<const Derived&>(rhs));
}

template <typename Derived>
constexpr bool operator>=(const compare<Derived>& lhs, const compare<Derived>& rhs)
{
    return !(static_cast<const Derived&>(lhs) < static_cast<const Derived&>(rhs));
}

#endif
