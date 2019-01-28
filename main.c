#include <stdio.h>
#include <stdlib.h>
void choosemax(int board1[8][8],int board2[8][8]);
void CheckBoard(char board[8][8],char player,int secondBoard[8][8], int thirdBoard[8][8]);
int CheckTile(char board[8][8],char player, int direction, int x, int y,int secondboard[8][8],int value);
int main(int argc, char *argv[])
{
    char player;
    int i,j;
    
    char mainBoard[8][8]={{"00000000"},{"00000000"},{"00000000"},{"00021110"},{"00112000"},{"00000000"},{"00000000"},{"00000000"}};
    int secondBoard[8][8];
   const int thirdBoard[8][8];
    // char  mainBoard;
    // for(i=0;i<8;i++){
    //     for(j=0;j<8;j++)
    //         mainBoard[i][j]=argv[i+1][j];
    // }
  //  player=argv[i+1][0];
    player='2';
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            secondBoard[i][j]=0;
        }
    }
    CheckBoard(mainBoard,player,secondBoard, thirdBoard);
    for( i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%2c",mainBoard[i][j]);
 
        }
        printf("\n");
    }
    printf("\n");
    for( i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",secondBoard[i][j]);
 
        }
        printf("\n");
    }
    choosemax(secondBoard,thirdBoard);
    return 0;
}
void CheckBoard(char board[8][8],char player,int secondBoard[8][8], int thirdBoard[8][8]){
    int i,j;
    int direction;       // 1,2,3,4,5,6,7,8 : r,ru,u,lu,l,ld,d,rd
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]==player){
                for(direction=1;direction<10;direction++){
                    
                    CheckTile(board,player,direction,i,j,secondBoard,thirdBoard[i][j]);
                }

            }
        }
    }
}
int CheckTile(char board[8][8],char player, int direction, int x, int y, int secondboard[8][8],int value){
   #pragma region SWITCH
    switch(direction){
    case(1):
        if(x<7)
        x++;
    break;
     case(2):
        if(x<7)
        x++;
        if(y>0)
        y--;
    break;
     case(3):
        if(y>0)
        y--;
    break;
     case(4):
        if(x>0)
        x--;
        if(x>0)
        y--;
    break;
    case(5):
        if(x>0)
        x--;
    break;
     case(6):
        if(x>0)
        x--;
        if(y<7)
        y++;
    break;
     case(7):
        if(y<7)
        y++;
    break;
     case(8):
        if(y<7)
        y++;
        if(x<7)
        x++;
    break;
    }
    #pragma endregion
    if(player=='1'){
        if(board[x][y]=='2'){
        //   printf("%d", value);
            value++;
            // printf("x=%d , y=%d\n",x,y);
            if(x<0||x>7||y<0||y>7)
                return 0;
            CheckTile(board,player,direction,x,y,secondboard,value);
        }
    }
    if(player=='2'){
        if(board[x][y]=='1'){
            // printf("%d", value);
            value++;
            
            // printf("x=%d , y=%d\n",x,y);
            if(x<1||x>6||y<1||y>6)
                return 0;
            CheckTile(board,player,direction,x,y,secondboard,value);
        }
    } if(board[x][y]=='0')
        if(value>0)
        secondboard[x][y]=value;
    return 0;
}


void choosemax(int board1[8][8],int board2[8][8])
{
    int x,j,y,i,max;
    int board3[8][8];

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            board3[i][j]=board1[i][j]+board2[i][j];
        }
    }

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(board1[i][j]==0)
            {
                board3[i][j]=0;
            }
        }
    }

    max=board3[0][0];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(board3[i][j] > max)
            {
                max=board3[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("\n%d,%d",x,y);
}