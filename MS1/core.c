/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "core.h"

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
    int value = 0;
    char newline = 0;
    do {
        scanf("%d%c", &value, &newline);
        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (newline != '\n');
    return value;
}

int inputIntPositive(void)
{
    int input;
    char newline;
    do {
        scanf("%d%c", &input, &newline);
        if (newline != '\n' || input <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (newline != '\n' || input <= 0);
    return input;
}

int inputIntRange(int minValue, int maxValue)
{
    int input = 0;
    char newline;
    do {
        scanf("%d%c", &input, &newline);
        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (input < minValue || input > maxValue)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", minValue, maxValue);
        }
    } while (input < minValue || input > maxValue || newline != '\n');
    return input;
}

char inputCharOption(const char validChar[])
{
    char input;
    int length = 0;
    int i;
    int flag = 0;
    do {
        scanf("%c", &input);
        clearInputBuffer();
        for (i = 0; validChar[i] != '\0'; i++)
        {
            length = i + 1;
        }
        for (i = 0; i < length && flag == 0; i++)
        {
            if (input == validChar[i])
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("ERROR: Character must be one of [%s]: ", validChar);
        }
    } while (!flag);
    return input;
}

void inputCString(char* charStr, int minChar, int maxChar)
{
    char input[100] = { '\0' };
    int length = 0;
    int flag = 0;
    int i = 0;
    do {
        scanf(" %[^\n]", input);
        clearInputBuffer();
        for (i = 0; input[i] != '\0'; i++)
        {
            length = i + 1;
        }
        if (minChar == maxChar)
        {
            if (length != minChar)
            {
                printf("ERROR: String length must be exactly %d chars: ", minChar);
            }
            else
            {
                flag = 1;
            }
        }
        else
        {
            if (length < minChar)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
            }
            else if (length > maxChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
            }
            else
            {
                flag = 1;
            }
        }
    } while (flag == 0);
    for (i = 0; i < length; i++)
    {
        charStr[i] = input[i];
    }
    charStr[length] = '\0';
}


void displayFormattedPhone(const char* phoneNum)
{
    int flag = 1;
    int i = 0;

    if (phoneNum != NULL)
    {
        for (i = 0; phoneNum[i] && flag; i++)
        {
            if (phoneNum[i] < 48 || phoneNum[i] > 57)
            {
                flag = 0;
            }
        }
    }

    if (flag == 1 && i == 10)
    {
        printf("(");
        for (i = 0; i < 3; i++)
            printf("%c", phoneNum[i]);
        printf(")");
        for (i = 3; i < 6; i++)
            printf("%c", phoneNum[i]);
        printf("-");
        for (i = 6; i < 10; i++)
            printf("%c", phoneNum[i]);
    }
    else
    {
        printf("(___)___-____");
    }
}