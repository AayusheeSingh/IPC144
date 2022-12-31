/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include<stdio.h>
#include"core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
int inputInt(void)
{
    int num;
    char letter;
    do
    {
        scanf("%d%c", &num, &letter);
        if (letter != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (letter != '\n');

    return num;
}

int inputIntPositive(void)
{
    int num;
    do
    {
        num = inputInt();        
            if (num <= 0)
            {
                printf("ERROR! Value must be > 0: ");
            }
    } while (num<=0);

    return num;
}
int inputIntRange(int lowerBound, int upperBound)
{
    int num;
    do
    {       
        num = inputInt();
        if (num <lowerBound || num>upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ",lowerBound,upperBound);
        }
    } while (num <lowerBound || num>upperBound);

    return num;
}

char inputCharOption(const char list[])
{
    int flag = 0,i;
    char letter;
    char letter1;

    do
    {
        
        scanf("%c%c", &letter, &letter1);
        if (letter1 != '\n')
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", list);
        }
        else
        {
            for (i = 0; list[i] != '\0'; i++)
            {
                if (letter == list[i])
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                printf("ERROR: Character must be one of [%s]: ", list);
            }
        }
    } while (flag == 0);
    return letter;
}

void inputCString(char* str, int min, int max)
{
    int flag = 1, i=0,len = 0;
    char string[100] = { '\0'};
    do
    {
        scanf("%[^\n]", string);   
        clearInputBuffer();

        for (len = 0; string[len] != '\0'; len++)
        {
            ;
        } 
        
        
        if (len >= min && len <= max)
        {
            for (i = 0; i<len; i++)
            {
               str[i] = string[i];
            }
           flag = 0;      
            
        }
        else if (min == max && len!= min)
        {
           
            printf("ERROR: String length must be exactly %d chars: ", min);

        }
        else if (len < min || len > max)
        {
            if (len > max)
            {
               
                printf("ERROR: String length must be no more than %d chars: ", max);

            }
            else if (len < min)
            {
               
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
       
    } while (flag);
}        
void displayFormattedPhone(const char* cstring)
{
    int len = 0,i;
    while (cstring!=NULL &&(cstring[len] >= '0' && cstring[len] <= '9'))
    {
        len++;
    }    
   
    if (len == 10)
    {
        for (i = 0; i < len; i++)
        {
            if (i == 0)
            {
                printf("(");
            }
            if (i == 3)
            {
                printf(")");
            }
            if (i == 6)
            {
                printf("-");
            }
            printf("%c", cstring[i]);
        }           
    }
   else
   {
        printf("(___)___-____");
   }   
   
    return;
}
