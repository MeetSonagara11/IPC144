/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxLength 5
#define maxDepth 14
        struct gameInfo
        {
            int moves, pathLength;
            char player;
            int bomb[maxDepth][maxLength], treasure[maxDepth][maxLength];
        };
        struct playerInfo
        {
            int lives, symbol, treasureFound;
        };
        int main(void)
        {
            int i, j, flag = 1;
            struct gameInfo game;
            struct playerInfo player;
            char symbol;
            int lives, Length, moves;

            printf("================================\n");
            printf("         Treasure Hunt!\n");
            printf("================================\n");
            printf("\n");
            printf("PLAYER Configuration\n");
            printf("--------------------\n");
            printf("Enter a single character to represent the player: ");
            scanf(" %c", &symbol);
            player.symbol = symbol;

            do
            {
                printf("Set the number of lives: ");
                scanf(" %d", &lives);
                if (lives >= 1 && lives <= 10)
                {
                    player.lives = lives;
                    flag = 0;
                }
                else
                    printf("     Must be between 1 and 10!\n");
            } while (flag);
            printf("Player configuration set-up is complete\n");
            printf("\n");
            printf("GAME Configuration\n");
            printf("------------------\n");
            flag = 1;

            do
            {
                printf("Set the path length (a multiple of 5 between 10-70): ");
                scanf(" %d", &Length);
                if (Length % 5 == 0 && Length >= 10 && Length <= 70)
                {
                    game.pathLength = Length;
                    flag = 0;
                }
                else
                    printf("     Must be a multiple of 5 and between 10-70!!!\n");
            } while (flag);
            flag = 1;

            do
            {
                printf("Set the limit for number of moves allowed: ");
                scanf(" %d", &moves);
                if (moves >= 3 && moves <= 26)
                {
                    game.moves = moves;
                    flag = 0;
                }
                else
                    printf("    Value must be between 3 and 26\n");
            } while (flag);

            printf("\n");
            printf("BOMB Placement\n");
            printf("--------------\n");
            printf("Enter the bomb positions in sets of 5 where a value\n");
            printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
            printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

            for (i = 0; i < (game.pathLength / 5); i++)
            {
                printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
                scanf(" %d %d %d %d %d", &game.bomb[i][0], &game.bomb[i][1], &game.bomb[i][2], &game.bomb[i][3], &game.bomb[i][4]);
            }
            printf("BOMB placement set\n");
            printf("\n");
            printf("TREASURE Placement\n");
            printf("------------------\n");
            printf("Enter the treasure placements in sets of 5 where a value\n");
            printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
            printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

            for (i = 0; i < (game.pathLength / 5); i++)
            {
                printf("   Positions [%2d-%2d]: ", (5 * i) + 1, (5 * i) + 5);
                scanf(" %d %d %d %d %d", &game.treasure[i][0], &game.treasure[i][1], &game.treasure[i][2], &game.treasure[i][3], &game.treasure[i][4]);
            }

            printf("TREASURE placement set\n");
            printf("\n");
            printf("GAME configuration set-up is complete...\n");
            printf("\n");
            printf("------------------------------------\n");
            printf("TREASURE HUNT Configuration Settings\n");
            printf("------------------------------------\n");
            printf("Player:\n");
            printf("   Symbol     : %c\n", player.symbol);
            printf("   Lives      : %d\n", player.lives);
            printf("   Treasure   : [ready for gameplay]\n");
            printf("   History    : [ready for gameplay]\n");
            printf("\n");
            printf("Game:\n");
            printf("   Path Length: %d\n", game.pathLength);
            printf("   Bombs      : ");
            for (i = 0; i < (game.pathLength / 5); i++)
            {
                for (j = 0; j < maxLength; j++)
                {
                    printf("%d", game.bomb[i][j]);
                }
            }
            printf("\n");
            printf("   Treasure   : ");
            for (i = 0; i < (game.pathLength / 5); i++)
            {
                for (j = 0; j < maxLength; j++)
                {
                    printf("%d", game.treasure[i][j]);
                }
            }
            printf("\n\n");
            printf("====================================\n");
            printf("~ Get ready to play TREASURE HUNT! ~\n");
            printf("====================================\n");

            return 0;
        }
