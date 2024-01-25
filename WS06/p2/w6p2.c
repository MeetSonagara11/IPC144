#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Magic Numbers And Explanatory Variable
#define MaximumItem 10
#define Minimum_Income 500
#define Maximum_Income 400000
#define Minimum_LIST 1
#define MaximumItem 10
#define Minimum_COST 100.00

int main(void)
{
	int Flag = 1, done;
	double Income, months;
	int Size, selection, i, years, Item_List[MaximumItem];
	double cost, cost_List[MaximumItem], Total = 0, Total1 = 0, Total2 = 0, Total3 = 0;
	int Priority, Priority_List[MaximumItem];
	char Finance_Options, Finance_List[MaximumItem];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &Income);
		if (Income < Minimum_Income)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		else if (Income > Maximum_Income)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		else
			Flag = 0;
	} while (Flag);
	Flag = 1;

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &Size);
		if (Size < Minimum_LIST || Size > MaximumItem)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		else
			Flag = 0;
	} while (Flag);

	for (i = 0; i < Size; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		Flag = 1;
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost);
			if (cost < Minimum_COST)
				printf("      ERROR: Cost must be at least $100.00\n");
			else
			{
				Total += cost;
				cost_List[i] = cost;
				Flag = 0;
			}
		} while (Flag);
		Flag = 1;

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &Priority);
			if (Priority < 1 || Priority > 3)
				printf("      ERROR: Value must be between 1 and 3\n");
			else
			{
				Priority_List[i] =Priority;
				switch (Priority)
				{
				case 1:
					Total1 += cost_List[i];
					break;

				case 2:
					Total2 += cost_List[i];
					break;

				case 3:
					Total3 += cost_List[i];
					break;

				default:
					break;
				}
				Flag = 0;
			}
		} while (Flag);
		Flag = 1;

		do
		{
			scanf("%*c");
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c", &Finance_Options);
			switch (Finance_Options)
			{
			case 'y':
			case 'n':
				Finance_List[i] = Finance_Options;
				Flag = 0;
				break;
			default:
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (Flag);
		Item_List[i] = i + 1;
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < Size; i++)
		printf("%3d  %5d    %5c    %11.2lf\n", Item_List[i], Priority_List[i], Finance_List[i], cost_List[i]);
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", Total);
	Flag = 1;

	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);

		if (selection == 0)
			Flag = 0;
		else if (selection == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", Total);
			Total *= 100;
			Income *= 100;
			years = (int)Total / (int)(Income * 12);
			months = ((int)Total % (int)(Income * 12)) / Income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			Total /= 100;
			Income /= 100;
			done = 0;
			for (i = 0; i < Size; i++)
				if (Finance_List[i] == 'y')
					done = 1;
			if (done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}

		else if (selection == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &Priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", Priority);
			done = 0;

			switch (Priority)
			{
			case 1:
				printf("Amount:   $%1.2lf\n", Total1);
				Total1 *= 100;
				Income *= 100;
				years = (int)Total1 / (int)(Income * 12);
				months = ((int)Total1 % (int)(Income * 12)) / Income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				Total1 /= 100;
				Income /= 100;
				for (i = 0; i < Size; i++)

					if (Priority_List[i] == Priority)

						if (Finance_List[i] == 'y')

							done = 1;
				break;

			case 2:
				printf("Amount:   $%1.2lf\n", Total2);
				Total2 *= 100;
				Income *= 100;
				years = (int)Total2 / (int)(Income * 12);
				months = (((int)Total2 % (int)(Income * 12)) / Income) + 1;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				Total2 /= 100;
				Income /= 100;

				for (i = 0; i < Size; i++)

					if (Priority_List[i] == Priority)

						if (Finance_List[i] == 'y')

							done = 1;
				break;

			case 3:
				printf("Amount:   $%1.2lf\n", Total3);
				Total3 *= 100;
				Income *= 100;
				years = (int)Total3 / (int)(Income * 12);
				months = ((int)Total3 % (int)(Income * 12)) / Income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				Total3 /= 100;
				Income /= 100;
				for (i = 0; i < Size; i++)
					if (Priority_List[i] == Priority)
						if (Finance_List[i] == 'y')
							done = 1;
				break;

			default:
				break;
			}

			if (done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}
		else
			printf("\nERROR: Invalid menu selection.\n");
		printf("\n");
	} while (Flag);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}