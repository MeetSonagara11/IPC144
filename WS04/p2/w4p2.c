/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    //Variable

    int  numA, numO, numP, numT, numC;
    int apple, orange, pear, tomato, cabbage;
    int total = 0, shop;

   //Loop Started 
    do {
        printf("Grocery Shopping\n");
        printf("================\n");


       //To Take Input how many number of apples are needed
        do {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &numA);
            if (numA < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (numA < 0);
        printf("\n");


        //To Take Input how many number of oranges are needed
        do {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &numO);
            if (numO < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (numO < 0);
        printf("\n");


        //To Take Input how many number of pears are needed
        do {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &numP);
            if (numP < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (numP < 0);
        printf("\n");


        //To Take Input how many number of Tomatoes are needed
        do {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &numT);
            if (numT < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (numT < 0);
        printf("\n");


        //To Take Input how many number of cabbages are needed
        do {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &numC);
            if (numC < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (numC < 0);
        printf("\n");



        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");



        if (numA >= 1)
        {
            printf("\n");
            do {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &apple);
                if (apple <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (apple > numA)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", numA - total);
                }
                else if (apple > 0 && apple <= numA)
                {
                    total += apple;
                    if (total != numA)
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                    else if (total == numA)
                    {
                        printf("Great, that's the apples done!\n");
                    }
                }
            } while (total != numA);
        }



        total = 0;
        if (numP >= 1)
        {
            printf("\n");
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pear);
                if (pear <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pear > numP)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", numP - total);
                }
                else if (pear > 0 && pear <= numP)
                {
                    total += pear;
                    if (total != numP)
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                    else if (total == numP)
                    {
                        printf("Great, that's the pears done!\n");
                    }
                }
            } while (total != numP);
        }



        total = 0;
        if (numC >= 1)
        {
            printf("\n");
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &cabbage);
                if (cabbage <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (cabbage > numC)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", numC - total);
                }
                else if (cabbage > 0 && cabbage <= numC)
                {
                    total += cabbage;
                    if (total != numC)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                    else if (total == numC)
                    {
                        printf("Great, that's the cabbages done!\n");
                    }
                }
            } while (total != numC);
        }



        total = 0;
        if (numO >= 1)
        {
            printf("\n");
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &orange);
                if (orange <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (orange > numO)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", numO - total);
                }
                else if (orange > 0 && orange <= numO)
                {
                    total += orange;
                    if (total != numO)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                    else if (total == numO)
                    {
                        printf("Great, that's the oranges done!\n");
                    }
                }
            } while (total != numO);
        }



        total = 0;
        if (numT >= 1)
        {
            printf("\n");
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &tomato);
                if (tomato <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (tomato > numT)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", numT - total);
                }
                else if (tomato > 0 && tomato <= numT)
                {
                    total += tomato;
                    if (total != numT)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                    else if (total == numT)
                    {
                        printf("Great, that's the tomatoes done!\n");
                    }
                }
            } while (total != numT);
        }



        printf("\nAll the items are picked!");
        printf("\n");
        printf("\nDo another shopping? (0=NO): ");
        scanf(" %d", &shop);
        printf("\n");

        if (shop == 0)
        {
            printf("Your tasks are done for today - enjoy your free time!");
            printf("\n");
            break;
        }


    } while (1);

    return 0;
}