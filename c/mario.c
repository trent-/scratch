#include <cs50.h>
#include <stdio.h>

#define FIRST_ROW_HASHES 2

void printNChars(int numTimes, char output)
{

    for(int i = 0; i < numTimes ; i++)
    {
        printf("%c", output);
    }

}

int main(void)
{
    //Get a positive int betweem 1 and 23
    int numSteps;
    do
    {

        printf("How high would you like Mario to climb? (Between 1 and 23 inclusive): ");
        numSteps = GetInt();

        if (numSteps == 0)
        {
            return 0;
        }

    } while (!(numSteps > 0 && numSteps <= 23) );

    //Print each step
    for (int i = 0; i < numSteps; i++)
    {
        //get row spaces and hashes counts
        int spaces = numSteps - (i+1);
        int hashes = i+FIRST_ROW_HASHES;

        //print left side
        printNChars(spaces, ' ');
        printNChars(hashes, '#');

        //New line for next row
        printf("\n");

    }


}
