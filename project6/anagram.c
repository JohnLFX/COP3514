#include <stdio.h>
#include <ctype.h>

int are_anagram(char *word1, char *word2);

int read_line(char *str, int n);


int main() {

    char sen1[101];
    char sen2[101];
    printf("Please enter the first word\n");
    read_line(sen1, 30);
    printf("Please enter the second word\n");
    read_line(sen2, 30);


    if (are_anagram(sen1, sen2))
        printf("The words are anagrams.\n");
    else

        printf("The words are NOT anagrams.\n");


    return 0;
}


int read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {// printf("reading %c", ch);
        if (i < n)
            *str++ = ch;
    }
    *str = '\0';
    return i;
}


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

    if (count == 26)
        return 1;
    else
        return 0;

    return 0;
}
       
