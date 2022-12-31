/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  :Aayushee Singh
Student ID#:173927211
Email      :asingh1221@myseneca.ca
Section    :NHH
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);
    char type1, type2, type3;
    char grindsize1, grindsize2, grindsize3;
    int bag_weight1, bag_weight2, bag_weight3;
    char cream1, cream2, cream3;
    double temp1, temp2, temp3;
    char coffee_st, like, maker;
    int ds;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type1);    
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsize1);    
    printf("Bag weight (g): ");
    scanf("%d", &bag_weight1);    
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);    
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf",&temp1);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsize2);
    printf("Bag weight (g): ");
    scanf("%d", &bag_weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c*c",&cream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf",&temp2);
    printf("\n");
    


    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &type3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindsize3);
    printf("Bag weight (g): ");
    scanf("%d", &bag_weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c*c", &cream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temp3);
    printf("\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");   
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",(type1=='l'||type1=='L'),(type1 == 'B'),(grindsize1 == 'c'), (grindsize1 == 'F' || grindsize1 == 'f'), (bag_weight1), (bag_weight1 / GRAMS_IN_LBS), (cream1 == 'y'), (temp1), ((temp1 * 1.8) + 32.0));
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",(type2=='l'||type2=='L'),(type2 == 'B'),(grindsize2 == 'c'), (grindsize2 == 'F' || grindsize2 == 'f'), (bag_weight2), (bag_weight2 / GRAMS_IN_LBS), (cream2 == 'y'), (temp2), ((temp2 * 1.8) + 32.0));
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",(type3=='l'||type3=='L'),(type3 == 'B'),(grindsize3 == 'c'), (grindsize3 == 'F' || grindsize3 == 'f'), (bag_weight3), (bag_weight3 / GRAMS_IN_LBS), (cream3 == 'y'), (temp3), ((temp3 * 1.8) + 32.0));
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");    
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c",&coffee_st);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c*c",&like);
    printf("Typical number of daily servings: ");
    scanf("%d",&ds);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c",&maker);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");  
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",((type1=='l'|| type1=='L')&&(coffee_st=='m')),((grindsize1=='F'|| grindsize1 =='f')&&(maker=='c')),((ds>=5||ds<=9)&&(bag_weight1==500)),((like=='y')&&(cream1=='y')),((maker=='c')&&(temp1>=70.0)));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",((type2=='l'|| type2 == 'L')&&(coffee_st=='m')),((grindsize2=='F'|| (grindsize2 == 'f'))&&(maker=='c')),((ds>=5||ds<=9)&&(bag_weight2==500)),((like=='y')&&(cream2=='y')),((maker=='c')&&(temp2>=70.0)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",((type3=='l'||type3=='L') && (coffee_st == 'm')), ((grindsize3=='F'||grindsize3=='f')&& (maker == 'c')), ((ds >= 5 || ds <= 9) && (bag_weight3 == 500)), ((like == 'y') && (cream3 == 'y')), ((maker == 'c') && (temp3 >= 70.0)));
    printf("\n");
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n");
    printf("\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffee_st);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c*c", &like);
    printf("Typical number of daily servings: ");
    scanf("%d", &ds);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (type1 == 'b' || type1 == 'B') && (coffee_st == 'R'), (grindsize1 == 'c' || grindsize1 == 'C') && (maker == 'R'), (ds >= 10) && (bag_weight1 == 1000), (like == 'N') && (cream1 == 'n' || cream1 == 'N'), (maker == 'R') && ((temp1 >= 60.0) && (temp1 <= 69.9)));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (type2 == 'b' || type2 == 'B') && (coffee_st == 'R'), (grindsize2 == 'c' || grindsize2 == 'C') && (maker == 'R'), (ds >= 10) && (bag_weight2 == 1000), (like == 'N') && (cream2 == 'n' || cream2 == 'N'), (maker == 'R') && ((temp2 >= 60.0) && (temp2 <= 69.9)));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", (type3 == 'b' || type3 == 'B') && (coffee_st == 'R'), (grindsize3 == 'c' || grindsize3 == 'C') && (maker == 'R'), (ds >= 10) && (bag_weight3 == 1000), (like == 'N') && (cream3 == 'n' || cream3 == 'N'), (maker == 'R') && ((temp3 >= 60.0) && (temp3 <= 69.9)));

   /*printf(" 2|       %d         |        %d           |      %d      |   %d   |      %d       \n", ((type2 == 'b' || type2 == 'B') && (coffee_st == 'R')), ((grindsize2 == 'c' || (grindsize2 == 'C')) && (maker == 'R')), ((ds >= 10) && (bag_weight2 == 1000)), ((like == 'N') && (cream2 == 'N')), ((maker == 'R') && (temp2 >= 60.0 && temp2 <= 69.9)));
    printf(" 3|       %d         |        %d           |      %d      |   %d   |      %d       \n", ((type3 == 'b' || (type3 == 'B'))&& (coffee_st == 'R')), ((grindsize3 == 'c') || (grindsize3 == 'C')) && (maker == 'R')), ((ds >= 10) && (bag_weight3 == 1000)), ((like == 'N') && (cream3 == 'N')), ((maker == 'R') && (temp3 >= 60.0 && temp3 <= 69.9));*/

    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");
    return 0;



}