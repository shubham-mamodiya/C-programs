
/*
 * sizes_and_ranges_cheatsheet.c
 *
 * Typical sizes AND value ranges of C data types
 * for 64-bit Linux (LP64 model: long = 8 bytes).
 *
 * NOTE: Always use sizeof() for portable code.
 */

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

  /* ---- INTEGER TYPES ---- */

  char c;           // char: 1 byte, range:   -128 to 127
  unsigned char uc; // unsigned char: 1 byte, 0 to 255

  short s;           // short: 2 bytes,        -32,768 to 32,767
  unsigned short us; // unsigned short: 2 bytes, 0 to 65,535

  int i;           // int: 4 bytes,          -2,147,483,648 to 2,147,483,647
  unsigned int ui; // unsigned int: 4 bytes, 0 to 4,294,967,295

  long l;           // long: 8 bytes,         approx -9.22e18 to +9.22e18
  unsigned long ul; // unsigned long: 8 bytes, 0 to ~1.84e19

  long long ll;           // long long: 8 bytes,    approx -9.22e18 to +9.22e18
  unsigned long long ull; // unsigned long long: 8 bytes, 0 to ~1.84e19

  /* ---- FLOATING TYPES ---- */

  float f;  // float: 4 bytes,  ~6 decimal digits,  ~1.17e-38 to ~3.4e38
  double d; // double: 8 bytes, ~15 decimal digits, ~2.2e-308 to ~1.8e308
  long double
      ld; // long double: 16 bytes (GCC), ~18+ digits, ~3.4e-4932 to ~1.1e4932

  /* ---- POINTER TYPES ---- */

  int *pi;  // int* : 8 bytes, range depends on address space
  char *pc; // char*: 8 bytes
  void *pv; // void*: 8 bytes

  /* ---- SPECIAL TYPES ---- */

  bool b; // bool (_Bool): 1 byte, values: 0 or 1

  size_t st;    // size_t: 8 bytes, unsigned 64-bit → 0 to ~1.84e19
  ptrdiff_t pt; // ptrdiff_t: 8 bytes, signed 64-bit → ~ -9.22e18 to +9.22e18
  wchar_t wc;   // wchar_t: 4 bytes on Linux, unsigned → 0 to 4,294,967,295

  enum Example { A, B }; // enum: 4 bytes, same range as int

  /* ---- ARRAYS ---- */

  int arr[10]; // int[10]: 40 bytes (10 × 4 bytes), each element int range

  /* Print actual sizeof() at runtime. */
  printf("char: %zu bytes, range %d to %d\n", sizeof(c), CHAR_MIN, CHAR_MAX);
  printf("unsigned char: %zu bytes, 0 to %u\n", sizeof(uc), UCHAR_MAX);
  printf("short: %zu bytes, %d to %d\n", sizeof(s), SHRT_MIN, SHRT_MAX);
  printf("unsigned short: %zu bytes, 0 to %u\n", sizeof(us), USHRT_MAX);
  printf("int: %zu bytes, %d to %d\n", sizeof(i), INT_MIN, INT_MAX);
  printf("unsigned int: %zu bytes, 0 to %u\n", sizeof(ui), UINT_MAX);
  printf("long: %zu bytes, %ld to %ld\n", sizeof(l), LONG_MIN, LONG_MAX);
  printf("unsigned long: %zu bytes, 0 to %lu\n", sizeof(ul), ULONG_MAX);
  printf("long long: %zu bytes, %lld to %lld\n", sizeof(ll), LLONG_MIN,
         LLONG_MAX);
  printf("unsigned long long: %zu bytes, 0 to %llu\n", sizeof(ull), ULLONG_MAX);

  printf("float: %zu bytes, %g to %g\n", sizeof(f), FLT_MIN, FLT_MAX);
  printf("double: %zu bytes, %g to %g\n", sizeof(d), DBL_MIN, DBL_MAX);
  printf("long double: %zu bytes, %Lg to %Lg\n", sizeof(ld), LDBL_MIN,
         LDBL_MAX);

  printf("void*: %zu bytes\n", sizeof(pv));
  printf("bool: %zu bytes (0 or 1)\n", sizeof(b));
  printf("size_t: %zu bytes\n", sizeof(st));
  printf("wchar_t: %zu bytes\n", sizeof(wc));
  printf("enum: %zu bytes\n", sizeof(enum Example));
  printf("arr[10]: %zu bytes\n", sizeof(arr));

  return 0;
}
