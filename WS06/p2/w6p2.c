/*
*****************************************************************************
                          Workshop - #6 (P2)
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
    double net_income, sum = 0, month, year, sum_priority = 0;
    double cost[max_items];
    int priority[max_items];
    char finance_option[max_items];
    int items, i, select, flag = 1,priority_select, c=1;
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
   

    


    
    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &select);      
       
        if (select == 0)
        {
            flag = 0;
            printf("\n");
            printf("Best of luck in all your future endeavours!\n");
            printf("\n");
        }
        else if (select == 1)
        {
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n",sum);
            year = (int)(sum / net_income)/12;            
            month = (int)(((((sum / net_income) / 12) - year) * 12) + 0.5);  // Mathematical step to calculate the modulous of any data type(float/int/double) and 0.5 is added to round off the number         
            printf("Forecast: %.0lf years, %.0lf months\n",year,month);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n");
            printf("\n");
                
        }
        else if (select == 2)
        {
            printf("\n");
            do
            {
                c = 1;
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priority_select);
                sum_priority = 0;
                for (i = 0; i < items; i++)
                {
                    if (priority_select == priority[i])
                    {
                        sum_priority = sum_priority + cost[i];                        
                    }                    
                }
                printf("\n");
                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", priority_select);
                printf("Amount:   $%.2lf\n", sum_priority);
                 year = (int)(sum_priority / net_income) / 12;
                month = (((((sum_priority / net_income) / 12) - (year)) * 12) +( 0.5));
              // year = (int)(sum_priority / net_income) / 12;
              //  month = (int)(sum_priority / net_income) % 12; //calculating the modulous using modulous operator
                printf("Forecast: %.0lf years, %.0lf months\n", year, month);


                for (i = 0; (i < items)&& (c==1); i++)
                {
                    if ((priority[i] == priority_select) && (finance_option[i] == 'y'))
                    {
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                        c = 0;
                    }
                }
                printf("====================================================\n");                

            } while (!(priority_select >= 1 && priority_select <= 3));
            
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
        }
    } while (flag);
    
    return 0;
}

