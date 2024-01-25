#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Explanatory Variable OR Magic Numbers
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3


int main(void)
{

    //Variables
    const int JAN = 1, DEC = 12;
    int monthNum, year, done = 1, i;
    double morning, evening;
    double morningTtl = 0, eveningTtl = 0, Ttl, morningAvg, eveningAvg, Avg;


    printf("General Well-being Log\n");
    printf("======================\n");


    //While Loop To Ensure that the user have given proper input of months or not. if not, than loop continues
    while (done)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &monthNum);

        if (year<MIN_YEAR || year>MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (monthNum<JAN || monthNum>DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (monthNum >= JAN && monthNum <= DEC))
        {
            printf("\n");
            printf("*** Log date set! ***\n");
            done = 0;
        }
    }


    for (i = 1; i <= LOG_DAYS; i++)
    {
        switch (monthNum)
        {
        case 1:
            printf("\n%d-JAN-%02d\n", year, i);
            break;

        case 2:
            printf("\n%d-FEB-%02d\n", year, i);
            break;

        case 3:
            printf("\n%d-MAR-%02d\n", year, i);
            break;

        case 4:
            printf("\n%d-APR-%02d\n", year, i);
            break;

        case 5:
            printf("\n%d-MAY-%02d\n", year, i);
            break;

        case 6:
            printf("\n%d-JUN-%02d\n", year, i);
            break;

        case 7:
            printf("\n%d-JUL-%02d\n", year, i);
            break;

        case 8:
            printf("\n%d-AUG-%02d\n", year, i);
            break;

        case 9:
            printf("\n%d-SEP-%02d\n", year, i);
            break;

        case 10:
            printf("\n%d-OCT-%02d\n", year, i);
            break;

        case 11:
            printf("\n%d-NOV-%02d\n", year, i);
            break;

        case 12:
            printf("\n%d-DEC-%02d\n", year, i);
            break;
        }
        done = 1;

        //Loop For Morning Rating
        while (done)
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);
            if (morning < 0.0 || morning > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                morningTtl = morningTtl + morning;
                done = 0;
            }
        }
        done = 1;

        //Loop For Evening Rating
        while (done)
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);
            if (evening < 0.0 || evening>5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                eveningTtl = eveningTtl + evening;
                done = 0;
            }
        }
    }

    Ttl = morningTtl + eveningTtl;
    morningAvg = morningTtl / LOG_DAYS;
    eveningAvg = eveningTtl / LOG_DAYS;
    Avg = (morningAvg + eveningAvg) / 2;
    printf("\n");
    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %.3lf\n", morningTtl);
    printf("Evening total rating:  %.3lf\n", eveningTtl);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", Ttl);
    printf("\n");

    printf("Average morning rating:  %.1lf\n", morningAvg);
    printf("Average evening rating:  %.1lf\n", eveningAvg);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", Avg);

    return 0;
}
