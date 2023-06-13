#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

namespace Utility
{
    
    int get_user_int()
    {
        int value;
        while (true)
        {
            std::cout << "Please input integer value: ";
            std::cin >> value;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                return value;
            }
        }
    }

}

#endif //UTILS_H
