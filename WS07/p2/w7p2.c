/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  :Aayushee Singh
Student ID#:173927211
Email      :asingh1221@myseneca.ca
Section    :NHH
Authenticity Declaration:a
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define minLive 1
#define maxLive 10
#define multiple 5
#define maxpathLength 70
#define minpathLength 10



struct PlayerInfo
{
    int lives;
    char symbol;
    int n_treasure;
    int position[maxpathLength];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bomb[maxpathLength];
    int treasure[maxpathLength];
};


int main(void)
{
    struct PlayerInfo playerinfo = { 0,0,0,{0} };
    struct GameInfo gameinfo = { 0,0,{0},{0} };
    int flag = 1, i, j;
    int movesLeft, livesLeft;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &playerinfo.symbol);
    while (flag == 1)
    {
        printf("Set the number of lives: ");
        scanf("%d", &playerinfo.lives);
        if ((playerinfo.lives < minLive) || (playerinfo.lives > maxLive))
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            flag = 0;
        }
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");


    printf("GAME Configuration\n");
    printf("------------------\n");
    flag = 1;
    while (flag == 1)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &gameinfo.pathLength);
        if ((gameinfo.pathLength % multiple == 0) && ((gameinfo.pathLength >= minpathLength) && (gameinfo.pathLength <= maxpathLength)))
        {
            flag = 0;
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    }


    flag = 1;
    while (flag == 1)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameinfo.moves);

        if (gameinfo.moves >= playerinfo.lives && gameinfo.moves <= (gameinfo.pathLength * 75) / 100)
        {
            flag = 0;
        }
        else
        {
            printf("    Value must be between %d and %d\n", playerinfo.lives, ((gameinfo.pathLength * 75) / 100));
        }
    }

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.pathLength);

    for (i = 1; i <= gameinfo.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i, i + 4);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &gameinfo.bomb[i + j - 1]);
        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameinfo.pathLength);
    for (i = 1; i <= gameinfo.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i, i + 4);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &gameinfo.treasure[i + j - 1]);
        }
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", playerinfo.symbol);
    printf("   Lives      : %d\n", playerinfo.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", gameinfo.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < gameinfo.pathLength; i++)
    {
        printf("%d", gameinfo.bomb[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gameinfo.pathLength; i++)
    {
        printf("%d", gameinfo.treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    playerinfo.n_treasure = 0;
    movesLeft = gameinfo.moves;
    livesLeft = playerinfo.lives;

    
    char movingSymbols[maxpathLength];

    for (i = 0; i < gameinfo.pathLength; i++)
    {
        playerinfo.position[i] = 0;
    }

    for (i = 0; i < gameinfo.pathLength; i++)
    {
        movingSymbols[i] = '-';
    }    
    
    int nextMove = 0;   
   
    do
    {              
        if (nextMove == 0)
        {            
            printf("\n");
        }
        else
        {
            printf("  ");
            for (i = 0; i < nextMove-1; i++)
            {
                printf(" ");
            }
            printf("%c\n",playerinfo.symbol);
        }        
            //  line 2
            printf("  ");
            for (i = 0; i < gameinfo.pathLength; i++)
            {
                printf("%c", movingSymbols[i]);
            }
            printf("\n");

            //  line 3
            printf("  ");
            for (i = 1; i <= gameinfo.pathLength; i++)
            {
                if (i % 10 == 0)
                {
                    printf("%d", i / 10);
                }
                else
                {
                    printf("|");
                }
            }
            printf("\n");

            // line 4
            printf("  ");
            for (i = 0; i < gameinfo.pathLength; i++)
            {
                if ((i+1) % 10 == 0)
                {
                    printf("0");
                }
                else
                {
                    printf("%d", (i+1) % 10);
                }
                
            }
            printf("\n");            
            printf("+---------------------------------------------------+\n");
            printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, playerinfo.n_treasure, movesLeft);
            printf("+---------------------------------------------------+\n");          
            
            {
                flag = 1;

                while (flag)
                {
                    printf("Next Move [1-%d]: ", gameinfo.pathLength);
                    scanf("%d", &nextMove);
                    if (nextMove < 1 || nextMove > gameinfo.pathLength)
                    {
                        printf("  Out of Range!!!\n");
                    }
                    else
                    {
                        flag = 0;
                    }
                }

                printf("\n");

                if (playerinfo.position[nextMove - 1] == nextMove)
                {
                    printf("===============> Dope! You've been here before!\n\n");                    
                    movesLeft++;
                }
                else if (gameinfo.bomb[nextMove - 1] == 1 && gameinfo.treasure[nextMove - 1] == 1)
                {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    movingSymbols[nextMove - 1] = '&';                    
                    livesLeft--;
                    playerinfo.n_treasure++;
                }
                else if (gameinfo.bomb[nextMove - 1] == 1 && gameinfo.treasure[nextMove - 1] == 0)
                {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    movingSymbols[nextMove - 1] = '!';
                    livesLeft--;
                }

                else if (gameinfo.treasure[nextMove - 1] == 1 && gameinfo.bomb[nextMove - 1] == 0)
                {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    movingSymbols[nextMove - 1] = '$';
                    playerinfo.n_treasure++;
                }

                else
                {
                    printf("===============> [.] ...Nothing found here... [.]\n\n");
                    movingSymbols[nextMove - 1] = '.';
                    
                }                
                playerinfo.position[nextMove - 1] = nextMove;                
                movesLeft--;
                if (livesLeft == 0)
                {
                    printf("No more LIVES remaining!\n");
                    printf("\n");
                    if (nextMove == 0)
                    {
                        printf("  ");
                        printf("\n");
                    }
                    else
                    {
                        printf("  ");
                        for (i = 0; i < nextMove - 1; i++)
                        {
                            printf(" ");
                        }
                        printf("V\n");
                    }
                    printf("  ");
                    for (i = 0; i < gameinfo.pathLength; i++)
                    {
                        printf("%c", movingSymbols[i]);
                    }
                    printf("\n");

                    // printing line 3
                    printf("  ");
                    for (i = 1; i <= gameinfo.pathLength; i++)
                    {
                        if (i % 10 == 0)
                        {
                            printf("%d", i / 10);
                        }
                        else
                        {
                            printf("|");
                        }
                    }
                    printf("\n");

                    //printing line 4
                    printf("  ");
                    for (i = 0; i < gameinfo.pathLength; i++)
                    {
                        if ((i + 1) % 10 == 0)
                        {
                            printf("0");
                        }
                        else
                        {
                            printf("%d", (i + 1) % 10);
                        }

                    }
                    printf("\n");

                   
                    printf("+---------------------------------------------------+\n");
                    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, playerinfo.n_treasure, movesLeft);
                    printf("+---------------------------------------------------+\n");                    
                }                
            }               
            
     } while (movesLeft != 0 && livesLeft != 0);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");
        return 0;
}
