/**
 * COP3514 Project 5
 * This program encodes a sentence by switching every alphabetical letter
 * (lower case or upper case) with alphabetical position i with the letter
 * with alphabetical position 25 – i. For example, letter a is at position 0
 * and after encoding it becomes letter z (position 25). Letter m is at position 12,
 * it becomes letter n (25 – 12 = 13) after encoding.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <ctype.h>

#define ASCII_UPPER_A 65
#define ASCII_LOWER_A 97
#define STR_LENGTH 1000

void convert(char *s1, char *s2);

int read_line(char *str, int n);

int main(void) {

    char input[STR_LENGTH + 1];

    printf("Enter the message:\n");

    read_line(input, STR_LENGTH);

    char output[STR_LENGTH + 1];

    convert(input, output);

    printf("Output: %s\n", output);

    return 0;
}

/**
 * The function expects s1 to point to a string containing the input
 * as a string and stores the output to the string pointed by s2.
 * @param s1 Input string
 * @param s2 Output string to store the result in
 */
void convert(char *s1, char *s2) {

    char *p;

    for (p = s1; p < s1 + STR_LENGTH; p++) {

        //If we have reached the end of the string, break the loop
        if (*p == '\0')
            break;

        //Only convert alphabetic characters
        if (isalpha(*p)) {

            //If the char is upper case, use the constant ASCII_UPPER_A.
            // Else, use the ASCII_LOWER_A constant.
            if (isupper(*p))
                *s2++ = ((25 - (((int) *p) - ASCII_UPPER_A)) + ASCII_UPPER_A);
            else
                *s2++ = ((25 - (((int) *p) - ASCII_LOWER_A)) + ASCII_LOWER_A);

        } else {
            *s2++ = *p;
        }

    }

    *s2 = '\0';//Append null terminator

}

/**
 * Reads a line from the console using getchar()
 * @param str The string to store the input in
 * @param n The length of the string
 * @return The number of characters read
 */
int read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++ = ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}