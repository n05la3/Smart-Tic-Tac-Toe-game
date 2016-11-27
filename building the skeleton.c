#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int Row,Column,NoMoves,Cordinate,expert;
char player1[18],player2[18]; //string variable to hold names of players
int validMove,GameHasBeenWon,GameHasBeenDrawn;
char currentSymbol ;
char Board[3][3];//2d arrays where the tokens can be placed
int mode;
char ch;
void help(void)
{
    if(mode==3)
        puts("\n 1: If You Wish To Play With Computer  OR \n\n 2: If You Wish Play With Human!"
        "\n\n Use Numbers 1 To 9 Place Tour Token in Your desired Grid \n\n\t(Type in a character to continue)");
    if(expert==3)
    {
        puts("\n 0 BASIC: computer reasons randomly\n\n"
            " 1 EXPERT: computer is wiser but unable to make certain decisions\n\n"
            " 2 PRO: Computer Knows Exactly What To Do\n\n"
            " tips: Is it possible to win??? Else defend!!!\n\n\n\t(KEY in a character to continue)\n");
    }
}

void getPlayerName(void)//used to get the name of the players
{
    if(mode==1)
    {
        printf("Player X enter your name: ");
        scanf("%s", player1);
        puts("");
        printf("\t\t%s (player X) Vs Computer (player O)\n\n", player1);
    }
    else{
        printf("Player X enter your name: ");
        scanf("%s", player1);
        puts("");
        printf("Playerr O enter your name: ");
        scanf("%s", player2);
        puts("");
        printf("\t\t%s (player X) Vs %s (player O)\n\n", player1,player2);
        }
}

void convert2DTo1D(void)//makes it possible to use intergers 1 to 9 instead of using rows and columns
{
             switch(Cordinate)
            {
                      case 1:
                      Row=0;
                      Column=0;
                      break;
                      case 2:
                      Row=0;
                      Column=1;
                      break;
                      case 3:
                      Row=0;
                      Column=2;
                      break;
                      case 4:
                      Row=1;
                      Column=0;
                      break;
                      case 5:
                      Row=1;
                      Column=1;
                      break;
                      case 6:
                      Row=1;
                      Column=2;
                      break;
                      case 7:
                      Row=2;
                      Column=0;
                      break;
                      case 8:
                      Row=2;
                      Column=1;
                      break;
                      case 9:
                      Row=2;
                      Column=2;
                      break;
                      default:
                      Row=3;
                      Column=3;
                      break;

                    }
}


int main(void)
{
    return 0;

}