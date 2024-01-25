/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
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

//Magic Numbers or Explanatory Variables
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
	//Variable

	const int JAN = 1, DEC = 12;
	int monthNum, year, flag2= 1, i;
	double morning, evening;
	double morningTtl = 0, eveningTtl = 0, Ttl, morningAvg, eveningAvg, Avg;
	int flag1 = 1;


	printf("General Well-being Log\n");
	printf("======================\n");

	//while Loop to repeat the block of code if the condition is true
	while (flag1 == 1)
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
			printf("\n");
			printf("Log starting date: %d-", year);

			switch (monthNum)
			{
			case 1:
				printf("JAN");
				break;

			case 2:
				printf("FEB");
				break;

			case 3:
				printf("MAR");
				break;

			case 4:
				printf("APR");
				break;

			case 5:
				printf("MAY");
				break;

			case 6:
				printf("JUN");
				break;

			case 7:
				printf("JUL");
				break;

			case 8:
				printf("AUG");
				break;

			case 9:
				printf("SEP");
				break;

			case 10:
				printf("OCT");
				break;

			case 11:
				printf("NOV");
				break;

			case 12:
				printf("DEC");
				break;
			}

			printf("-01");
			printf("\n");
			flag1 = 0;
		}
		
		return 0;
}
