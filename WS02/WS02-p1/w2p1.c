/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P1)
Full Name :
Student ID# :
    Email :
    Section :
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
******************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    printf("Set Shirt Prices\n================\n");

    //Variables
    
    double sMall, mEDIUM, lARGE;
    const char patSize = 'S';
    int No_Shirt;

    //To take Shirt prices according to the size 

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &sMall);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mEDIUM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lARGE);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", sMall);
    printf("MEDIUM : $%.2lf\n", mEDIUM);
    printf("LARGE  : $%.2lf\n", lARGE);
    printf("\n");

    printf("Patty's shirt size is \'%c",patSize);
    printf("\'\n");
    
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &No_Shirt);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d", No_Shirt);
    printf(" shirts\n");

    // Variables For Billing

    const double TAX = 0.13;
    double sub = No_Shirt * sMall;
    
    sub = sub + 0.005;
    sub = sub * 100;
    sub = (int)sub;
    sub = sub / 100;

    double tax = sub * TAX;
    
    tax = tax + 0.005;
    tax = tax * 100;
    tax = (int)tax;
    tax = tax / 100;

    double tot = tax + sub;

    printf("Sub-total: $%8.4lf\n", sub);
    printf("Taxes    : $%8.4lf\n",tax);
    printf("Total    : $%8.4lf\n", tot);
 
    
    return 0;
}