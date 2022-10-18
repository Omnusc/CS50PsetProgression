#include <cs50.h>
#include <stdio.h>


int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    //Quarter = 25cents
    //Dimes = 10cents
    //Nickle = 5cents
    //Penny = 1cent
    int price, pay, cents;
    // ask the item price
    do
    {
    price = get_int("Price= ");
    // ask how much the customer pay
    pay = get_int("Payment= ");
    //  how many cents the customer is owed
    cents = pay - price;
    if(pay<price)
    {
        printf("Payment is not enough\n");
    }
    }
    while(pay<price);



    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    printf("Quarter = %i coins\n", quarters);

    // so we got how many quarters  we need in the int quarters variable
    // cents now updated by the formula below, cents e.g 55, so the new cents = 55 - (2) * 25 = 5 cents left
    // the 2 is the int quarters from the function below

    cents = cents - quarters * 25;

    // printf("%i\n", cents);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    printf("Dimes = %i coins\n", dimes);
    // printf("%i\n", cents);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    printf("Nickels = %i coins\n", nickels);
    // printf("%i\n", cents);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    printf("Pennies = %i coins\n", pennies);
    // printf("%i\n", cents);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;


    printf("%i\n", coins);
}



int calculate_quarters(int cents)
{
    // so we count by subsracting the cent by 25 and we loop it until the cent value is less than 25, while there's a counter
    // that keep counting by plus 1 if the substraction successfull
    int counter = 0;
    while(cents >= 25)
    {
        cents = cents - 25;
        counter++;
    }
    return counter;
}

int calculate_dimes(int cents)
{
    // same principal as before, but now we substarct it by 10 because it's  a dime, and we count it to if we can substract it by 1
    // TODO
    int counter = 0;
    while(cents >= 10)
    {
        cents = cents - 10;
        counter++;
    }
    return counter;
}

int calculate_nickels(int cents)
{
    // Sameeeee, substract by  5, nickel;
    // TODO
    int counter = 0;
    while(cents >=5)
    {
        cents = cents - 5;
        counter++;
    }
    return counter;

}

int calculate_pennies(int cents)
{
    // Sameeeee, substract by  1, pennies;
    // TODO
    int counter = 0;
    while(cents >= 1)
    {
        cents = cents - 1;
        counter++;
    }
    return counter;

}
