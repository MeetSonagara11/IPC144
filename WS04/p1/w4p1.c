/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    //Variable
    int num, n = 0;
    char letter;

    //Loop Started Info
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");

    //Loop
    do {
        //Input From user
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter letter type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &letter, &num);

        //For Do-While Loop
        if (letter == 'D')
        {
            if (num >= 3 && num <= 20)
            {
                n = 0;
                printf("DO-WHILE: ");
                do {
                    printf("D");
                    n++;
                } while (n < num);
                printf("\n");
            }
            else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
        }

        //For While Loop
        else if (letter == 'W')
        {
            if (num >= 3 && num <= 20)
            {
                n = 0;
                printf("WHILE   : ");
                while (n < num)
                {
                    n++;
                    printf("W");
                }
                printf("\n");
            }
            else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
        }

        //For For Loop
        else if (letter == 'F')
        {
            if (num >= 3 && num <= 20)
            {
                printf("FOR     : ");
                for (n = 0; n < num; n++)
                {
                    printf("F");
                }
                printf("\n");
            }
            else
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
        }

        //Exit the Loop if User will print Q0
        else if (letter == 'Q')
        {
            if (num == 0)
            {
                //Loop Ended Info
                printf("\n");
                printf("+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
            }
            else
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            printf("\n");
        }
        else
            printf("ERROR: Invalid entered value(s)!\n\n");

    } while (num != 0 || letter != 'Q');


    return 0;
}