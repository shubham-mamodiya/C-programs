
// bit_cheatsheet.c
// A single-file, compile-ready C cheat sheet for bit manipulation.

#include <stdint.h>
#include <stdio.h>

// -----------------------------
// Basic Operations
// -----------------------------
void basic_ops(void) {
  unsigned int a = 5; /* 0x05 */
  unsigned int b = 3; /* 0x03 */

  printf("AND: %u\n", a & b);
  printf("OR: %u\n", a | b);
  printf("XOR: %u\n", a ^ b);
  printf("NOT (a): %u\n", (unsigned)~a);
  printf("Shift left 1: %u\n", a << 1);
  printf("Shift right 1: %u\n", a >> 1);
}

// -----------------------------
// Bit Operations
// -----------------------------
void bit_ops(void) {
  unsigned int num = 0xA; /* 1010b */
  unsigned int k = 1;

  num |= (1U << k);  /* set bit k */
  num &= ~(1U << k); /* clear bit k */
  num ^= (1U << k);  /* toggle bit k */

  unsigned int check = num & (1U << k);
  unsigned int bit = (num >> k) & 1U;

  printf("Check bit: %d\n", check ? 1 : 0);
  printf("Bit value: %u\n", bit);
}

// -----------------------------
// Bit Field (extract bits)
// -----------------------------
void bit_field(void) {
  unsigned int num = 0xD8; /* 11011000b */
  /* extract bits 3..5 (3 bits) */
  unsigned int field = (num >> 3) & 0x7U; /* 0x7 = 111b */
  printf("Extracted field (bits 3..5): %u\n", field);
}

// -----------------------------
// Bit Masks
// -----------------------------
#define FLAG_READ (1U << 0)
#define FLAG_WRITE (1U << 1)
#define FLAG_EXEC (1U << 2)

void bit_masks(void) {
  unsigned int perms = 0U;
  perms |= FLAG_READ | FLAG_EXEC; /* set read & exec */
  perms &= ~FLAG_EXEC;            /* clear exec */

  if (perms & FLAG_READ)
    printf("Read flag is ON\n");
  else
    printf("Read flag is OFF\n");
}

// -----------------------------
// Useful Tricks
// -----------------------------
void tricks(void) {
  int x = 18; /* even */

  printf("Even? %s\n", (x & 1) ? "no" : "yes");
  printf("Power of 2? %s\n", (x > 0 && (x & (x - 1)) == 0) ? "yes" : "no");

  int a = 5, b = 9;
  a ^= b;
  b ^= a;
  a ^= b; /* swap without temp */
  printf("Swapped: a=%d b=%d\n", a, b);

  int y = 44; /* 101100b */
  printf("Turn off lowest set bit: %d\n", y & (y - 1));
  printf("Isolate lowest set bit: %d\n", y & -y);
}

// -----------------------------
// Count Bits (Brian Kernighan)
// -----------------------------
int count_bits(unsigned int x) {
  int count = 0;
  while (x) {
    x &= (x - 1U);
    count++;
  }
  return count;
}

// -----------------------------
// Reverse Bits (32-bit)
// -----------------------------
uint32_t reverse_bits(uint32_t v) {
  v = ((v >> 1) & 0x55555555U) | ((v & 0x55555555U) << 1);
  v = ((v >> 2) & 0x33333333U) | ((v & 0x33333333U) << 2);
  v = ((v >> 4) & 0x0F0F0F0FU) | ((v & 0x0F0F0F0FU) << 4);
  v = ((v >> 8) & 0x00FF00FFU) | ((v & 0x00FF00FFU) << 8);
  v = (v >> 16) | (v << 16);
  return v;
}

// -----------------------------
// Packing / Unpacking (RGB)
// -----------------------------
void rgb_pack(void) {
  unsigned int r = 120U, g = 200U, b = 90U;

  unsigned int pack = 0U;
  pack |= (r & 0xFFU) << 16;
  pack |= (g & 0xFFU) << 8;
  pack |= (b & 0xFFU);

  unsigned int rr = (pack >> 16) & 0xFFU;
  unsigned int gg = (pack >> 8) & 0xFFU;
  unsigned int bb = pack & 0xFFU;

  printf("Unpacked RGB: %u %u %u\n", rr, gg, bb);
}

// -----------------------------
// Simple Bitset (32 flags)
// -----------------------------
static unsigned int bitset = 0U;
void set_bit(int i) { bitset |= (1U << i); }
void clear_bit(int i) { bitset &= ~(1U << i); }
int get_bit(int i) { return (int)((bitset >> i) & 1U); }

void bitset_demo(void) {
  set_bit(3);
  printf("Bit 3: %d\n", get_bit(3));
  clear_bit(3);
  printf("Bit 3 after clear: %d\n", get_bit(3));
}

// -----------------------------
// Main - demos all snippets
// -----------------------------
int main(void) {
  puts("-- basic_ops --");
  basic_ops();
  puts("\n-- bit_ops --");
  bit_ops();
  puts("\n-- bit_field --");
  bit_field();
  puts("\n-- bit_masks --");
  bit_masks();
  puts("\n-- tricks --");
  tricks();
  printf("\nCount bits in 29: %d\n", count_bits(29U));
  printf("Reverse bits of 13: %u\n", reverse_bits(13U));
  puts("\n-- rgb_pack --");
  rgb_pack();
  puts("\n-- bitset_demo --");
  bitset_demo();
  return 0;
}
