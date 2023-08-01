#include "vector_3d.hpp"
#include <iostream>

int main()
{

    //Exercise 1
    exercise::hello();
    exercise::vector_3d::hello();

    //Exercise 2
    exercise::vector_3d v3d{ 3, 3, 3 };
  

    std::cout << "Testing overloaded << operator for printing the vector to console:\n\n"
        << v3d << '\n';


    //Exercise 3
    exercise::vector_3d v3d_1{ v3d + v3d };

    std::cout << v3d << " + " << v3d << " = " << v3d_1 << '\n';

    exercise::vector_3d v3d_2{ v3d_1 - v3d };

    std::cout << v3d_1 << " - " << v3d << " = " << v3d_2 << '\n';


    std::cout << v3d_1 << " += " << v3d << ": " << (v3d_1 += v3d) << '\n';


    std::cout << v3d_1 << " -= " << v3d << ": " << (v3d_1 -= v3d) << '\n';
    
    std::cout << v3d_1 << " -= " << exercise::vector_3d{ 10, 10, 10 }
    << ":  " << (v3d_1 -= exercise::vector_3d{ 10,10,10 }) << '\n';

    return 0;

}
