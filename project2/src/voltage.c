/**
 * COP3514 Project 2
 * This program calculates the voltage across a capacitor at certain times
 * when given the capacitance, resistance, and source voltage in a circuit.
 *
 * @author John Cameron (jcameron2)
 */
#include <stdio.h>
#include <math.h>

/* Define the given constants. */
#define CAPACITANCE 50e-6
#define RESISTANCE 3000
#define VOLTAGE 10.0

/* Define constants that are used in the equation. */
#define TIME_CONSTANT (CAPACITANCE * RESISTANCE)

/* Define the amount of seconds to increase the time by in the for loop. */
#define TIME_INCREMENT (1.0 / 15.0)

int main(void) {

    float seconds;

    printf("time (sec)\tvoltage\n");

    //Increase the seconds variable from 0 to at least 1 by the TIME_INCREMENT constant in each loop.
    for (seconds = 0.0; seconds <= 1; seconds += TIME_INCREMENT) {

        //Calculate the exponent portion of the exponentiation in the equation.
        float exponent = ((-1 * seconds) / TIME_CONSTANT);

        //Determine the final voltage by calculating the remaining portion of the equation.
        float voltage = (VOLTAGE * (1.0 - exp(exponent)));

        //Print the result with a format of having only two numbers after the decimal point.
        printf("  %.2f\t\t    %.2f\n", seconds, voltage);

    }

    return 0;
}