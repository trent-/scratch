#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_CHARS 26

char encrypt(char input, int rotateBy);

int main(int argc, string argv[])
{
    //validate command line args
    if (argc != 2)
    {
        printf("You must supply at minimum and at most one command line argument. e.g. ./caeser 4. PLEASE TRY AGAIN!!!!\n");
        return 1;
    }

    //convert string input to int
    int rotateBy = atoi(argv[1]);

    string plainTextMessage = GetString();

    for(int i = 0, len = strlen(plainTextMessage); i < len; i++){
        printf("%c", encrypt(plainTextMessage[i], rotateBy));
    }
    printf("\n");
}

char encrypt(char input, int rotateBy)
{
    //define character codes
    int lowerCaseOffset = 'a';
    int upperCaseOffset = 'A';

    int offset = 0;
    char encrypted;

    if (islower(input))
    {
        offset = lowerCaseOffset;
    }
    else if (isupper(input))
    {
        offset = upperCaseOffset;
    }
    else
    {
        //We're not encrypting non-alpha characters, so return as is
        return input;
    }

    //Reduce it by the offset to get it in base 26
    encrypted = input - offset;

    //Shift it forward by the specified int
    encrypted += rotateBy;

    //Restore it to base 26 by getting the modulous
    encrypted %= NUM_CHARS;

    //Add the offset to get it back into an upper/lowercase char
    encrypted += offset;

    return encrypted;
}
