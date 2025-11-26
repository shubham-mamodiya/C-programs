/*
    C INTEGER TYPES CHEAT SHEET
    Covers:
      - Standard integer types
      - Fixed-width integers <stdint.h>
      - Least / Fast types
      - Pointer-sized & max types
      - Format specifiers
      - Typical x86_64 sizes
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  printf("\n=== STANDARD INTEGER TYPES ===\n");
  printf("char:                 %zu bytes\n", sizeof(char));
  printf("signed char:          %zu bytes\n", sizeof(signed char));
  printf("unsigned char:        %zu bytes\n", sizeof(unsigned char));
  printf("short:                %zu bytes\n", sizeof(short));
  printf("unsigned short:       %zu bytes\n", sizeof(unsigned short));
  printf("int:                  %zu bytes\n", sizeof(int));
  printf("unsigned int:         %zu bytes\n", sizeof(unsigned int));
  printf("long:                 %zu bytes\n", sizeof(long));
  printf("unsigned long:        %zu bytes\n", sizeof(unsigned long));
  printf("long long:            %zu bytes\n", sizeof(long long));
  printf("unsigned long long:   %zu bytes\n", sizeof(unsigned long long));

  printf("\n=== EXACT-WIDTH TYPES <stdint.h> ===\n");
  printf("int8_t:   %zu bytes\n", sizeof(int8_t));
  printf("uint8_t:  %zu bytes\n", sizeof(uint8_t));
  printf("int16_t:  %zu bytes\n", sizeof(int16_t));
  printf("uint16_t: %zu bytes\n", sizeof(uint16_t));
  printf("int32_t:  %zu bytes\n", sizeof(int32_t));
  printf("uint32_t: %zu bytes\n", sizeof(uint32_t));
  printf("int64_t:  %zu bytes\n", sizeof(int64_t));
  printf("uint64_t: %zu bytes\n", sizeof(uint64_t));

  printf("\n=== LEAST TYPES (>= N bits) ===\n");
  printf("int_least8_t:   %zu bytes\n", sizeof(int_least8_t));
  printf("int_least16_t:  %zu bytes\n", sizeof(int_least16_t));
  printf("int_least32_t:  %zu bytes\n", sizeof(int_least32_t));
  printf("int_least64_t:  %zu bytes\n", sizeof(int_least64_t));

  printf("\n=== FAST TYPES (fastest >= N bits) ===\n");
  printf("int_fast8_t:    %zu bytes\n", sizeof(int_fast8_t));
  printf("int_fast16_t:   %zu bytes\n", sizeof(int_fast16_t));
  printf("int_fast32_t:   %zu bytes\n", sizeof(int_fast32_t));
  printf("int_fast64_t:   %zu bytes\n", sizeof(int_fast64_t));

  printf("\n=== SPECIAL INTEGER TYPES ===\n");
  printf("size_t:         %zu bytes\n", sizeof(size_t));
  printf(
      "ssize_t:        (platform-dependent)\n"); // not standard C, POSIX only
  printf("ptrdiff_t:      %zu bytes\n", sizeof(ptrdiff_t));
  printf("intptr_t:       %zu bytes\n", sizeof(intptr_t));
  printf("uintptr_t:      %zu bytes\n", sizeof(uintptr_t));
  printf("intmax_t:       %zu bytes\n", sizeof(intmax_t));
  printf("uintmax_t:      %zu bytes\n", sizeof(uintmax_t));

  printf("\n=== PRINTF FORMAT SPECIFIERS ===\n");
  printf("int: %%d, unsigned int: %%u\n");
  printf("long: %%ld, unsigned long: %%lu\n");
  printf("long long: %%lld, unsigned long long: %%llu\n");
  printf("int8_t:   %" PRId8 " (example)\n", (int8_t)42);
  printf("uint8_t:  %" PRIu8 " (example)\n", (uint8_t)42);
  printf("int16_t:  %" PRId16 " (example)\n", (int16_t)42);
  printf("int32_t:  %" PRId32 " (example)\n", (int32_t)42);
  printf("int64_t:  %" PRId64 " (example)\n", (int64_t)42);
  printf("intptr_t: %" PRIdPTR " (example)\n", (intptr_t)42);
  printf("intmax_t: %" PRIdMAX " (example)\n", (intmax_t)42);

  printf("\n=== NOTES ===\n");
  printf("- Exact-width types (int32_t, uint64_t) have the same size "
         "everywhere.\n");
  printf("- Least types guarantee AT LEAST the required bits.\n");
  printf("- Fast types are chosen by the compiler for best speed.\n");
  printf("- intptr_t is the integer that can hold a pointer.\n");
  printf("- intmax_t is the biggest supported integer.\n");

  return 0;
}
