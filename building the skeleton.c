#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>//to pass in the srand function
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
void computerPlay(void)
{
       do{
                    Cordinate=rand()%10;
                    switch(Cordinate)//This construct ensures computer never guesses and invalid number!
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
        }while(checkValidMove(Row,Column)!=1);
}

int smartMove(void)
{
    if(Cordinate==5)
    {
        if((rand()%2)==1)
           Cordinate=7;
        else
           Cordinate=3;
    }
    else computerPlay();
    return Cordinate;
}

int smartAttack(void)//Makes game more interesting as computer knows exactly what to do.
{
   if(Board[0][0]=='O'&&Board[0][1]=='O'&&Board[0][2]==' ')
        Cordinate=3;
   else if(Board[1][0]=='O'&&Board[1][1]=='O'&&Board[1][2]==' ')
        Cordinate=6;
   else if(Board[2][0]=='O'&&Board[2][1]=='O'&&Board[2][2]==' ')
        Cordinate=9;
   else if(Board[0][0]=='O'&&Board[1][0]=='O'&&Board[2][0]==' ')
        Cordinate=7;
   else if(Board[0][1]=='O'&&Board[1][1]=='O'&&Board[2][1]==' ')
        Cordinate=8;
   else if(Board[0][2]=='O'&&Board[1][2]=='O'&&Board[2][2]==' ')
        Cordinate=9;
   else if(Board[0][0]=='O'&&Board[1][1]=='O'&&Board[2][2]==' ')
        Cordinate=9;
   else if(Board[2][2]=='O'&&Board[1][1]=='O'&&Board[0][0]==' ')
        Cordinate=1;
   else if(Board[0][2]=='O'&&Board[1][1]=='O'&&Board[2][0]==' ')
        Cordinate=7;
   else if(Board[2][0]=='O'&&Board[1][1]=='O'&&Board[0][2]==' ')
        Cordinate=3;
   else if(Board[2][0]=='O'&&Board[0][2]=='O'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[0][0]=='O'&&Board[2][0]=='O'&&Board[1][0]==' ')
        Cordinate=4;
   else if(Board[0][1]=='O'&&Board[2][1]=='O'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[0][0]=='O'&&Board[0][2]=='O'&&Board[0][1]==' ')
        Cordinate=2;
   else if(Board[1][0]=='O'&&Board[1][2]=='O'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[2][0]=='O'&&Board[2][2]=='O'&&Board[2][1]==' ')
        Cordinate=8;
   else if(Board[2][1]=='O'&&Board[2][2]=='O'&&Board[2][0]==' ')
        Cordinate=7;
   return Cordinate;
   }

