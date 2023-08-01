#include <iostream>
#include <vector>

#include "board.h"

// Function to print the game board
void print_board(const char board[][BOARD_SIZE])
{
    std::cout << " ___________ \n";
    for (int i{0}; i < BOARD_SIZE; ++i)
    {
        std::cout << "| ";
        for (int j{0}; j < BOARD_SIZE; ++j)
        {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n ___________ \n";
    }
    std::cout << '\n';
}

// Function to initialize the game board
void initialize_board(char board[][BOARD_SIZE])
{
    for (int i{0}; i < BOARD_SIZE; ++i)
    {
        for (int j{0}; j < BOARD_SIZE; ++j)
        {
            board[i][j] = EMPTY_SQUARE; // empty cells
        }
    }
}
