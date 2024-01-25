/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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

#include <stdio.h>

int main(void){

    
    // You must use this variable in #3 data analysis section!
   
    //Variable
    const double testValue = 330.99;
    const int productID1 = 111, productID2 = 222, productID3 = 111;
    const double pricep1 = 111.4900, pricep2 = 222.9900, pricep3 = 334.4900;
    const char tax1 = 'Y', tax2 = 'N', tax3 = 'N';
    double avg = (pricep1 + pricep2 + pricep3) / 3;

    printf("Product Information\n===================\n");

    //Product 1
    printf("Product-1 (ID:%d)\n",productID1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%.4lf\n\n", pricep1);


    //Product 2
    printf("Product-2 (ID:%d)\n", productID2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%.4lf\n\n", pricep2);

    //Product 3
    printf("Product-3 (ID:%d)\n", productID3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%.4lf\n\n", pricep3);

    //Notes
    printf("The average of all prices is: $%.4lf\n\n",avg);
    printf(
        "About Relational and Logical Expressions!\n"
        "========================================\n"
        "1. These expressions evaluate to TRUE or FALSE\n"
        "2. FALSE: is always represented by integer value 0\n"
        "3. TRUE : is represented by any integer value other than 0\n\n"
    );

    //Data Analysis
    printf("Some Data Analysis...\n=====================\n");
    
    printf("1. Is product 1 taxable? -> %d\n\n",tax1 == 'Y');
    
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", tax2 == 'N' && tax3 == 'N');
    
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", pricep3 < testValue);
    
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", pricep3 > pricep1 + pricep2);
    
    printf(
        "5. Is the price of product 1 equal to or more than the price difference\n"
        "   of product 3 LESS product 2? ->  %d",pricep1 >= (pricep3 - pricep2));
    printf(" (price difference: $%.2lf)\n\n", pricep3 - pricep2);

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",avg >= pricep2 );

    printf("7. Based on product ID, product 1 is unique -> %d\n\n", productID1 != productID2 && productID1 != productID3);

    printf("8. Based on product ID, product 2 is unique -> %d\n\n", productID2 != productID1 && productID2 != productID3);

    printf("9. Based on product ID, product 3 is unique -> %d\n", productID3 != productID1 && productID3 != productID2);
    return 0;
}