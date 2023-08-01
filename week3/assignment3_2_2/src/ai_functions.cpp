#include <iostream>

#include "board.h"
#include "ai_functions.h"
#include "game_functions.h"

int minimax(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces, bool is_ai_turn)
{
    // This should return a char
    char result{check_if_won(board)};
    if (result == PLAYER1)
    {
        return -10;
    }
    if (result == PLAYER2)
    {
        return 10;
    }
    if (empty_spaces == 0)
    {
        return 0;
    }

    if (is_ai_turn)
    {
        int best_score{-1000};
        for (int x{0}; x < BOARD_SIZE; ++x)
        {
            for (int y{0}; y < BOARD_SIZE; ++y)
            {
                if (board[x][y] == EMPTY_SQUARE)
                {
                    board[x][y] = PLAYER2;
                    int score = minimax(board, empty_spaces - 1, false);
                    best_score = std::max(score, best_score);
                    board[x][y] = EMPTY_SQUARE;
                }
            }
        }
        return best_score;
    }
    else
    {
        int best_score{1000};
        for (int x{0}; x < BOARD_SIZE; ++x)
        {
            for (int y{0}; y < BOARD_SIZE; ++y)
            {
                if (board[x][y] == EMPTY_SQUARE)
                {
                    board[x][y] = PLAYER1;
                    int score{minimax(board, empty_spaces - 1, true)};
                    best_score = std::min(score, best_score);
                    board[x][y] = EMPTY_SQUARE;
                }
            }
        }
        return best_score;
    }
}

void ai_turn(char board[BOARD_SIZE][BOARD_SIZE], int empty_spaces)
{
    std::cout << "AI turn:\n";
    int best_score{-1000};
    int best_x{};
    int best_y{};

    for (int x{0}; x < BOARD_SIZE; ++x)
    {
        for (int y{0}; y < BOARD_SIZE; ++y)
        {
            if (board[x][y] == EMPTY_SQUARE)
            {
                board[x][y] = PLAYER2;
                int score{minimax(board, empty_spaces - 1, false)};
                if (score > best_score)
                {
                    best_score = score;
                    best_x = x;
                    best_y = y;
                }
                board[x][y] = EMPTY_SQUARE;
            }
        }
    }
    board[best_x][best_y] = PLAYER2;
}

void play_against_ai()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    initialize_board(board);

    print_board(board);

    // True if PLAYER1 turn
    bool player1_turn{true};

    char won;

    int empty_spaces{9};

    // Game loop
    while (true)
    {
        make_move(player1_turn, board);

        --empty_spaces;

        print_board(board);

        won = check_if_won(board);

        if (won == PLAYER1)
        {
            std::cout << "Player won! GAME IS OVER!\n\nReturning to main Game Menu ..\n\n";
            break;
        }

        if (empty_spaces == 0)
        {
            std::cout << "It's a draw! GAME IS OVER!\n\nReturning to main Game Menu ..\n\n";
            break;
        }

        player1_turn = false;

        ai_turn(board, empty_spaces);

        --empty_spaces;

        print_board(board);

        won = check_if_won(board);

        player1_turn = true;

        if (won == PLAYER2)
        {
            std::cout << "The AI won! GAME IS OVER\n\nReturning to main Game Menu ..\n\n";
            break;
        }
    }
}
