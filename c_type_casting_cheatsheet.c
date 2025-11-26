/*
 * Type Casting Cheat Sheet in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    /* Implicit casting */
    int a = 5;
    float b = a;

    /* Explicit casting */
    float x = 5.7f;
    int y = (int)x;

    /* Avoid integer division */
    int n1 = 7, n2 = 2;
    float r = (float)n1 / n2;

    /* Dangerous narrowing */
    int big = 300;
    char small = (char)big;

    /* Pointer casting */
    void *ptr;
    int *iptr = (int *)ptr;

    /* Signed/unsigned wrap example */
    int neg = -1;
    unsigned int wrap = (unsigned)neg;

    printf("Implicit: %f\n", b);
    printf("Explicit int->float: %d\n", y);
    printf("Float division: %f\n", r);
    printf("Narrow char from 300: %d\n", small);
    printf("Unsigned wrap from -1: %u\n", wrap);

    return 0;
}
