// ai_functions.h
#ifndef AI_FUNCTIONS_H
#define AI_FUNCTIONS_H

#include "board.h"

int minimax(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces, bool is_ai_turn);

void ai_turn(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces);

void play_against_ai();

#endif
