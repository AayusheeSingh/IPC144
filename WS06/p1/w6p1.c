/*
*****************************************************************************
                          Workshop - #6 (P1)
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
#define max_items 10
#include <stdio.h>

int main(void)

{
    const double min_monthly_income = 500.00;
    const double max_monthly_income = 400000.00;
    const double max_cost = 100.00;
    double net_income, sum = 0;
    double cost[max_items];
    int priority[max_items];
    char finance_option[max_items];
    int items, i;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");


    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &net_income);
        if (net_income < min_monthly_income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            printf("\n");
        }
        else if (net_income > max_monthly_income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            printf("\n");
        }
    } while (net_income< min_monthly_income || net_income>max_monthly_income);
    printf("\n");

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &items);
        if (items<1 || items>max_items)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            printf("\n");
        }

    } while (items<1 || items>max_items);
    printf("\n");



    for (i = 0; i < items; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do
        {

            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < max_cost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < max_cost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c*c", &finance_option[i]);
            if (!((finance_option[i] == 'y') || (finance_option[i] == 'n')))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!((finance_option[i] == 'y') || (finance_option[i] == 'n')));
        printf("\n");
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < items; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance_option[i], cost[i]);
        sum = sum + cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);
    printf("Best of luck in all your future endeavours!");
    printf("\n");






    return 0;
}


/*   PDF Provided Formatting:
Step #7 (a):
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
Step #7 (b):
    printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemCanFinance[i], itemCost[i]);
*/