#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cardNumber = get_long("Number: ");
    int productsSum = 0, otherSum = 0;
    
    // Figure out how many digits in a number.
    long tempCard = cardNumber;
    int digitsCount = 0;
    while (tempCard != 0)
    {
        tempCard = tempCard / 10;
        digitsCount += 1;
    }
    
    if (digitsCount != 13 && digitsCount != 15 && digitsCount != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Validate checksum.
    for (int i = 1; i <= digitsCount; i += 1)
    {   
        if (i % 2 == 0)
        {
            // If the current digit starting second-to-last is even
            // then multiply it to 2 and add to the productsSum.
            int num = (cardNumber % (long) pow(10, i) / (long) pow(10, i - 1)) * 2;
            productsSum += (num / 10) + (num % 10);
        }
        else
        {
            // If the digit is not even, then add it to otherSum
            otherSum += cardNumber % (long) pow(10, i) / (long) pow(10, i - 1);
        }
    }
    // if checkSum last digit is not 0 then
    if ((productsSum + otherSum) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Get the two first digits of a credit card number.
    int firstNumber = cardNumber / pow(10, digitsCount - 2);
    
    // If number starts from 4, then it is VISA.
    if (firstNumber >= 40 && firstNumber <= 49)
    {
        printf("VISA\n");
        return 0;
    }
    // Check for other credit card systems.
    switch (firstNumber)
    {
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("MASTERCARD\n");
            break;
        
        default:
            printf("INVALID\n");
            return 0;
    }
    
}