int smartDefence(void)//function to increase game intelligence
{
   if(Board[0][0]=='X'&&Board[0][1]=='X'&&Board[0][2]==' ')
       Cordinate=3;
   else if(Board[0][2]=='X'&&Board[2][2]=='X'&&Board[1][2]==' ')
       Cordinate=6;
   else if(Board[1][1]=='X'&&Board[2][1]=='X'&&Board[0][1]==' ')
       Cordinate=2;
   else if(Board[1][0]=='X'&&Board[2][0]=='X'&&Board[0][0]==' ')
       Cordinate=1;
   else if(Board[1][0]=='X'&&Board[1][1]=='X'&&Board[1][2]==' ')
       Cordinate=6;
   else if(Board[2][0]=='X'&&Board[2][1]=='X'&&Board[2][2]==' ')
       Cordinate=9;
   else if(Board[0][0]=='X'&&Board[1][0]=='X'&&Board[2][0]==' ')
        Cordinate=7;
   else if(Board[0][1]=='X'&&Board[1][1]=='X'&&Board[2][1]==' ')
        Cordinate=8;
   else if(Board[0][2]=='X'&&Board[1][2]=='X'&&Board[2][2]==' ')
        Cordinate=9;
   else if(Board[0][0]=='X'&&Board[1][1]=='X'&&Board[2][2]==' ')
        Cordinate=9;
   else if(Board[2][2]=='X'&&Board[1][1]=='X'&&Board[0][0]==' ')
        Cordinate=1;
   else if(Board[0][2]=='X'&&Board[1][1]=='X'&&Board[2][0]==' ')
        Cordinate=7;
   else if(Board[2][0]=='X'&&Board[1][1]=='X'&&Board[0][2]==' ')
        Cordinate=3;
   else if(Board[2][0]=='X'&&Board[0][2]=='X'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[0][0]=='X'&&Board[2][0]=='X'&&Board[1][0]==' ')
        Cordinate=4;
   else if(Board[0][1]=='X'&&Board[2][1]=='X'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[0][0]=='X'&&Board[0][2]=='X'&&Board[0][1]==' ')
        Cordinate=2;
   else if(Board[1][0]=='X'&&Board[1][2]=='X'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[2][0]=='X'&&Board[2][2]=='X'&&Board[2][1]==' ')
        Cordinate=8;
   else if(Board[0][0]=='X'&&Board[2][2]=='X'&&Board[1][1]==' ')
        Cordinate=5;
   else if(Board[1][1]=='X'&&Board[1][2]=='X'&&Board[1][0]==' ')
        Cordinate=4;
   else
       computerPlay();
   return Cordinate;
   }

   int getMode()
     {
       do{
           printf("Hello would you love to play with human or computer?: \n\n");
           puts("\t\t1: COMPUTER\n\n");
           puts("\t\t2: HUMAN\n\n");
           puts("\t\t3: Help\n");
           printf("waiting....");
           scanf("%d", &mode);
           if(mode==3){
                help();
                getch();
                     }
           system("cls");
           printf("\t\t\t                        \n\t\t\t=========================\n");
           puts("\t\t\tTIC TAC TOE GAME FOR TWO!\n\t\t\t=========================\n");
           while(getchar()==ch)//ensuring program works when character is entered.
           {
             putchar(ch);//ignore characters
             scanf("%d", &mode);
           }
             if(mode==1)
             {
                do{
                    puts("\t*Which do you prefer?: \n\n"
                       "\t0: BASIC Mode\n\n"
                       "\t1: EXPERT Mode\n\n"
                       "\t2: PRO Mode\n\n"
                       "\t3: Help\n");
                       printf("Waiting...");
                  scanf("%d", &expert);
                  if(expert==3)
                  {
                    help();
                    getch();
                    }
                  //system("cls");
                  while(getchar()==ch)//ensuring program works when character is entered.
                  {
                   putchar(ch);//ignore characters
                   scanf("%d", &expert);
                  }
                   
                   }while(expert!=0&&expert!=1&&expert!=2);
             }
           }while(mode!=1&&mode!=2);
          return mode;
     }
int checkXorOHasWon(void)//function checks if there is a win or not
    {
         if((Board[0][0]==Board[0][1]&&Board[0][1]==Board[0][2])&&Board[0][0]!=' '||
            (Board[1][0]==Board[1][1]&&Board[1][1]==Board[1][2])&&Board[1][0]!=' '||
            (Board[2][0]==Board[2][1]&&Board[2][1]==Board[2][2])&&Board[2][0]!=' '||
            (Board[0][0]==Board[1][0]&&Board[1][0]==Board[2][0])&&Board[0][0]!=' '||
            (Board[0][1]==Board[1][1]&&Board[1][1]==Board[2][1])&&Board[0][1]!=' '||
            (Board[0][2]==Board[1][2]&&Board[1][2]==Board[2][2])&&Board[0][2]!=' '||
            (Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2])&&Board[0][0]!=' '||
            (Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0])&&Board[0][2]!=' ')
            return 1;
            else return 0;
    }
   
int checkValidMove(int Row, int Column)//function ensures all moves made are valid
    {
        if((Row>=0&&Row<=2)&&(Column>=0&&Column<=2)&&(Board[Row][Column]==' '))
        return 1;
        else
        return 0;
    }                                                                              
    
    void displayBoard(void)//displays the grid on the screen
    {
         printf("\t\t\t  +----+----+----+\n"
                "\t\t\t  | %c  | %c  | %c  |\n", Board[0][0],Board[0][1],Board[0][2]);
         printf("\t\t\t  +----+----+----+\n"
                "\t\t\t  | %c  | %c  | %c  |\n", Board[1][0],Board[1][1],Board[1][2]);
         printf("\t\t\t  +----+----+----+\n"
                "\t\t\t  | %c  | %c  | %c  |\n", Board[2][0],Board[2][1],Board[2][2]);
         printf("\t\t\t  +----+----+----+\n\n");
    }
    void clearBoard(void)//sets all grid positions to null
    {
         Board[0][0]=' ';
         Board[0][1]=' ';
         Board[0][2]=' ';
         Board[1][0]=' ';
         Board[1][1]=' ';
         Board[1][2]=' ';
         Board[2][0]=' ';
         Board[2][1]=' ';
         Board[2][2]=' ';
    }

