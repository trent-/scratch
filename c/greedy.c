#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define COIN_TYPE_COUNT 4

int main(void)
{

    int coins[COIN_TYPE_COUNT] = {25, 10, 5, 1};

    float dollarsCentsInput;

    do
    {
        printf("O hai! How much change is owed?\n");

        //Get the money value in dollars and cents
        dollarsCentsInput =  GetFloat();
    }
    while (!(dollarsCentsInput > 0));

    //Convert it to cents to deal with precision issues
    int centsInput = round(dollarsCentsInput * 100);

    //Variable to store the minimum # coins it takes to refund
    int totalCoins = 0;

    for (int i = 0; i < COIN_TYPE_COUNT; i++)
    {

        if (centsInput > 0)
        {
            //How many can the current coin divide into the change?
            int coinCount = centsInput / coins[i];
            //Add that to the total coin count
            totalCoins += coinCount;
            //Reduce input by number of coins of current value just refunded
            centsInput -= coins[i] * coinCount;
        }

    }

    printf("%i\n", totalCoins);

}
