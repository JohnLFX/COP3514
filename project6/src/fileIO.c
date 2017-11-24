/**
 * COP3514 Project 6
 * This program prompts the user to enter the name of a file.
 * Then the program searches for anagrams in the file and outputs the
 * results in a new file with the same name but with an added .ang extension.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Assume the file name is no more than 100 characters.
#define FILE_NAME_SIZE 100

//Assume the length of each line in the input file is no more than 100 characters.
#define LINE_SIZE 100

//Assume the input file contains no more than 1000 words (lines in this case, since each word is on a new line)
#define MAX_LINES 1000

int are_anagram(char *word1, char *word2);

int read_line(char *str, int n);

int main(void) {

    printf("Enter the file name: ");

    char inputFileName[FILE_NAME_SIZE];

    read_line(inputFileName, FILE_NAME_SIZE);

    FILE *readFile = fopen(inputFileName, "r");

    if (readFile == NULL) {//Null pointer
        printf("File %s was not opened successfully.\n", inputFileName);
        return 1;
    }

    char words[MAX_LINES][LINE_SIZE];

    int size = 0;

    // fgets reads the newline character and adds null terminator
    // Allow LINE_SIZE (100) characters in the line to be read, and +1 for the null terminator
    while (fgets(words[size++], LINE_SIZE + 1, readFile) != NULL)
        if (size >= MAX_LINES)//Bounds checking for the array
            break;

    fclose(readFile);

    //Increase bounds to allow for appended extension
    char outputFileName[FILE_NAME_SIZE + 4];

    // The output file name should be the same name as the
    // input file but with an added extension of .ang
    strcpy(outputFileName, inputFileName);
    strcat(outputFileName, ".ang");

    FILE *writeFile = fopen(outputFileName, "w");
    if (writeFile == NULL) {
        printf("File %s was not opened successfully.\n", outputFileName);
        return 1;
    }

    int anagramsFound[size];

    int i = 0;

    //Initialize all values to 0
    for (i = 0; i < size; i++)
        anagramsFound[i] = 0;

    //Keep track of the anagrams found
    int anagramsCount = 0;

    for (i = 0; i < size; i++) {

        int j;

        for (j = 0; j < size; j++) {

            // If the word was already used in an anagram,
            // skip it to prevent duplicate entries
            if (anagramsFound[j])
                continue;

            // Make sure that the two words are different first before checking if they are an anagram
            if (strcmp(words[i], words[j]) != 0 && are_anagram(words[i], words[j])) {

                //Mark index i as an anagram
                anagramsFound[i] = 1;

                //The words stored in the array contain new line characters
                fprintf(writeFile, "%d\t%s\t%s", ++anagramsCount, words[i], words[j]);

            }

        }

    }

    fclose(writeFile);

    printf("anagrams are written to file: %s\n", outputFileName);

    return 0;
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
        if (i++ < n)
            *str++ = ch;
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

/**
 * Checks to see if two strings are anagrams
 * @param word1 First string
 * @param word2 Second string
 * @return 1 if anagrams, 0 otherwise
 */
int are_anagram(char *word1, char *word2) {
    int letter_counts[26] = {0};
    char *p;
    char *q;
    int i, count = 0;
    char ch;
    for (p = word1; *p != '\0'; p++)
        if (isalpha(*p)) {
            ch = tolower(*p);
            letter_counts[ch - 'a']++;
        }

    for (q = word2; *q != '\0'; q++)
        if (isalpha(*q)) {
            ch = tolower(*q);
            letter_counts[ch - 'a']--;
        }

    for (i = 0; i < 26; i++) {
        if (letter_counts[i] == 0)
            count++;
    }

    return count == 26;
}
