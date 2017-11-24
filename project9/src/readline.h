/**
 * COP3514 Project 9
 * This program is exactly like the one in project 8
 * but split into multiple files and linked together as necessary.
 * This file contains the header for the readline function.
 *
 * @author John Cameron (jcameron2)
 */
#ifndef READLINE_H
#define READLINE_H

/**
 * Skips leading white-space characters, then reads
 * the remainder of the input line and stores it in str.
 * Truncates the line if its length exceeds n.
 * Returns the number of characters stored.
 * @param str The string variable to store the input in
 * @param n The buffer size of the string variable
 * @return The amount of characters stored
 */
int read_line(char str[], int n);

#endif //READLINE_H