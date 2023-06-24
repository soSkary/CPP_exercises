#include "utils.h"

#include <iostream>
#include <limits>

int Utility::get_user_int()
    {
        int value;
        while (true)
        {
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
    
    double Utility::get_user_double()
    {
        double value;
        while (true)
        {
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

    std::string Utility::get_user_string()
    {
        std::string value;
        while (true)
        {
            std::getline(std::cin >> std::ws, value);
        
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

    char Utility::get_user_char()
    {
        char value;
        while (true)
        {
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
    char Utility::to_lowercase(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
