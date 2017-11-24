/**
 * COP3514 Project 10 Extra Credit
 * This program is a modified version from project 10.
 * In this program, the LinkedList maintains order
 * by considering many other car structure variables.
 *
 * @author John Cameron (jcameron2)
 */
#include <ctype.h>
#include <stdio.h>
#include "readline.h"

/**
 * Skips leading white-space characters, then reads
 * the remainder of the input line and stores it in str.
 * Truncates the line if its length exceeds n.
 * Returns the number of characters stored.
 * @param str The string variable to store the input in
 * @param n The buffer size of the string variable
 * @return The amount of characters stored
 */
int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()));
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}