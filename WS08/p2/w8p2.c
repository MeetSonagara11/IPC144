

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p2.h"

int getIntPositive(int* iPtr) 
{
	int value,flag=1;

	do {
		scanf(" %d", &value);
		if (value <= 0)
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
		*iPtr = value;
	}
	return value;
}

double getDoublePositive(double* dPtr)
{
	double value;
	int flag = 1;

	do {
		scanf(" %lf", &value);
		if (value <= 0)
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
		*dPtr = value;
	}
	return value;
}

void openingMessage(const int num) 
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProduct);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
	printf("\n");
}

struct CatFoodInfo getCatFoodInfo(const int num) 
{
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
		scanf("%lf", &foodInfo.weight);
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

void displayCatFoodData(int skuNumber, double* price, int perServingCalorie, double* lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *price, *lbs, perServingCalorie);
}

double convertLbsKg(const double* pounds, double* poundToKg) 
{

	double poundsToKg = (*pounds) / lbsKg;

	if (poundToKg != NULL)
	{
		*poundToKg = poundsToKg;
	}

	return poundsToKg;
}

int convertLbsG(const double* pounds, int* poundToGram) 
{
	int poundsToG = ((*pounds) / lbsKg) * 1000;

	if (poundToGram != NULL)
	{
		*poundToGram = poundsToG;
	}
	return poundsToG;
}

void convertLbs(const double* pounds, double* poundToKg, int* poundToGram) 
{
	double poundsToKg = (*pounds) / lbsKg;
	int poundsToG = ((*pounds) / lbsKg) * 1000;

	if (poundToGram != NULL && poundToKg != NULL)
	{
		*poundToGram = poundsToG;
		*poundToKg = poundsToKg;
	}
}

double calculateServings(const int servingSizeGrams, const int ttlGrams, double* numServings) 
{
	double servings = ((double)ttlGrams) / servingSizeGrams;
	if (numServings != NULL)
	{
		*numServings = servings;
	}
	return servings;
}

double calculateCostPerServing(const double* price, const double* numServings, double* result) 
{
	double costPerServing = (*price) / (*numServings);
	if (result != NULL)
	{
		*result = costPerServing;
	}
	return costPerServing;
}

double calculateCostPerCal(const double* price, const double* ttlCalories, double* result)
{
	double costPerCal = (*price) / (*ttlCalories);
	if (result != NULL)
	{
		*result = costPerCal;
	}
	return costPerCal;
}

struct ReportData calculateReportData(struct CatFoodInfo foodInfo) 
{
	struct ReportData data;
	data.skuNumber = foodInfo.skuNumber;
	data.price = foodInfo.price, data.lbs = foodInfo.weight, data.calories = foodInfo.calories;
	data.kg = convertLbsKg(&data.lbs, &data.kg), data.gram = convertLbsG(&data.lbs, &data.gram);
	data.servings = calculateServings(GRAMS_NUMBER, data.gram, &data.servings);
	double totalCalories = data.calories * data.servings;
	data.servingPrice = calculateCostPerServing(&data.price, &data.servings, &data.servingPrice);
	data.calorieCost = calculateCostPerCal(&data.price, &totalCalories, &data.calorieCost);
	return data;
}

void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_NUMBER);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData data, const int cheapProduct) 
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.skuNumber, data.price, data.lbs, data.kg, data.gram, data.calories, data.servings, data.servingPrice, data.calorieCost);
}

void displayFinalAnalysis(const struct CatFoodInfo foodInfo) 
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", foodInfo.skuNumber, foodInfo.price);
	printf("\n");
	printf("Happy shopping!\n");
	printf("\n");
}

void start(void)
{
	struct ReportData data[maxProduct] = { {0} };
	struct CatFoodInfo foodInfo[maxProduct] = { {0} };
	int i, cheapestIndex = 0;
	openingMessage(maxProduct);

	for (i = 0; i < maxProduct; i++) 
	{
	foodInfo[i] = getCatFoodInfo(i);
	data[i] = calculateReportData(foodInfo[i]);
	}
	displayCatFoodHeader();
	for (i = 0; i < maxProduct; i++) {
		displayCatFoodData(foodInfo[i].skuNumber, &foodInfo[i].price, foodInfo[i].calories, &foodInfo[i].weight);
	}

	double cheapestProductPrice = data[0].servingPrice;
	for (i = 0; i < maxProduct; i++)
	{
		if (data[i].servingPrice <= cheapestProductPrice)
		{
			cheapestProductPrice = data[i].servingPrice;
			cheapestIndex = i;
		}
	}
	printf("\n");

	displayReportHeader();
	for (i = 0; i < maxProduct; i++)
	{
		displayReportData(data[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < maxProduct; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(foodInfo[i]);
		}
	}
}