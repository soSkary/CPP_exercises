// board.h
#ifndef BOARD_H
#define BOARD_H

const int BOARD_SIZE{3};
const char PLAYER1{'X'};
const char PLAYER2{'O'};
const char EMPTY_SQUARE{' '};

// Function to print the game board
void print_board(const char board[][BOARD_SIZE]);

// Function to initialize the game board
void initialize_board(char board[][BOARD_SIZE]);

#endif
