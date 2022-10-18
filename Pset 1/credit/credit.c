#include <cs50.h>
#include <stdio.h>
#include <math.h>
// luhn algorithm checking credit card validility
int firstNumber (long cardNumber);
int main(void)
{
    //4003600000000014
    int totalSum = 0;
    long cardNumber;
    do
    {
        cardNumber = get_long("Credit Number: "); // get number
    }
    while (cardNumber < 0);
     //luhn algorotm
    // e.g number 123, to get last number modular by 10
    // so 123/10 is 12.3. the modular is 3 then then last digit is 3
    // 2nd number = modular by 100
    // 123/100 = 1.23 the modular is 23 then divide it by 10 to get int 2
    long temp1 = cardNumber;
    long temp2 = cardNumber/10;
    long temp3 = cardNumber;
    int length = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (temp1 > 0) // to get the last digit that will not multiplied by 2
    {
        int firstNumber = temp1 % 10;
        sum1 = sum1 + firstNumber;
        temp1 /= 100;
    }
    // to get the "underline number" and multiply it etc etc
    while (temp2 > 0)
    {
        int firstNumber = temp2 % 10;
        int multiply = firstNumber*2;
        sum2 = sum2 + (multiply % 10) + (multiply / 10);
        temp2 /= 100;
    }
    //count lenght
    while(temp3 > 0)
    {
        temp3 /= 10;
        length++;
    }
    int sumTotal = sum1+sum2;
    if (sumTotal % 10 == 0)
    {
        // we check the visa first number by using modular or divide until there's only one digit because visa only use the 1st digit
        long temp4 = cardNumber;
        int firstNumberVisa ;
        while(temp4 > 10)
        {
            firstNumberVisa = temp4 / 10; // so for e.g the digit 123, first loop we will get  a value of 12, and the temp will be 12 because temp is an int so the 0.3 is deleted, it loop
                                          //  until we only have value of digit less than 10 and the it stopped
            temp4 /= 10;
        }
        if(firstNumberVisa == 4 && (length == 13 || length == 14 || length == 15 || length == 16)  )
        {
            printf("VISA\n");
        }
        else
        {
            int firstNumberAX = firstNumber(cardNumber);
            if ((firstNumberAX == 34 || firstNumberAX == 37) && (length == 15))
            {
                printf("AMEX\n");
            }
            else
                 {
                    int firstNumberMaster = firstNumber(cardNumber);
                     if((firstNumberMaster == 51 || firstNumberMaster == 52 || firstNumberMaster == 53 || firstNumberMaster == 54 || firstNumberMaster == 55 ) && (length == 16))
                 {
                    printf("MASTERCARD\n");
                 }
                    else
                    {
                         printf("INVALID\n");
                    }
                }

        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int firstNumber (long temp)
{
    int firstNumber;
    while(temp > 100)
    {
       firstNumber = temp / 10;
        temp /=10;
    }
    return firstNumber;
}