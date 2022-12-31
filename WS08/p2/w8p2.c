/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1
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
	} while (val <= 0);
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
	} while (val <= 0);
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
	int inputInt = 0;
	double inputDouble = 0;
	printf("Cat Food Product #%d\n", index + 1);
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* wtKilo)
{
	double res;
	res= *pounds / conversionFactor;
	if (wtKilo != NULL)
	{
		*wtKilo = res;
	}
	return res;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* wtGrams)
{
	int res;
	//res = ( ( * pounds) / conversionFactor) * 1000;
	res = convertLbsKg(pounds, NULL) * 1000;
	//res = res * 1000;
	if (wtGrams != NULL)
	{
		*wtGrams = res;
	}
	return res;
}


// 10. convert lbs: kg and g
//void convertLbs(const int* pounds, double* kg, int* grams)
//{
	//convertLbsG(pounds,grams);
	//convertLbsKg(pounds,kg);
	//return;
	void convertLbs(const double* pounds, double* kg, int* grams)
	{
		*grams = convertLbsG(pounds, NULL);
		*kg = convertLbsKg(pounds, NULL);
		return;
	//}
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double* numOfServings)
{
	double numberOfServings;
	numberOfServings = (double)totalGrams / (double)servingSizeGrams;
	if (numOfServings != NULL)
	{
		*numOfServings = numberOfServings;
	}
	return numberOfServings;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumOfServings, double* costPerServing)
{
	double costPerServ;
	costPerServ = *productPrice / *totalNumOfServings;
	if (costPerServing != NULL)
	{
		*costPerServing = costPerServ;
	}
	return costPerServ;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPerCalorie)
{
	double costPerCal;
	costPerCal = *productPrice/ *totalCalories ;
	if (costPerCalorie != NULL)
	{
		*costPerCalorie = costPerCal;
	}
	return costPerCal;
}



// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catfood)
{
	struct ReportData rdata;
	rdata.skuNum = catfood.skuNum;
	rdata.productPrice = catfood.productPrice;
	rdata.weightLBS = catfood.weight;
	rdata.calories = catfood.calories;
	rdata.weightKG = convertLbsKg(&rdata.weightLBS, NULL);
	rdata.weightG = convertLbsG(&rdata.weightLBS, NULL);
	rdata.totalServings = calculateServings(numOfGrams, rdata.weightG, NULL);
	double ttlcalories = rdata.calories * rdata.totalServings;
	rdata.costPerServing = calculateCostPerServing(&rdata.productPrice, &rdata.totalServings, NULL);
	rdata.costCalories = calculateCostPerCal(&rdata.productPrice, &ttlcalories, NULL);
	return rdata;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", numOfGrams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData( const struct ReportData rdata, const int productOption)
{	
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rdata.skuNum, rdata.productPrice, rdata.weightLBS, rdata.weightKG, rdata.weightG, rdata.calories, rdata.totalServings, rdata.costPerServing, rdata.costCalories);
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catfood)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", catfood.skuNum, catfood.productPrice);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
	return;
}



// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo information[maxProducts] = { {0} };
	struct ReportData reportdata[maxProducts] = { {0} };
	openingMessage(maxProducts);
	printf("\n");
	for (i = 0; i < maxProducts; i++)
	{
		information[i] = getCatFoodInfo(i);		
	}
	displayCatFoodHeader();
	for (i = 0; i < maxProducts; i++)
	{
		displayCatFoodData(information[i].skuNum, &information[i].productPrice, information[i].calories, &information[i].weight);
	}
	for (i = 0; i < maxProducts; i++)
	{		
		reportdata[i] = calculateReportData(information[i]);
	}
	printf("\n");

	// Displaying the report header
	displayReportHeader();	
	int cheapPosition;
	for (i = 0; i < maxProducts; i++)
	{
		if (reportdata[i].costPerServing < reportdata[i-1].costPerServing)
		{
			cheapPosition = i;
		}
	}

	// Displaying the report data
	for (i = 0; i < maxProducts; i++)
	{
		displayReportData(reportdata[i], cheapPosition);

		if (cheapPosition == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");
	displayFinalAnalysis(information[cheapPosition]);		
}
