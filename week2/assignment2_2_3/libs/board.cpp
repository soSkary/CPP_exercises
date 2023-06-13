#include "board.h"
#include "random.h"
#include "player.h"

#include <iostream>


//Function for filling out the game board with random spaces and obstacles
void fill_game_board_randomly(Board& game_board)
{
    for (int y {0}; y < 10; ++y)
    {
        for (int x{0}; x < 10; ++x)
        {
            int random_cell = random_0_3( mt );
            if (random_cell == 0)
                game_board[x][y].cell_type = 'O';
            else
                game_board[x][y].cell_type = ' ';
        }
    }
}

//Add player to board (default location x = 5, y = 0)
void add_player(Board& game_board, Player& player, int x, int y)
{
    game_board[x][y].cell_type = 'X';
    player.x = x;
    player.y = y;
}

//Print game board to screen
void print_game_board(const Board& game_board)
{
    for (int y{ 0 }; y < 10; ++y)
    {
        std::cout << '|';
        for (int x{ 0 }; x < 10; ++x)
        {
            std::cout << game_board[x][y].cell_type << ' ';
        }
        std::cout << "|\n";
    }
}

//Add treasures to game board
void add_treasures(Board& game_board, int treasures)
{
    int counter{ 0 };
    while (counter < treasures)
    {
        int x = random_0_9(mt);
        int y = random_0_9(mt);

        if (( x == 5 && y == 0 )|| game_board[x][y].cell_type == '$')
        {
            continue;
        }
        else
        {
            game_board[x][y].cell_type = '$';
            ++counter;
        }
    }
}

//Check if move is possible
bool is_possible_move(const Board& game_board, int x, int y)
{
    //Check if trying to go over the boards edges or towards an obstacle
    if (x > 9 || x < 0 || y > 9 || y < 0 || game_board[x][y].cell_type == 'O')
    {
        return false;
    }
    else
        return true;
}
