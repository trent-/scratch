#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_CHARS 26

char encrypt(char source, char key);

int main(int argc, string argv[])
{

    //This program should be run with 1 argument: the key to encrypt the message with
    if (argc != 2)
    {
        printf("You must supply at minimum and at most one command line argument. e.g. ./caeser 4. PLEASE TRY AGAIN!!!!\n");
        return 1;
    }

    string keyword = argv[1];
    //validate they keyword doesn't contain any special chars
    for(int i = 0, len = strlen(keyword); i < len; i ++)
    {
        if(!(isalpha(keyword[i])))
        {
            printf("Your keyword must only contain alpha characters. Please try again\n");
            return 1;
        }
    }

    int keywordLength = strlen(keyword);

    //Fetch a string to encrypt
    string plainText = GetString();

    // Use a separate variable to determine the key to use to encrypt,
    // since it should only match when it is an alpha character.
    // Current code assumes string starts with an alpha numeric haracter.
    for (int i = 0, len = strlen(plainText), keypos = 0; i < len; i++)
    {
        int keyIndex = keypos % keywordLength;
        //Increment keypos by one only when the current char is alpha
        if (isalpha(plainText[i]))
        {
            keypos++;
        }

        //Output the current encrypted char to the screen
        printf("%c", encrypt(plainText[i], keyword[keyIndex]));

    }

    printf("\n");

}

char encrypt(char source, char key)
{
    int lowerCaseOffset = 'a';
    int upperCaseOffset = 'A';

    int offsetSource;
    int offsetKey;// = key - lowerCaseOffset;

    //Get the base 26 of the key
    if (islower(key))
    {
        offsetKey = key - lowerCaseOffset;
    }
    else if (isupper(key))
    {
        offsetKey = key - upperCaseOffset;
    }
    else
    {
        printf("Special characters are not supported in the key");
        return 1;
    }

    if (islower(source))
    {
        offsetSource = source - lowerCaseOffset;

        return ((offsetSource + offsetKey) % NUM_CHARS) + lowerCaseOffset;

    }
    else if (isupper(source))
    {
        offsetSource = source - upperCaseOffset;

        return ((offsetSource + offsetKey) % NUM_CHARS) + upperCaseOffset;
    }
    else
    {
        return source;
    }
}
