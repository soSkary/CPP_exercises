#ifndef BOARD_H
#define BOARD_H
#include "player.h"

#include <array>



struct Cell
{
    char cell_type{};
};

using Board = std::array<std::array<Cell, 10>, 10>;

//Function for filling out the game board with random spaces and obstacles
void fill_game_board_randomly(Board& game_board);

//Add player to board (default location x = 5, y = 0)
void add_player(Board& game_board, Player& player, int x = 5, int y = 0);

//Print game board to screen
void print_game_board(const Board& game_board);

//Add treasures to game board
void add_treasures(Board& game_board, int treasures);

//Check if move is possible
bool is_possible_move(const Board& game_board, int x, int y);

#endif
