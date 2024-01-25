/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name   :
Student ID# :
Email       :
Section     :
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
******************************************************************************
*/

//For More Contact me on instagram or mail
//Instagram: @meetsonagara1101
//Mail : connect.meetsonagara1101@gmail.com


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    
    //Variables For Coffee 1, Coffee 2, Coffee 3

    char type1, type2, type3, strength1, strength2;
    int bagweight1 = 0, bagweight2 = 0, bagweight3 = 0, servings1 = 0, servings2 = 0;
    char cream1 = 'A', cream2 = 'B', cream3 = 'C', cream4 = 'D', cream5 = 'E';

    //char coffstr1, coffstr2, coffeq1, coffeq2, crwcoff1, crwcoff2;
    //int  Dlserve1, Dlserve2;

    printf("Take a Break - Coffee Shop\n==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    //COFFEE-1
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c*", &type1);
    printf("Bag weight (g): ");
    scanf(" %d*", &bagweight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c*", &cream1);
    printf("\n");

    //COFFEE-2
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf(" %d", &bagweight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\n");

    //COFFEE-3
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf(" %d", &bagweight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n");

    //Table1
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G)  | Lbs   | Cream |\n");
    printf("---+------------------------+---------------+-------+\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type1 == 'L' || type1 == 'l',
        type1 == 'M' || type1 == 'm',
        type1 == 'R' || type1 == 'r',
        bagweight1, bagweight1 / GRAMS_IN_LBS,
        cream1 == 'Y' || cream1 == 'y',
        cream1 == 'N' || cream1 == 'N');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type2 == 'L' || type2 == 'l',
        type2 == 'M' || type2 == 'm',
        type2 == 'R' || type2 == 'r',
        bagweight2, bagweight2 / GRAMS_IN_LBS,
        cream2 == 'Y' || cream2 == 'y');

    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
        type3 == 'L' || type3 == 'l',
        type3 == 'M' || type3 == 'm',
        type3 == 'R' || type3 == 'r',
        bagweight3, bagweight3 / GRAMS_IN_LBS,
        cream3 == 'Y' || cream3 == 'y');

    //Inputs For Prefrence Table 1
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream4);
    printf("Typical number of daily servings : ");
    scanf(" %d", &servings1);
    printf("\n\n");

    //Prefrence Table 1
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", strength1 == 'l' || strength1 == 'L' , servings1 == 1 || servings1 <=4, cream4 == 'Y' || cream4 == 'y');

    printf(" 2|       %d         |      %d      |   %d   |\n", strength1 == 'm' || strength1 == 'M' , servings1 >= 5 && servings1 <=9,cream4 == 'N' || cream4 == 'n');

    printf(" 3|       %d         |      %d      |   %d   |\n", strength1 == 'R' || strength1 == 'R' , servings1 >= 10, cream4 == 'N' || cream4 == 'n');

    //Inputs For Prefrence Table 2
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &strength2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream5);
    printf("Typical number of daily servings : ");
    scanf(" %d", &servings2);
    printf("\n\n");

    //Prefrence Table 2
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", strength2 == 'l' || strength2 == 'L', servings2 == 1 || servings2 <= 4, cream5 == 'Y' || cream5 == 'y');

    printf(" 2|       %d         |      %d      |   %d   |\n", strength2 == 'R' || strength2 == 'r', servings2 >= 5 && servings2 <= 9, cream5 == 'N' || cream5 == 'n');

    printf(" 3|       %d         |      %d      |   %d   |\n", strength2 == 'M' || strength2 == 'm', servings2 >= 10, cream5 == 'N' || cream5 == 'n');

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}