/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define maxLength 70
#define minLength 10
#define maxLives 10
#define minLives 1

#include <stdio.h>

//Structure Player Information
struct playerInfo {
    int lives, treasureFound;
    char symbol;
    int position[maxLength];
};

//Structure Game Info
struct gameInfo {
    int moves, pathLength;
    int bombLocation[maxLength], treasureLocation[maxLength];
};

int main(void)
{
    //Variable
    int i, j, k;
    int movesLeft, livesLeft, movePosition = maxLength + 1;

    //Structure
    struct playerInfo player;
    struct gameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    //Loops of
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < minLives || player.lives > maxLives)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < minLives || player.lives > maxLives);

    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    //Loop of 
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if ((game.pathLength < minLength || game.pathLength > maxLength) || (game.pathLength % 5 != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((game.pathLength < minLength || game.pathLength > maxLength) || (game.pathLength % 5 != 0));

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < player.lives || game.moves >(int) (0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
        }
    } while (game.moves < player.lives || game.moves >(int) (0.75 * game.pathLength));


    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombLocation[i], &game.bombLocation[i + 1], &game.bombLocation[i + 2], &game.bombLocation[i + 3], &game.bombLocation[i + 4]);
    }

    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasureLocation[i], &game.treasureLocation[i + 1], &game.treasureLocation[i + 2], &game.treasureLocation[i + 3], &game.treasureLocation[i + 4]);
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

    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombLocation[j]);
    }
    printf("\n");
    printf("   Treasure   : ");

    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", game.treasureLocation[k]);
    }

    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    movesLeft = game.moves;
    livesLeft = player.lives;
    player.treasureFound = 0;
    int Count = 0;
    char currentPosition[maxLength];
    char positionItem[maxLength];

    for (j = 0; j < game.pathLength; j++)
    {
        player.position[j] = 0;
    }

    for (k = 0; k < game.pathLength; k++)
    {
        positionItem[k] = '-';
    }

    for (k = 0; k < game.pathLength; k++)
    {
        currentPosition[k] = ' ';
    }

    do {
        for (k = 0; k < game.pathLength; k++)
        {
            if (currentPosition[k] == 'V')
            {
                Count++;
            }
        }
        if (Count == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (k = 0; k < game.pathLength; k++)
            {
                if (currentPosition[k] == 'V')
                {
                    printf("%c\n", currentPosition[k]);
                    break;
                }
                else
                {
                    printf("%c", currentPosition[k]);
                }
            }
        }

        for (k = 0; k < game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, player.treasureFound, movesLeft);
        printf("+---------------------------------------------------+\n");

        if (livesLeft == 0)
        {
            break;
        }

        if (movesLeft == 0)
        {
            break;
        }

        do {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.position[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = 'V';
            movesLeft++;
        }

        else if (game.bombLocation[movePosition - 1] == 1 && game.treasureLocation[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = 'V';
            livesLeft--;
            player.treasureFound++;
        }

        else if (game.bombLocation[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = 'V';
            livesLeft--;
        }

        else if (game.treasureLocation[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = 'V';
            player.treasureFound++;
        }

        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = 'V';
        }

        player.position[movePosition - 1] = 1;
        movesLeft--;

        if (livesLeft == 0)
        {
            printf("No more LIVES remaining!\n");
            printf("\n");
        }
        if (movesLeft == 0)
        {
            printf("No more MOVES remaining!\n");
            printf("\n");
        }

    } while (movesLeft >= 0 && livesLeft >= 0);

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}