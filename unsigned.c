
#include <stdio.h>

int main() {
    // ----- 1. Declaration -----
    unsigned char uc = 255;
    unsigned short us = 65535;
    unsigned int ui = 4000000000U;
    unsigned long ul = 5000000000UL;
    unsigned long long ull = 18446744073709551615ULL;

    // ----- 2. Printing -----
    printf("unsigned char: %hhu\n", uc);
    printf("unsigned short: %hu\n", us);
    printf("unsigned int: %u\n", ui);
    printf("unsigned long: %lu\n", ul);
    printf("unsigned long long: %llu\n", ull);

    // ----- 3. Wrap-around -----
    unsigned int a = 0;
    a--;  // causes wrap
    printf("\nWrap around (0 - 1) = %u\n", a);

    // ----- 4. Comparison issue -----
    int x = -5;
    unsigned int y = 10;

    if (x < y)
        printf("Signed comparison: x < y is TRUE\n");
    else
        printf("Signed comparison: x < y is FALSE (because x becomes large unsigned)\n");

    // ----- 5. Loop example -----
    printf("\nLoop with unsigned:\n");
    for (unsigned int i = 0; i < 5; i++)
        printf("i = %u\n", i);

    return 0;
}

/*
=====================
C Unsigned Cheat Sheet
=====================

unsigned types: only 0 and positive numbers

Common forms:
    unsigned char           0 to 255
    unsigned short          0 to 65535
    unsigned int            0 to ~4 billion
    unsigned long           0 to ~18 quintillion
    unsigned long long      0 to ~18 quintillion

Format specifiers:
    unsigned int            %u
    unsigned short          %hu
    unsigned long           %lu
    unsigned long long      %llu
    unsigned char           %hhu

Common uses:
    - counters
    - array indices
    - sizes
    - bitwise operations

Wrap-around:
    unsigned int a = 0;
    a--;  // becomes large positive number

Danger:
    Mixing signed & unsigned:
    int x = -1;
    unsigned int y = 10;
    x < y  // becomes FALSE
*/
