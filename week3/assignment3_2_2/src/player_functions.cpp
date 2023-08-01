#include <iostream>
#include "board.h"
#include "player_functions.h"
#include "game_functions.h"

void play_against_another_player()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    initialize_board(board);

    print_board(board);

    // True if PLAYER1 turn
    bool player1_turn{true};

    bool game_over{false};

    int empty_spaces{9};

    char won{};

    // Game loop
    while (!game_over)
    {
        make_move(player1_turn, board);

        print_board(board);

        --empty_spaces;

        won = check_if_won(board);

        if (won == PLAYER1)
        {
            std::cout << "Player 1 won! GAME IS OVER!\n\nReturning to main Game Menu ..\n\n";

            break;
        }
        if (won == PLAYER2)
        {
            std::cout << "Player 2 won! GAME IS OVER!\n\nReturning to main Game Menu ..\n\n";

            break;
        }

        // Changes the player turn
        player1_turn = !player1_turn;

        if (empty_spaces == 0)
        {
            std::cout << "It's a draw! GAME IS OVER!\n\nReturning to main Game Menu ..\n\n";
            break;
        }
    }
}
