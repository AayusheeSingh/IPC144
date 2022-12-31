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
    int num;
    char ch;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    
    do
    {
        printf("\n");
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d",&ch,&num);         

        if (ch=='Q')
        {
            if (num==0)
            {
                printf("\n");
            }
            else
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
                
            }
        }

        else if (ch=='D')
        {
            if (num>=3 && num<=20)
            {
                int c=1;
                printf("DO-WHILE: ");
                do 
                {
                    printf("D");
                    c++;
                }
                while(c <= num);
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }

        else if (ch == 'W')
        {
            if (num >= 3 && num <= 20)
            {
                int c = 1;
               
                printf("WHILE   : ");
                while (c <= num)
                {
                    printf("W");
                    c++;
                }
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        



        else if (ch == 'F')
        {
            if (num >= 3 && num <= 20)
            {
                int c = 1;
                
                printf("FOR     : ");
                for (c = 1; c <= num; c++)
                {
                    printf("F");
                }
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }

        else
        {
            printf("ERROR: Invalid entered value(s)!");
            printf("\n");
        }       

    } while (ch!='Q'||num!=0);
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    
    return 0;
}