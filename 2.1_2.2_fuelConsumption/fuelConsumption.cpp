// Author Oskar Siegfrids

// This is a short program for calculating the cost of driving a car.
// The user get's to input consumption, fuel type and distance drived.

#include <iostream>
#include <iomanip> //for std::setprecision()
#include <limits>  //for std::numeric_limits

enum class FuelType
{
    gasoline,
    diesel,
    electricity,

    max_types
};

FuelType getFuelType()
{
    while (true)
    {
        std::cout << "Please input type of fuel - (g)asoline, (d)iesel or (e)lectricity: ";
        char fuel{};
        std::cin >> fuel;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (fuel)
        {
        case 'g':
        case 'G':
            return FuelType::gasoline;
        case 'd':
        case 'D':
            return FuelType::diesel;
        case 'e':
        case 'E':
            return FuelType::electricity;
        default:
            std::cerr << "Incorrect letter, please input 'g' for gasoline, 'd' for diesel or 'e' for electricity\n";
        }
    }
}

double getDistance()
{
    while (true)
    {
        std::cout << "Please input the distance driven in km: ";
        double distance{};
        std::cin >> distance;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Incorrect input, try again!\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return distance;
        }
    }
}

double getConsumption(FuelType fuelType)
{
    while (true)
    {
        if (fuelType == FuelType::electricity)
        {
            std::cout << "Please input the consumption in kWh/100km: ";
        }
        else
        {
            std::cout << "Please input the consumption in l/100km: ";
        }
        double consumption{};
        std::cin >> consumption;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Incorrect input, try again!\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return consumption;
        }
    }
}

// gas 95E10 and diesel mean prices/liter https://www.polttoaine.net - data fetched 8.5.2023
constexpr double gasPrice{1.946};
constexpr double dieselPrice{1.842};
// electricity 7 day mean price per kWh  https://sahko.tk - data fetched 8.5.2023
constexpr double electricityPrice{0.0782};

double calculatePrice(FuelType fuelType, double distance, double consumption)
{
    switch (fuelType)
    {
    case FuelType::gasoline:
        return gasPrice * (distance / 100.0) * consumption;
    case FuelType::diesel:
        return dieselPrice * (distance / 100.0) * consumption;
    case FuelType::electricity:
        return electricityPrice * (distance / 100.0) * consumption;
    default:
        std::cerr << "\n\nError: Unidentified fuel type. Returning -1\n\n";
        return -1;
    }
}

void printCostOfDriving(FuelType fuelType, double distance, double consumption, double price)
{
    std::cout << "The cost of driving " << distance << " km using a";
    switch (fuelType)
    {
    case FuelType::gasoline:
        std::cout << " gasoline powered ";
        break;
    case FuelType::diesel:
        std::cout << " diesel powered ";
        break;
    case FuelType::electricity:
        std::cout << " electric ";
        break;
    default:
        std::cerr << "\n\nError. Unidentified fuel type!\n\n";
        return;
    }
    std::cout << "vehicle consuming " << consumption;
    if (fuelType == FuelType::electricity)
        std::cout << "kWh/100km ";
    else
        std::cout << "l/100km ";
    std::cout << "costs " << std::fixed << std::setprecision(2) << price << " €.\n";
}

int main()
{
    std::cout << "This is a program for calculating the cost of driving in euros and cents.\n\n";

    FuelType fuelType{getFuelType()};

    double distance{getDistance()};

    double consumption{getConsumption(fuelType)};

    double price{calculatePrice(fuelType, distance, consumption)};

    std::cout << "\n\n";

    printCostOfDriving(fuelType, distance, consumption, price);

    std::cout << "\n\n";

    return 0;
}
