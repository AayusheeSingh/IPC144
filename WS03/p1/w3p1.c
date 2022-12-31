/*
*****************************************************************************
<assessment name example : Workshop - #3 (Part - 1)>
Full Name : Aayushee Singh
Student ID# :173927211
Email :asingh1221@myseneca.ca
Section :NHH
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{	
	int pid1 = 111, pid2 = 222, pid3 = 111;
	double price1=111.49, price2=222.99, price3=334.49,avg;
	char taxed1='Y', taxed2='N', taxed3='N';
	const double testValue = 330.99;
	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)\n", pid1);
	printf("  Taxed: %c\n", taxed1);
	printf("  Price: $%.4lf\n", price1);
	printf("\n");
	printf("Product-2 (ID:%d)\n", pid2);
	printf("  Taxed: %c\n", taxed2);
	printf("  Price: $%.4lf\n", price2);
	printf("\n");
	printf("Product-3 (ID:%d)\n", pid3);
	printf("  Taxed: %c\n", taxed3);
	printf("  Price: $%.4lf\n", price3);
	avg = (price1 + price2 + price3)/3;
	printf("\n");
	printf("The average of all prices is: $%.4lf\n",avg);
	printf("\n");
	printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n");
	printf("\n");
	printf("Some Data Analysis...\n");
	printf("=====================\n");
	printf("1. Is product 1 taxable? -> %d\n", taxed1 == 'Y');
	printf("\n");
	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", taxed2=='N' && taxed3=='N');
	printf("\n");
	printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n",testValue,price3<testValue);
	printf("\n");
	printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n",price3>price1 && price3>price2);
	printf("\n");
	printf("5. Is the price of product 1 equal to or more than the price difference\n");
	printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n", price1==(price3 - price2) && price1>(price3 - price2),price3 - price2);
	printf("\n");
	printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", price2 >= avg);
	printf("\n");
	printf("7. Based on product ID, product 1 is unique -> %d\n",(pid1!=pid2) && (pid1!=pid3));
	printf("\n");
	printf("8. Based on product ID, product 2 is unique -> %d\n",(pid2!=pid1) && (pid2!=pid3));
	printf("\n");
	printf("9. Based on product ID, product 3 is unique -> %d\n",(pid3 != pid1) && (pid3 != pid2));
	printf("\n");



	
	return 0;
}