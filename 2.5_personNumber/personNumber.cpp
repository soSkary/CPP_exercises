//Author Oskar Siegfrids 11.5.2023
//A program that checks if a Finnish personnumber belongs to a woman or a man.

#include <iostream>
#include <limits>       //for std::numeric_limits

long int getPersonNumber()
{
    long int personNumber;
    while (true)
    {
        std::cout << "Please input a personnumber without the space symbol (- or A): ";
        long int personNumber{};
        std::cin >> personNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return personNumber;
    }

}
bool checkIfWoman (long int personNumber)
{
    if (personNumber > 320000000) // if the personnumber only includes digits remove last digit
    {
        personNumber /= 10;
    }
    
    if (personNumber % 2 == 0)
        return true;
    else
        return false;
}
void printIfWoman(bool woman)
{
    if (woman)
        std::cout << "The personnumber belongs to a woman!\n";
    else
        std::cout << "The personnumber belongs to a man!\n";
}

int main ()
{
    long int personNumber {getPersonNumber()};
    bool woman {checkIfWoman(personNumber)};

    printIfWoman(woman);

    return 0;
}