#include <stdio.h>
#include <stdlib.h>
// FILE *cfptr;
void choosemax(int board1[8][8], int board2[8][8]);
void CheckBoard(char board[8][8], char player, int secondBoard[8][8], int thirdBoard[8][8]);
int CheckTile(char board[8][8], char player, int direction, int x, int y, int secondboard[8][8], int value, int optionalVal);
int main(int argc, char *argv[])
{

    char player;
    int i, j;
    // cfptr = fopen("PlayLog.txt", "r+");
    //  char mainBoard[8][8]={{"00000000"},{"00000000"},{"00000000"},{"00021110"},{"00112000"},{"00000000"},{"00000000"},{"00000000"}};
    int secondBoard[8][8] = {{0}};
    const int thirdBoard[8][8] = {{100, -50, 20, 10, 10, 20, -50, 100}, {-50, -60, 0, 0, 0, 0, -60, -50}, {20, 0, 0, 0, 0, 0, 0, 20}, {10, 0, 0, 0, 0, 0, 0, 10}, {10, 0, 0, 0, 0, 0, 0, 10}, {20, 0, 0, 0, 0, 0, 0, 20}, {-50, -60, 0, 0, 0, 0, -60, -50}, {100, -50, 20, 10, 10, 20, -50, 100}};
    char mainBoard[8][8];
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            mainBoard[i][j] = argv[i + 1][j];
    }
    player = argv[i + 1][0];

    //  player='1';
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            secondBoard[i][j] = 0;
        }
    }
    CheckBoard(mainBoard, player, secondBoard, thirdBoard);
    // for (i = 0; i < 8; i++)
    // {
    //     for (j = 0; j < 8; j++)
    //     {
    //         fprintf(cfptr, "%2c", mainBoard[i][j]);
    //     }
    //     fprintf(cfptr, "\n");
    // }
    // fprintf(cfptr, "\n");
    // for (i = 0; i < 8; i++)
    // {
    //     for (j = 0; j < 8; j++)
    //     {
    //         fprintf(cfptr, "%d ", secondBoard[i][j]);
    //     }
    //     fprintf(cfptr, "\n");
    // }
    choosemax(secondBoard, thirdBoard);
    // fclose(cfptr);
    return 0;
}
void CheckBoard(char board[8][8], char player, int secondBoard[8][8], int thirdBoard[8][8])
{
    int i, j;
    int direction; // 1,2,3,4,5,6,7,8 : r,ru,u,lu,l,ld,d,rd
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == player)
            {
                for (direction = 1; direction < 9; direction++)
                {

                    CheckTile(board, player, direction, i, j, secondBoard, 0,thirdBoard[i][j]);
                }
            }
        }
    }
}
int CheckTile(char board[8][8], char player, int direction, int x, int y, int secondboard[8][8], int value, int optionalVal)
{
#pragma region SWITCH
    switch (direction)
    {
    case (1):
        if (x < 7)
            x++;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (2):
        if (x < 7)
            x++;
        else
        {
            value = 0;
            return 0;
        }
        if (y > 0)
            y--;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (3):
        if (y > 0)
            y--;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (4):
        if (x > 0)
            x--;
        if (x > 0)
            y--;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (5):
        if (x > 0)
            x--;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (6):
        if (x > 0)
            x--;
        else
        {
            value = 0;
            return 0;
        }
        if (y < 7)
            y++;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (7):
        if (y < 7)
            y++;
        else
        {
            value = 0;
            return 0;
        }
        break;
    case (8):
        if (y < 7)
            y++;
        else
        {
            value = 0;
            return 0;
        }
        if (x < 7)
            x++;
        else
        {
            value = 0;
            return 0;
        }
        break;
    }
#pragma endregion
    if (player == '1')
    {
        if (board[x][y] == '2')
        {
            //   printf("%d", value);
            value++;
            // printf("x=%d , y=%d\n",x,y);
            if (x < 0 || x > 7 || y < 0 || y > 7)
                return 0;
            CheckTile(board, player, direction, x, y, secondboard, value,optionalVal);
        }
    }
    if (player == '2')
    {
        if (board[x][y] == '1')
        {
            // printf("%d", value);
            value++;

            // printf("x=%d , y=%d\n",x,y);
            if (x < 1 || x > 6 || y < 1 || y > 6)
                return 0;
            CheckTile(board, player, direction, x, y, secondboard, value,optionalVal);
        }
    }
    if (board[x][y] == '0')
        if (value != 0)
            secondboard[x][y] = value+optionalVal;
    return 0;
}

void choosemax(int board1[8][8], int board2[8][8])
{
    int x = 0, j, y = 0, i, max;
    int board3[8][8];

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            board3[i][j] = (board1[i][j] == 0) ? 0 : board1[i][j] + board2[i][j];
        }
    }

    max = -1000;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board3[i][j] != 0 && board3[i][j] > max)
            {

                max = board3[i][j];
                x = j;
                y = i;
            }
        }
    }
    printf("%d %d", x, y);
    // fprintf(cfptr, "\n%d %d\n", x, y);
}