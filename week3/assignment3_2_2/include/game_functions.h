// game_functions.h
#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include "board.h"

char check_if_won(const char board[BOARD_SIZE][BOARD_SIZE]);

// Function to make move
void make_move(const bool player1_turn, char board[][BOARD_SIZE]);

#endif
