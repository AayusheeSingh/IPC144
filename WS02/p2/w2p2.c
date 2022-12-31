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
	float p1, p2, p3, tax1,tax2,tax3, ntax1,ntax2,ntax3,st1,st2,st3,total1,total2,total3,st_total,tax_total,f_total;
	float toonies = 2.0, loonies = 1.0, quarters = 0.25, dimes = 0.1, nickels = 0.05, pennies = 0.01;
	float qt1,qt2,qt3,qt4,qt5,qt6,bal1, bal2, bal3, bal4,bal5,bal6;

	int num1, num2, num3;
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
	printf("SMALL  : $%.2f\n", p1);
	printf("MEDIUM : $%.2f\n", p2);
	printf("LARGE  : $%.2f\n", p3);
	printf("\n");

	printf("Patty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &num1);
	printf("\n");
	printf("Tommy's shirt size is 'L'\n");
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &num2);
	printf("\n");
	printf("Sally's shirt size is 'M'\n");
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &num3);
	printf("\n");


	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	st1 = p1 * num1;
	tax1 = st1*0.13;
	tax1 = (tax1 * 100) + 0.5;
	ntax1 = (int)tax1;	
	ntax1 = ntax1 / 100;
	total1 = ntax1 + st1;
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'S', p1, num1, st1, ntax1, total1);
	st2 = p2 * num3;
	tax2 = st2 * 0.13;
	tax2 = (tax2 * 100) + 0.5;
	ntax2 = (int)tax2;
	ntax2 = ntax2 / 100;
	total2 = ntax2 + st2;
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'M', p2, num3, st2, ntax2, total2);
	st3 = p3 * num2;
	tax3 = st3 * 0.13;
	tax3 = (tax3 * 100) + 0.5;
	ntax3 = (int)tax3;
	ntax3 = ntax3 / 100;
	total3 = ntax3 + st3;
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 'L', p3, num2, st3, ntax3, total3);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	st_total = st1 + st2 + st3;
	tax_total = ntax1 + ntax2 + ntax3;
	f_total = total1 + total2 + total3;
	printf("%33.4lf %9.4lf %9.4lf\n\n", st_total, tax_total, f_total);


	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n");
	printf("\n");	
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", st_total);
	qt1 = st_total/toonies;
	qt1 = (int)qt1;
	bal1 =(((st_total/toonies)-qt1)*toonies);
	qt2 = bal1 / loonies;
	qt2 = (int)qt2;
	bal2 = (((bal1 / loonies) -qt2) * loonies);
	qt3 = bal2 /quarters;
	qt3 = (int)qt3;
	bal3 = (((bal2 / quarters) - qt3) * quarters);
	qt4 = bal3 / dimes;
	qt4 = (int)qt4;
	bal4 = (((bal3 / dimes) - qt4) * dimes);
	qt5 = bal4 / nickels;
	qt5 = (int)qt5;
	bal5 = (((bal4 / nickels)- qt5) * nickels);
	qt6 = bal5/pennies;
	qt6 = (int)qt6;
	bal6 = (((bal5 / pennies) - qt6) * pennies);	
	float avg_et = (st_total / (num1+num2+num3));
	printf("Toonies  %3d %9.4lf\n",(int)qt1,bal1 );
	printf("Loonies  %3d %9.4lf\n",(int)qt2,bal2 );
	printf("Quarters %3d %9.4lf\n",(int)qt3,bal3 );
	printf("Dimes    %3d %9.4lf\n",(int)qt4,bal4 );
	printf("Nickels  %3d %9.4lf\n",(int)qt5,bal5 );
	printf("Pennies  %3d %9.4lf\n",(int)qt6,bal6 );
	printf("\n");
	printf("Average cost/shirt: $%.4lf\n",avg_et);
	printf("\n");


	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", f_total);
	qt1 = f_total / toonies;
	qt1 = (int)qt1;
	bal1 = (((f_total / toonies) - qt1) * toonies);
	qt2 = bal1 / loonies;
	qt2 = (int)qt2;
	bal2 = (((bal1 / loonies) - qt2) * loonies);
	qt3 = bal2 / quarters;
	qt3 = (int)qt3;
	bal3 = (((bal2 / quarters) - qt3) * quarters);
	qt4 = bal3 / dimes;
	qt4 = (int)qt4;
	bal4 = (((bal3 / dimes) - qt4) * dimes);
	qt5 = bal4 / nickels;
	qt5 = (int)qt5;
	bal5 = (((bal4 / nickels) - qt5) * nickels);
	qt6 = bal5 / pennies;
	qt6 = (int)qt6;
	bal6 = (((bal5 / pennies) - qt6) * pennies);
	float avg_it = (f_total / (num1 + num2 + num3));
	printf("Toonies  %3d %9.4lf\n", (int)qt1, bal1);
	printf("Loonies  %3d %9.4lf\n", (int)qt2, bal2);
	printf("Quarters %3d %9.4lf\n", (int)qt3, bal3);
	printf("Dimes    %3d %9.4lf\n", (int)qt4, bal4);
	printf("Nickels  %3d %9.4lf\n", (int)qt5, bal5);
	printf("Pennies  %3d %9.4lf\n", (int)qt6, bal6);
	printf("\n");
	printf("Average cost/shirt: $%.4lf", avg_it);
	printf("\n");
    return 0;
}