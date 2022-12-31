#include<stdio.h>
int main() {

	double price1 = 10.10, price2 = 10.12, price3 = 10.15;
	int cents1 = (int)(price1 * 100);
	int cents2 = (int)(price2 * 100);
	int cents3 = (int)(price3 * 100);
	printf("%d 10.10 = %.15lf\n", cents1, price1);
	printf("%d 10.12 = %.15lf\n", cents2, price2);
	printf("%d 10.15 = %.15lf\n", cents3, price3);
	
		int amount = 7245;
		float res;
		res = amount;
		res = amount/(100.0);
		printf("The converted value is %.2lf\n", res);
		int age = 19;

		printf("Prefix:  %d\n", ++age);
		printf("         %d\n", age);
		printf("Postfix: %d\n", age++);
		printf("         %d\n", ++age);

		
	return 0;
}