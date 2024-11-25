#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void store_int(char *current_move)
{
    *current_move -= '0';
}




void print_Board(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        printf("%c", board[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" | ");
        }
    }
}

bool check_Winner(char board[])
{
    // Check for win condition

    // 1. check rows
    for (int j = 0; j < 9; j += 3)
    {
        if (board[j] != ' ' && board[j] == board[j + 1] && board[j + 1] == board[j + 2])
        {
            return true;
        }
    }

    // 2. check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[j] != ' ' && (board[j] == board[j + 3]) && (board[j + 3] == board[j + 6]))
        {
            return true;
        }
    }

    // 3. Diagonal 1st
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
    {
       return true;
    }

    // 4.Diagonal 2nd
    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
    {
        return true;
    }

    return false; // one one hA
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, current_player, current_move;
    for (int i = 0; i < 9; i++)
    {
        current_player = (i % 2 == 0) ? 'X' : 'O';
        printf("Enter Your Move Player %c (1-9):\n ", current_player);
        scanf("%c",&current_move);
        fflush(stdin);
        store_int(&current_move);
        if (board[current_move - 1] != ' ' || current_move < 1 || current_move > 9)
        {
            printf("INVLAID MOVE PLAYER %c TRY AGAIN:\n", current_player);
            i--;
            continue;
        }
        board[current_move - 1] = current_player;
        print_Board(board);
        if(check_Winner(board))
        {
            printf("Player %c Wins! ",current_player);
            return 0;
        }

    }
    printf("Game was a Draw! ");
    return 0;
}
