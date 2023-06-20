/* main.cpp
 *
 * Group assignment: Oskar, Anna & Heidi
 *
 * Tic Tac Toe Game
 *  - You can choose to play against another player or an AI
 *  - A board is created as a console application
 *  - Each player is represented by a O or an X
 *  - Minimax algorithm is implemented to calculate the best possible moves for
 *    AI and 2then choose the best move it could play
 **/
#include <algorithm>
#include <iostream>
#include <vector>
#include "player_functions.h"
#include "ai_functions.h"

int main()
{
    while (true)
    {
        std::cout << "\n******** Tic Tac Toe Game ********\n\n";

        std::cout << "(1) Play against another player\n";
        std::cout << "(2) Play against AI\n";
        std::cout << "(3) Quit\n\n";

        std::cout << "Choose Game Mode: ";
        int mode{};
        std::cin >> mode;

        switch (mode)
        {
        case 1:
            play_against_another_player();
            break;
        case 2:
            play_against_ai();
            break;
        case 3:
            std::cout << "Bye bye!\n";
            return 0;
        }
    }

    return 0;
}
