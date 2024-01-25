
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* iPtr) 
{
	int input;
	int flag = 1;

	do {
		scanf(" %d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (iPtr != NULL)
	{
		*iPtr = input;
	}
	return input;
}

double getDoublePositive(double* dPtr) {
	double input;
	int flag = 1;

	do {
		scanf(" %lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (dPtr != NULL)
	{
		*dPtr = input;
	}
	return input;
}

void openingMessage(const int num) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProduct);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
	printf("\n");
}

struct CatFoodInfo getCatFoodInfo(const int num) {
	struct CatFoodInfo foodInfo;
	int flag;
	printf("Cat Food Product #%d\n", num + 1);
	printf("--------------------\n");
	flag = 1;

	printf("SKU           : ");
	flag = 1;
	do {
		scanf(" %d", &foodInfo.skuNumber);
		if (foodInfo.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("PRICE         : $");
	flag = 1;
	do {
		scanf(" %lf", &foodInfo.price);
		if (foodInfo.price <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do {
		scanf(" %lf", &foodInfo.weight);
		if (foodInfo.weight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("CALORIES/SERV.: ");
	flag = 1;
	do {
		scanf(" %d", &foodInfo.calories);
		if (foodInfo.calories <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("\n");
	return foodInfo;
}

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku_number, double* price, int calorie_per_serving, double* weightLbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *price, *weightLbs, calorie_per_serving);
}

void start(void)
{
	int i;
	struct CatFoodInfo foodInfo[maxProduct] = { {0} };
	openingMessage(maxProduct);

	for (i = 0; i < maxProduct; i++) {
		foodInfo[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	for (i = 0; i < maxProduct; i++) {
		displayCatFoodData(foodInfo[i].skuNumber, &foodInfo[i].price, foodInfo[i].calories, &foodInfo[i].weight);
	}
}