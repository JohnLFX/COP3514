#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 30
struct car {
    char make[LEN + 1];
    char model[LEN + 1];
    char color[LEN + 1];
    int year;
    int city_mpg;
    int highway_mpg;
    int quantity;
    struct car *next;
};


struct car *append_to_list(struct car *list);

void find_car(struct car *list);

void printList(struct car *list);

void clearList(struct car *list);

int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void) {
    char code;

    struct car *car_list = NULL;
    printf("Operation Code: a for appending to the list, f for finding a car"
                   ", p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'a':
                car_list = append_to_list(car_list);
                break;
            case 'f':
                find_car(car_list);
                break;
            case 'p':
                printList(car_list);
                break;
            case 'q':
                clearList(car_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct car *append_to_list(struct car *list) {

    //add your code here and remove the return NULL; statement
    return NULL;
}

void find_car(struct car *list) {
    //add your code here

}

void printList(struct car *list) {

    //add your code here

}

void clearList(struct car *list) {
    //add your code here

}

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
