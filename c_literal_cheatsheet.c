/*
 * C Literal Cheat Sheet
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /* Integer Literals */
    int dec = 123;          // decimal
    int hex = 0x7B;         // hexadecimal
    int oct = 0173;         // octal
    int bin = 0b1011;       // binary (C23 or GCC/Clang)

    /* Integer Suffixes */
    unsigned int ui = 100u;
    long l = 100l;
    long long ll = 100ll;
    unsigned long ul = 100ul;
    unsigned long long ull = 100ull;

    /* Floating-point Literals */
    float f = 12.34f;
    double d = 12.34;
    long double ld = 12.34L;
    double sci = 1.23e3;    // scientific notation

    /* Character Literals */
    char c1 = 'A';
    char c2 = '\n';         // escape
    char c3 = '\x41';       // hex for 'A'
    char c4 = '\101';       // octal for 'A'

    /* String Literals */
    char *s1 = "Hello";
    char *s2 = "Line1\nLine2";

    /* Boolean (C99+) */
    bool flag = true;
    bool ok = false;

    /* Print examples */
    printf("dec=%d hex=%d oct=%d bin=%d\n", dec, hex, oct, bin);
    printf("float=%f double=%f long double=%Lf sci=%f\n", f, d, ld, sci);
    printf("chars: %c %c %c %c\n", c1, 'A', c3, c4);
    printf("strings: %s | %s\n", s1, s2);
    printf("bools: %d %d\n", flag, ok);

    return 0;
}
