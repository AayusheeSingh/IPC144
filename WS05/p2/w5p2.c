/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int year, month;
    const int JAN = 1;
    const int DEC = 12;
    int i;
    double morning_rating, evening_rating,evening_total=0,morning_total=0;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if ((year < MIN_YEAR || year > MAX_YEAR) && (month< JAN && month > DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while ((year < MIN_YEAR || year>MAX_YEAR) || (month< JAN || month > DEC));
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");
    
   
    for (i = 1; i <= LOG_DAYS; i++)
    {    
        switch (month)
        {
            case 1:
            printf("%d-JAN-0%d\n", year, i);
            break;
            case 2:
            printf("%d-FEB-0%d\n", year, i);
            break;
            case 3:
            printf("%d-MAR-0%d\n", year, i);
            break;
            case 4:
            printf("%d-APR-0%d\n", year, i);
            break;
            case 5:
            printf("%d-MAY-0%d\n", year, i);
            break;
            case 6:
            printf("%d-JUN-0%d\n", year, i);
            break;
            case 7:
            printf("%d-JUL-0%d\n", year, i);
            break;
            case 8:
            printf("%d-AUG-0%d\n", year, i);
            break;
            case 9:
            printf("%d-SEP-0%d\n", year, i);
            break;
            case 10:
            printf("%d-OCT-0%d\n", year, i);
            break;
            case 11:
            printf("%d-NOV-0%d\n", year, i);
            break;
            case 12:
            printf("%d-DEC-0%d\n", year, i);
            break;
            default:
                printf("invalid");

        }
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morning_rating);

                if ((morning_rating < 0.0) || (morning_rating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
               
            } while ((morning_rating < 0) || (morning_rating > 5.0));
            morning_total += morning_rating;

            do
             {
                 printf("   Evening rating (0.0-5.0): ");
                 scanf("%lf", &evening_rating);

                 if ((evening_rating < 0.0) || (evening_rating > 5.0))
                 {
                     printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                 }
                 
             } while ((evening_rating<0.0)||(evening_rating > 5.0));
             evening_total += evening_rating;
             printf("\n");
     }       
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n",morning_total);
    printf("Evening total rating:  %.3lf\n",evening_total);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n",(morning_total+evening_total));
    printf("\n");
    printf("Average morning rating:  %.1lf\n",morning_total/ LOG_DAYS);
    printf("Average evening rating:  %.1lf\n",evening_total/ LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (((morning_total / LOG_DAYS)+(evening_total / LOG_DAYS))/2));
    printf("\n");
    return 0;
}

