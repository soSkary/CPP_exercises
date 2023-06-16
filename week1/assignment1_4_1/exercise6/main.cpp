/*
Exercise 6
Write a C++ program that simulates a simple game.
Implement a function called play_game() that takes a number as rounds and checks if it is within a certain range.
Use assert statements to check if the number is within the range of 1 to 100 (inclusive).
If the assertion fails, display an error message indicating that the number is out of range.
Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/

#include "random.h"     //for main "thing" of this "beautiful" game :D

//#define NDEBUG
#include <cassert>
#include <iostream>

bool play_game(int rounds)
{
    assert(rounds > 0 && rounds <= 100 && "rounds not within specified range 1 - 100 (inclusive)\n");

    int sum{ 0 };
    for (int i{ 0 }; i < rounds; ++i)
    {
        int flip_coin{Random::get(1,2)};
        std::cout << "Flipping a coin!\t";
        if (flip_coin == 1)
            std::cout << "You LOST this round!\n";
        else
        {
            std::cout << "You WON this round!\n";
            ++sum;
        }
    }
    std::cout << "\nYou won " << sum << " of " << rounds << " rounds...\n\n";
    if (sum > (rounds / 2))
        return true;
    else
        return false;
}

int how_many_rounds()
{
    std::cout << "Please input how many rounds you would like to play the FABULOUS GAME! (1 - 100)\n";
    int rounds;
    std::cin >> rounds;
    return rounds;
}

int main()
{
    int rounds{ how_many_rounds() };

    if (play_game(rounds))
        std::cout << "You have won the game! WooHooo!\n\n";
    else
        std::cout << "You lost the game! Better luck next time!\n\n";

    return 0;
}
