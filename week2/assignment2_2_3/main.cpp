#include "random.h"
#include "board.h"
#include "player.h"

#include <iostream>

bool game_actions(Board& game_board, Player& player)
{
    //Get user input for movement or quitting the game
    char input;
    std::cin >> input;
    int x = player.x;
    int y = player.y;

    switch (input)
    {
    case 'w':
        --y;
        break;
    case 'a':
        --x;
        break;
    case 's':
        ++y;
        break;
    case 'd':
        ++x;
        break;
    case 'q':
        return false;
    default:
        return true;
    }
    //Check if the given move is possible, i.e. not obstacle or wall
    if (is_possible_move(game_board, x, y))
    {
        //If cell that player tries to move to is a treasure
        if (game_board[x][y].cell_type == '$')
        {
            //Swap 'X' to treasure and previous to ' '
            game_board[player.x][player.y].cell_type = ' ';
            game_board[x][y].cell_type = 'X';
            //Update player location and amount of treasures
            player.x = x;
            player.y = y;
            ++player.treasures;
            
        }
        else
        {
            //If tile is empty, swap places between 'X' and ' '
            std::swap(game_board[player.x][player.y], game_board[x][y]);
            //Update player location
            player.x = x;
            player.y = y;
        }
    }
    return true;
}

void game_loop(Board& game_board, Player& player)
{
    //The main game loop
    while (true)
    {
        
        std::cout
            << "Please input direction:\n"
            << "w - for up | s - for down | a - for left | d - for right:\n"
            << "q - for quit | TREASURES FOUND: " << player.treasures << '\n';

        //Print game board
        print_game_board(game_board);

        //Check if victory conditions are met
        if (player.y == 9 && player.treasures == 5)
        {
            std::cout << "!!!You have won the game!!!\n";
            return;
        }
        //Get input from user. game_actions returns false, if player wants to quit
        if (!game_actions(game_board, player))
        {
            return;
        }
    }
}

int main()
{
//Create instances of Board and Player, fills the board randomly, adds player and treasures
//and starts the main game loop

Board game_board;
Player player{ 0,0,0 };

fill_game_board_randomly(game_board);

add_player(game_board, player);

add_treasures(game_board, 5);

game_loop(game_board, player);

}



