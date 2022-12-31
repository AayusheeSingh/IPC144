/*
*****************************************************************************
<assessment name example : Workshop - #2 (Part - 1)>
Full Name :Aayushee Singh
Student ID# :173927211
Email : asingh1221@myseneca.ca
Section :NHH
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float p1, p2, p3,st,tax,total,ntax;
	int num;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%f", &p1);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%f", &p2);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%f", &p3);
	printf("\n");
	printf("Shirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2f\n",p1);
	printf("MEDIUM : $%.2f\n",p2);
	printf("LARGE  : $%.2f\n",p3);
	printf("\n");
	printf("Patty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &num);
	printf("\n");
	printf("Patty's shopping cart...\n");
	printf("Contains : %d shirts",num); 
	
	st = num * p1;
	printf("\nSub-total: $%.4f\n", st);
	tax = st * 0.13;
	tax = (tax*100)+0.5;	
	ntax = (int)tax;
	total = ntax / 100 + st;
	printf("Taxes    : $ %.4f\n",ntax/100);
	printf("Total    : $%.4f\n",total);
	
	return 0;
}