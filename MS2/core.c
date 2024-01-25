

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ;
    }
}

// Wait for user to input the "enter" key to continue 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This function guarantees that an integer value is entered and returned, and displays an error message if necessary
int inputInt(void) {
    char character = ' ';
    int value;

    do {
        scanf(" %d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');

    // If the character after the integer is a new line character that means an appropriate value was entered
    return value;
}

// This function guarantees a positive integer value is entered and returned. If a 0 or a negative value in entered, an error message would be displayed.
int inputIntPositive(void) {
    char character = ' ';
    int value;

    do {
        scanf(" %d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);

    // After testing is completed we can return the value
    return value;
}

// This function guarantees that an integer value is entered within the range and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lowerBound, int upperBound) {
    char character = ' ';
    int value;

    do {
        scanf(" %d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(value <= upperBound && value >= lowerBound)) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while (!(value <= upperBound && value >= lowerBound));

    // Value can be returned after completion of process
    return value;
}

// This function guarantees a single character value is entered within the list of valid characters and returned. If an entered character is not in the list of valid characters, display an error message and prompt again.
char inputCharOption(char str[]) {
    int i, count = 0;
    char input;

    do {
        scanf(" %c", &input);

        for (i = 0; str[i] != '\0'; i++) {
            if (input == str[i]) {
                count++;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (count == 0);

    // After all testing is completed, we will return the input value
    clearInputBuffer();
    return input;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int length = 0;
        while (ch != '\n' && length <= maxChar) {
            ch = getchar();
            str[length] = ch;
            length++;
        };

        // If the string is less than or equal to the maxChar we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && length <= (maxChar + 1)) {
            length--;
            str[length] = '\0';
        }
        // If length is more than maxChar, then add '\0' at the end
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && length != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (length < minChar || length > maxChar) {
            if (length > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (length < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}

// The purpose of this function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* str) {
    int length = 0, i;

    while (str != NULL && str[length] && isdigit(str[length])) {
        length++;
    }
    if (length == 10) {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", str[i]);
            i++;
        }
        printf(")");
        while (i < 6) {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", str[i]);
            i++;
        }
    }
    else {
        printf("(___)___-____");
    }
    if (str != 0) {
        for (i = 0; str[i] != '\0'; i++)
            length++;
    }
}