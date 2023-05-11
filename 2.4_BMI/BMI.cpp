//Author Oskar Siegfrids 11.5.2023

//A simple BMI-calculator

#include <iostream>
#include <iomanip>          //for std::setprecision()
#include <limits>           //for std::numeric_limits

double getHeight()
{
    double height{};
    while (true)
    {
        std::cout << "Please input height of the person in cm: ";
        std::cin >> height;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (height < 50.0 || height > 250.0 )
            std::cout << "Please enter correct height (50 < height < 250 cm)\n";
        else
            return height;
    }
}
double getWeight()
{
    double weight{};
    while (true)
    {
        std::cout << "Please input weight of the person in kg: ";
        std::cin >> weight;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (weight < 30 || weight > 150)
            std::cout << "Please enter correct number for weight (30 < weight < 150 kg)\n";
        else
            return weight;
    }
}
double calculateBMI(double height, double weight)
{
    return weight / (height/100 * height/100);
}
void printBMI(double height, double weight, double bmi)
{
    std::cout << "The BMI for a person who is " << height << " cm long and weighs " << weight << " kg is: " << 
                std::fixed << std::setprecision(1) << bmi << '\n';

    if (bmi < 18.5)
        std::cout << "You are under-weight.\n";
    else if (bmi >=18.5 && bmi <= 25.0)
        std::cout << "You are normal weight.\n";
    else 
        std::cout << "You are over-weight.\n";
}
int main ()
{
    double height {getHeight()};
    double weight {getWeight()};
    double bmi {calculateBMI(height, weight)};
    printBMI(height,weight,bmi);

    return 0;

}