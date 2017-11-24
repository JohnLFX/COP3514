/**
 * COP3514 Project 3
 * This program adds two numbers together by using
 * function recursion without the + operator
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>

int add(int n, int m);

int main(void) {

    //Prompt user for two integers
    printf("Enter two numbers:\n");

    //Read console input
    int number1, number2;
    scanf("%d %d", &number1, &number2);

    int result = add(number1, number2);

    printf("The addition is %d.\n", result);

    return 0;
}

int add(int n, int m) {

    if (m > 0) {

        /*
         * If the second number is greater than the first,
         * Update the variables by adding 1 to n and subtracting 1 from m.
         * Then, call the function again to repeat the process if needed.
         */
        return add(++n, --m);

    } else if (m == 0) {

        //m is equal to 0. No more calculations need to be made.
        return n;

    } else {

        /*
         * In this case, m is a negative number. Do the same as the add function above,
         * but subtract 1 from n and add 1 to m.
         */
        return add(--n, ++m);

    }
}