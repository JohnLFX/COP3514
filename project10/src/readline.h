/**
 * COP3514 Project 10
 * This program is a modified version from project 9.
 * In this program, the LinkedList maintains order
 * and includes an option to delete entries from it.
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