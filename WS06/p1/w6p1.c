#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Magic Number for Maximum item
#define MaximumItem 10
#define Minimum_Income 500
#define Maximum_Income 400000


int main(void)
{

    //variables
    //const double Minimum_Income = 500, Maximum_Income = 400000;
    int Item = 0, i, Priority[10];
    double Income, Total = 0, Item_cost[10];
    char Finance[10];

    //Flag Variable to end the loop or to exit the loop
    int Flag = 0;

    //Title
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    //While Loop
    while (Flag == 0)
    {
        printf("Enter your monthly NET income: $");
        scanf(" %lf", &Income);
        if (Income < Minimum_Income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        if (Income > Maximum_Income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }
        if (Income >= Minimum_Income && Income <= Maximum_Income)
        {
            Flag = 1;
        }
    }
    Flag = 0;

    while (Flag == 0)
    {
        printf("\n");
        printf("How many wish list items do you want to forecast?: ");
        scanf(" %d", &Item);
        if ((Item > MaximumItem) || (Item < 1))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else
        {
            Flag = 1;
        }
    }

    for (i = 0; i < Item; i++)
    {
        printf("\n");
        printf("Item-%d Details:\n", i + 1);
        Flag = 0;
        while (Flag == 0)
        {
            printf("   Item cost: $");
            scanf(" %lf", &Item_cost[i]);
            if (Item_cost[i] < 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                Total = Total + Item_cost[i];
                Flag = 1;
            }
        }
        Flag = 0;

        while (Flag == 0)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &Priority[i]);
            if (Priority[i] < 1 || Priority[i]>3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                Flag = 1;
            }
        }
        Flag = 0;

        while (Flag == 0)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &Finance[i]);
            if (Finance[i] != 'y' && Finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                Flag = 1;
            }
        }
    }

    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < Item; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Priority[i], Finance[i], Item_cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", Total);
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}