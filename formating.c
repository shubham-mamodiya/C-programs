
#include <stdio.h>

int main() {
  int i = 10;
  unsigned int ui = 20;
  short s = -5;
  unsigned short us = 500;
  long l = 100000L;
  unsigned long ul = 4000000000UL;
  long long ll = -900000000000LL;
  unsigned long long ull = 18000000000000000000ULL;

  char ch = 'A';
  unsigned char uch = 250;
  char str[] = "Hello";

  float f = 3.14f;
  double d = 9.876543;
  long double ld = 15.123456789L;

  size_t size = 42;
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
