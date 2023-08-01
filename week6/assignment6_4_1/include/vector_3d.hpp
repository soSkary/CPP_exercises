#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

#include <cstdint>
#include <iostream>

namespace exercise
{
    //exercise::hello() 
    void hello();
    
    class vector_3d
    {
    public:

        vector_3d(const int32_t new_x, const int32_t new_y, const int32_t new_z);

        //overloaded operator<< as friend function
        friend std::ostream& operator<<(std::ostream& out, const vector_3d& v3d);

        //overloaded operators + and - as friend functions
        friend vector_3d operator+(const vector_3d& v3d_1, const vector_3d& v3d_2);
        friend vector_3d operator-(const vector_3d& v3d_1, const vector_3d& v3d_2);

        //overloaded operator += and -= as member functions
        vector_3d& operator+=(const vector_3d& v3d);
        vector_3d& operator-=(const vector_3d& v3d);

        //exercise::vector_3d::hello()
        static void hello();

    private:
        int32_t x{ 0 };
        int32_t y{ 0 };
        int32_t z{ 0 };
    };
}


#endif
