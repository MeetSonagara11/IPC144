/*

/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
#include<stdio.h>
int main()
{
    int pat, tom, sal, patTax, tomTax, salTax, loon, toon, quart, dimes, nick, penny, salTtl, tomTtl, patTtl, patSubttl, tomSubttl, salSubttl;
    double priceS, priceM, priceL;
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double subttl, ttl, tax, avg, average, bal;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceS);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &priceM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceL);
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n", priceL);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pat);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tom);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sal);
    printf("\n");

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    patSubttl = priceS * pat * 100;
    patTax = TAX * patSubttl + 0.5;
    patTtl = patSubttl + patTax;

    salSubttl = priceM * sal * 100;
    salTax = TAX * salSubttl + 0.5;
    salTtl = salSubttl + salTax;

    tomSubttl = priceL * tom * 100;
    tomTax = TAX * tomSubttl + 0.5;
    tomTtl = tomSubttl + tomTax;

    printf("Patty %4c    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceS, pat, (double)patSubttl / 100, (double)patTax / 100, (double)patTtl / 100);
    printf("Sally %4c    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, priceM, sal, (double)salSubttl / 100, (double)salTax / 100, (double)salTtl / 100);
    printf("Tommy %4c    %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceL, tom, (double)tomSubttl / 100, (double)tomTax / 100, (double)tomTtl / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subttl = (int)patSubttl + salSubttl + tomSubttl;
    tax = (int)patTax + salTax + tomTax;
    ttl = (int)patTtl + salTtl + tomTtl;

    printf("%33.4lf %9.4lf %9.4lf\n\n", (double)subttl / 100, (double)tax / 100, (double)ttl / 100);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subttl / 100);
    toon = subttl / 200;
    bal = (int)subttl % 200;
    printf("Toonies  %3d %9.4lf\n", toon, bal / 100);
    loon = bal / 100;
    bal = (int)bal % 100;
    printf("Loonies  %3d %9.4lf\n", loon, bal / 100);
    quart = bal / 25;
    bal = (int)bal % 25;
    printf("Quarters %3d %9.4lf\n", quart, bal / 100);
    dimes = bal / 10;
    bal = (int)bal % 10;
    printf("Dimes    %3d %9.4lf\n", dimes, bal / 100);
    nick = bal / 5;
    bal = (int)bal % 5;
    printf("Nickels  %3d %9.4lf\n", nick, bal / 100);
    penny = bal;
    bal = (int)bal % 1;
    printf("Pennies  %3d %9.4lf\n", penny, bal / 100);
    avg = subttl / (pat + sal + tom);
    printf("\n");
    printf("Average cost/shirt: $%.4lf", avg / 100.0);
    printf("\n\n");
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", ttl / 100);
    toon = ttl / 200;
    bal = (int)ttl % 200;
    printf("Toonies  %3d %9.4lf\n", toon, bal / 100);
    loon = bal / 100;
    bal = (int)bal % 100;
    printf("Loonies  %3d %9.4lf\n", loon, bal / 100);
    quart = bal / 25;
    bal = (int)bal % 25;
    printf("Quarters %3d %9.4lf\n", quart, bal / 100);
    dimes = bal / 10;
    bal = (int)bal % 10;
    printf("Dimes    %3d %9.4lf\n", dimes, bal / 100);
    nick = bal / 5;
    bal = (int)bal % 5;
    printf("Nickels  %3d %9.4lf\n", nick, bal / 100);
    penny = bal / 1;
    bal = (int)bal % 1;
    printf("Pennies  %3d %9.4lf\n", penny, bal / 100);
    average = ttl / (pat + sal + tom);
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", average / 100.0);

    return 0;
}