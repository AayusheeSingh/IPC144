/*
*****************************************************************************
                          Workshop - #4 (P1)
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
    int apples,oranges,pears,tomatoes,cabbages,shopping_choice=1;
    int pick;
    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
        printf("\n");


        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");


        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");


        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");


        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        if (apples > 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",apples);
                }
                else if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else
                {
                    apples = apples - pick;
                    if (apples == 0)
                    {
                        printf("Great, that's the apples done!\n");
                    }
                    else
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
            } while (apples > 0);
            printf("\n");
        }
        


        if (oranges > 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n",oranges);
                }

                else if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }

                else
                {
                    oranges = oranges - pick;

                    if (oranges == 0)
                    {
                        printf("Great, that's the oranges done!\n");
                    }
                    else
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
            } while (oranges > 0);
            printf("\n");
        }
        


        if (pears > 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n",pears);
                }

                else if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }

                else
                {
                    pears=pears - pick;

                    if (pears == 0)
                    {
                        printf("Great, that's the pears done!\n");
                    }
                    else
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                }
            } while (pears > 0);
            printf("\n");
        }
        


        if (tomatoes > 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n",tomatoes);
                }

                else if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }

                else
                {
                    tomatoes=tomatoes-pick;
                    if (tomatoes == 0)
                    {
                        printf("Great, that's the tomatoes done!\n");
                    }
                    else
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
            } while (tomatoes > 0);
            printf("\n");
        }
        


        if (cabbages > 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pick);
                if (pick > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n",cabbages);
                }

                else if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }

                else
                {
                    cabbages=cabbages - pick;

                    if (cabbages == 0)
                    {
                        printf("Great, that's the cabbages done!\n");
                    }
                    else
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
            } while (cabbages > 0);
            printf("\n");
        }
        
        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopping_choice);
        printf("\n");
    }
    while (shopping_choice == 1);
    printf("Your tasks are done for today - enjoy your free time!\n");
    printf("\n");   
    return 0;

}