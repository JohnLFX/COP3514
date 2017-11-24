/**
 * COP3514 Project 2
 * This program determines whether a username (input of characters) is valid.
 * A valid username must be between 5-10 characters and can only contain
 * alphabetic letters (lower or upper case), digits, or underscores.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {

    char character;
    int length = 0;

    //Prompt the user for an input.
    printf("Enter the username:\n");

    // Read a character from the input.
    // If it is a new line character, terminate the loop.
    // Otherwise, continue reading new characters.
    while ((character = getchar()) && character != '\n') {

        //Increase the character count by 1.
        length++;

        //Determine if the input char is a letter, digit, or underscore.
        if (!isalpha(character) && !isdigit(character) && character != '_') {

            // The char is not a letter, digit, or underscore.
            // Print an invalid input message and terminate the program.
            printf("Input is invalid.\n");
            return 0;

        }

    }

    // There are no invalid characters detected since the program is still running.
    // Check to see if the character count (length) is within the requirements.
    if (length < 5 || length > 10) {

        printf("Input is invalid. Length must be between 5-10 characters.\n");
        return 0; //Terminate the program.

    }

    //All checks have passed. Print a message of the username being a successful input.

    printf("Valid input.\n");

    return 0;
}