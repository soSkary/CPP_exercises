#include <iostream>
#include <iomanip>          //for std::setprecision()
#include <limits>           //for std::numeric_limits
#include <cmath>            //for std::pow(base, exp)

constexpr double PI { 3.1416 };

double circleCircumference (double radius)
{
    return radius * 2 * PI ;
}

double circleArea (double radius)
{
    return std::pow(radius, 2) * PI;
}

char getDimensionType ()
{
    std::cout << "Do you want to calculate circle area or circumference? (a for area, c for circumference) ";
    char circleType{};

    while (true)
    {
        std::cin >> circleType;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (circleType == 'a' || circleType == 'c')
            break;
    }
    return circleType;
}

double getRadius()
{
    std::cout << "Please enter a radius for circle: ";
    double radius{};

    while (true)
    {
        std::cin >> radius;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return radius;
}

void printResult(double radius, char dimensionType)
{
    if (dimensionType == 'a')
        std::cout << "The area of a circle with the given radius " << radius << " is: " << std::fixed << std::setprecision(2) << circleArea(radius) << '\n';
    else if (dimensionType == 'c')
        std::cout << "The circumference of a circle with the given radius " << radius << " is: " << std::fixed << std::setprecision(2) << circleCircumference(radius) << '\n';
}

int main ()
{
    
    double radius{getRadius()};

    char dimensionType{getDimensionType()};

    printResult(radius, dimensionType);

   
    return 0;
}