#include "vector_3d.hpp"
#include <iostream>


namespace exercise
{
    void hello()
    {
        std::cout << "Hello from within the namespace exercise::!\n";
    }

    void vector_3d::hello()
    {
        std::cout << "Hello from within vector_3d within namespace exercise::!\n";
    }
    vector_3d::vector_3d(const int32_t new_x, const int32_t new_y, const int32_t new_z)
    : x{ new_x }, y{ new_y }, z{ new_z } {}


    std::ostream& operator<<(std::ostream& out, const vector_3d& v3d)
    {
        out << '(' << v3d.x << ", " << v3d.y << ", " << v3d.z << ')';
        return out;
    }

    vector_3d operator+(const vector_3d& v3d_1, const vector_3d& v3d_2)
    {
        return { v3d_1.x + v3d_2.x, v3d_1.y + v3d_2.y, v3d_1.z + v3d_2.z };
    }

    vector_3d operator-(const vector_3d& v3d_1, const vector_3d& v3d_2)
    {
    return { v3d_1.x - v3d_2.x, v3d_1.y - v3d_2.y, v3d_1.z - v3d_2.z };
    }
    
    vector_3d& vector_3d::operator+=(const vector_3d& v3d)
    {
        x += v3d.x;
        y += v3d.y;
        z += v3d.z;
        
        return *this;
    }

    vector_3d& vector_3d::operator-=(const vector_3d& v3d)
    {
        x -= v3d.x;
        y -= v3d.y;
        z -= v3d.z;
        
        return *this;
    }
}



