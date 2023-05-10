//Author Oskar Siegfrids 10.5.2023
//A simple calculator to compare a season price to single ticket prices, and see which one is the cheaper alernative.
//Part of Brights C++ Program pre-studies


#include <iostream>
#include <limits>           //for std::numeric_limits

double getSinglePrice()
{
    while (true)
    {
        std::cout << "Please input cost of single gym visit: ";
        double price{};
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
        {
            return price;
        }
    }
}

double getSeasonPrice()
{
    while (true)
    {
        std::cout << "Please input cost of season ticket: ";
        double price{};
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
        {
            return price;
        }
    }
}

int getGymVisits()
{
    while (true)
    {
        std::cout << "Please input how many times you visit the gym: ";
        int visits{};
        std::cin >> visits;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
        {
            return visits;
        }
    }
}

void singleOrSeason(double singlePrice, double seasonPrice, int gymVisits)
{
    if (seasonPrice <= static_cast<double>(gymVisits) * singlePrice)
        std::cout << "The season ticket ("<< seasonPrice <<" money) will be the cheaper alternative for you!\n\n";
    else
        std::cout << "Buying single tickets will be cheaper for you and will cost you " << static_cast<double>(gymVisits) * singlePrice << " money.\n\n";
    
    std::cout << "With the price of a single ticket being\t" << singlePrice <<
                "\nand the price of a season ticket being\t " << seasonPrice <<
                "\nthe season ticket becomes the cheaper alternative after " << static_cast<int>(seasonPrice/singlePrice) <<
                " visits.\n\n";
}

int main ()
{
    double singlePrice { getSinglePrice() };

    double seasonPrice { getSeasonPrice() };

    int gymVisits { getGymVisits() };
    
    singleOrSeason(singlePrice, seasonPrice, gymVisits);

    return 0;
}