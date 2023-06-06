//author Oskar Siegfrids 11.5.2023
//A simple program to check if one will get rich by working ;)

#include <iostream>

int calculateHowLong()
{
    int sum{1};
    int pay{1};
    long int days{1};
    while (sum < 10000000)
    {
        pay *= 2;
        sum += pay;
        ++days;
    }
    return days;
}

int main ()
{
    std::cout << "If you gain one money the first day, and your pay is always doubled the next day, how long until you have 10 million money?\n";

    int howLong{calculateHowLong()};
    std::cout << "It would take you " << howLong << " days to get together your first 10 millions! Not a bad gig!\n\n";

    return 0;
}