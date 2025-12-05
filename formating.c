
#include <stdio.h>

int main() {
  /* ===== Integers assigned literal max values ===== */
  int i = 2147483647;                        // max int
  unsigned int ui = 4294967295U;             // max unsigned int
  short s = 32767;                           // max short
  unsigned short us = 65535U;                // max unsigned short
  long l = 9223372036854775807L;             // max long (on 64-bit)
  unsigned long ul = 18446744073709551615UL; // max unsigned long
  long long ll = 9223372036854775807LL;      // max long long
  unsigned long long ull = 18446744073709551615ULL;

  /* ===== Chars ===== */
  char ch = 127; // max signed char
  unsigned char uch = 255;

  /* ===== Floating types (approx literal) ===== */
  float f = 3.402823466e+38F;
  double d = 1.7976931348623157e+308;
  long double ld = 1.189731495357231765e+4932L; // platform dependent

  size_t size = 18446744073709551615ULL; // on 64-bit usually equal to ULL max
  void *ptr = &i;
  printf("\n========== INTEGER ==========\n");

  printf("int               %%d  = %d\n", i);
  printf("unsigned int      %%u  = %u\n", ui);
  printf("short             %%hd = %hd\n", s);
  printf("unsigned short    %%hu = %hu\n", us);
  printf("long              %%ld = %ld\n", l);
  printf("unsigned long     %%lu = %lu\n", ul);
  printf("long long         %%lld = %lld\n", ll);
  printf("unsigned long long%%llu = %llu\n", ull);

  printf("\n========== CHAR / STRING ==========\n");
  printf("char              %%c  = %c\n", ch);
  printf("unsigned char     %%hhu = %hhu\n", uch);
  printf("string            %%s  = %s\n", str);

  printf("\n========== FLOAT / DOUBLE ==========\n");
  printf("float             %%f  = %f\n", f);
  printf("double            %%lf = %lf\n", d);
  printf("long double       %%Lf = %Lf\n", ld);

  printf("\n========== SPECIAL FORMATS ==========\n");
  printf("hex (lower)       %%x  = %x\n", i);
  printf("hex (upper)       %%X  = %X\n", i);
  printf("octal             %%o  = %o\n", i);
  printf("pointer           %%p  = %p\n", ptr);

  printf("\n========== SIZE, WIDTH, SIGN ==========\n");
  printf("size_t            %%zu = %zu\n", size);
  printf("width (5 spaces)  %%5d = %5d\n", i);
  printf("zero padded       %%05d = %05d\n", i);
  printf("left aligned      %%-5d = %-5d\n", i);

  printf("\n========== PERCENT SIGN ==========\n");
  printf("print %% with %%%% : %%\n");

  return 0;
}

/*
===============================
 C FORMAT SPECIFIER CHEAT SHEET
===============================

Integers:
    int                     %d / %i
    unsigned int            %u
    short                   %hd
    unsigned short          %hu
    long                    %ld
    unsigned long           %lu
    long long               %lld
    unsigned long long      %llu

Characters / Strings:
    char                    %c
    unsigned char           %hhu
    string (char*)          %s

Floating:
    float                   %f
    double                  %lf / %f
    long double             %Lf

Other:
    hex (lower / upper)     %x / %X
    octal                   %o
    pointer                 %p
    size_t                  %zu
    percent sign            %%

Width:
    %5d      -> right aligned in 5 spaces
    %05d     -> zero padded
    %-5d     -> left aligned



========================================
  WHAT THESE FORMAT LETTERS *MEAN*
========================================

    d  -> decimal (signed)
    i  -> integer (same as d)
    u  -> unsigned decimal (no negative numbers)
    h  -> short modifier (half size)
    l  -> long modifier (longer size)
    ll -> long long modifier (even bigger)
    f  -> floating point
    L  -> long double modifier
    x/X-> hexadecimal (base 16)
    o  -> octal (base 8)
    p  -> pointer
    z  -> size_t modifier (compiler-dependent sized unsigned int)

========================================
 WHY WE USE UNSIGNED SPECIFIERS LIKE %u
========================================
* %u tells printf to interpret the bits as a **positive-only integer**.
* If you print a negative value using %u, it will show the raw bit pattern
  reinterpreted as a large positive number (wrap-around).
* Use unsigned types when:
      - You never need negative numbers
      - You want to store bigger positive values in the same memory size
      - You're dealing with bit operations, memory sizes, array lengths, etc.
*/
