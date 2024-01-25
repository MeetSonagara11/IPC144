

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function guarantees that an integer value is entered and returned, and displays an error message if necessary
int inputInt(void);

// This function guarantees a positive integer value is entered and returned. If 0 or a negative value is entered, an error message would be displayed.
int inputIntPositive(void);

// This function guarantees that an integer value is entered within the range and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lowerBound, int upperBound);

// This function guarantees a single character value is entered within the list of valid characters and returned
char inputCharOption(char str[]);

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar);

// It displys an array of 10-character digits
void displayFormattedPhone(const char* str);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
