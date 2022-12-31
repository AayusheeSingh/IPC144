/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : Aayushee Singh
Student ID#: 173927211
Email      : asingh1221@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include<stdio.h>


// User Libraries
#include"w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int val;
	do
	{
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}while (val <= 0);
	if (num != NULL)
	{
		*num = val;
	}
	return val;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double val;
	do
	{
		scanf("%lf", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}while (val <= 0);
	if (num != NULL)
	{
		*num = val;
	}
	return val;
	
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProduct)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProducts);
	printf("NOTE: A 'serving' is %dg\n", numOfGrams);
	return;
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int index)
{
	
	struct CatFoodInfo data;
	int inputInt=0;
	double inputDouble=0;
	printf("Cat Food Product #%d\n", index+1);
	printf("--------------------\n");
	printf("SKU           : ");
	data.skuNum = getIntPositive(&inputInt);

	printf("PRICE         : $");
	data.productPrice = getDoublePositive(&inputDouble);

	printf("WEIGHT (LBS)  : ");
	data.weight = getDoublePositive(&inputDouble);

	printf("CALORIES/SERV.: ");
	data.calories = getIntPositive(&inputInt);
	printf("\n");	
	return data;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* productPrice, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNum, *productPrice, *weight, calories);	
}


// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo information[maxProducts] = { {0} };
	openingMessage(maxProducts);
	printf("\n");
	for (i = 0; i < maxProducts; i++)
	{
		information[i]=getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < maxProducts; i++)
	{
		displayCatFoodData(information[i].skuNum, &information[i].productPrice, information[i].calories ,&information[i].weight);
	}
	return;
}