void getMoveCoordinates(char currentSymbol, int *Row, int *Column)//used to obtain desired row and column from two users and computer
    {
         if(mode==2)
         {
          if(currentSymbol=='X')
          {
            printf("Player (X): \n");
            printf("Enter Grid Position: ");
            scanf("%d", &Cordinate);
          }
         else{
              printf("player (O): \n");
              printf("Enter Grid Position: "); 
              scanf("%d", &Cordinate);
              }
         }
    else{
          if(currentSymbol=='X')
          {
            printf("Player (X): \n");
            printf("Enter Grid Position: ");
            scanf("%d", &Cordinate);
            while(getchar()==ch)//ensuring program works when character is entered.
           {
             putchar(ch);//ignorecharacters
             scanf("%d", &Cordinate);
             }
          }
          else{
               if(expert==0)
                   computerPlay(); 
               else if(expert==1) 
                 {
                    int i;
                    for(i=1; i<=5; i++)
                     {
                       printf(".");
                       Sleep(700);

                     }               
                   Cordinate=smartDefence();}
               else{
                    if(NoMoves==1&&currentSymbol=='O')
                       Cordinate=smartMove();
                    else{
                         int i;           
                         for(i=1; i<=5; i++)
                          {
                            printf(".");
                            Sleep(700);
                          }
                         Cordinate=smartDefence();
                         Cordinate=smartAttack();}
                 }
               }
         }
         convert2DTo1D();
         
}

int main(void)
{
  int TryAgain=0;
 do{
    printf("\t\t\t                        \n\t\t\t=========================\n");
    puts("\t\t\tTIC TAC TOE GAME FOR TWO!\n\t\t\t=========================\n");
    srand(time(NULL));
    NoMoves=0;
    GameHasBeenWon=0;
    getMode();
    getPlayerName();
    clearBoard();
    displayBoard();
    if((rand()%2)==1)
     currentSymbol='X';
    else currentSymbol='O';
    do{
        do{
            getMoveCoordinates(currentSymbol, &Row,&Column);
            if(checkValidMove(Row,Column)!=1)
                {
                 puts("INVALID MOVE!\n");
                 }
           }while(checkValidMove(Row,Column)!=1);
        Board[Row][Column]=currentSymbol;
        displayBoard();
        system("cls");
        printf("\t\t\t                        \n\t\t\t=========================\n");
        puts("\t\t\tTIC TAC TOE GAME FOR TWO!\n\t\t\t=========================\n");
        displayBoard();
        GameHasBeenWon=checkXorOHasWon();
        NoMoves++;
        if(GameHasBeenWon!=1)
          {
             if(NoMoves==9)
             GameHasBeenDrawn=1;
             if(currentSymbol=='X')
               currentSymbol='O';
             else if(currentSymbol=='O')
               currentSymbol='X';
          }      
      }while(GameHasBeenWon!=1&&GameHasBeenDrawn!=1);
       if(GameHasBeenWon==1)
       {
          if(mode==1)
            {
                if(currentSymbol=='X')
                printf("\tHurrrreeeey! %s Wins", player1);
                else
                printf("\tHurrrreeeey! COMPUTER GOT YOU THIS TIME!!!");
            }
          else
          {
             if(currentSymbol=='X')
             printf("Hurrrreeeey! %s Wins", player1);
            else
             printf("Hurrrreeeey! %s Wins", player2);
          }
        }
       else 
       puts("Sorry A Draw This Time!"); 
       int choice;
       do{
         printf("\n\nWish For Another Round?: ");
         puts("\n 1: Yeah\n"
              "\n 2: Nope\n");
         printf("Waiting...");
         scanf("%d", &choice);
         if(choice==1)
         TryAgain=1;
        // if(TryAgain==2)
         //puts("\nIt Was a Nice Round There!\n"); 
        }while(choice!=1&&choice!=2);
        system("cls");
    }while(TryAgain==1);
    
    printf("\n<Key In Any Character To Exit Game>\n"
         "Waiting... ");
    
    getch();
    return 0;

}