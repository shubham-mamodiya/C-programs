#include <stdio.h>

void print_mario(int length);
void print_whitespaces(int length, int num_of_hash_sym);
void print_hash_sym(int num_of_hash_sym);

int main(void) {
  int length = 0;
  printf("\nLength: ");
  scanf("%d", &length);
  print_mario(length);

  return 0;
}

void print_mario(int length) {
  for (int i = 1; i <= length; i++) {
    print_whitespaces(length, i);
    print_hash_sym(i);
    printf("  ");
    print_hash_sym(i);
    print_whitespaces(length, i);
    printf("\n");
  }
}

void print_whitespaces(int length, int num_of_hash_sym) {
  int white_spaces = length - num_of_hash_sym;
  for (int i = 0; i < white_spaces; i++) {
    printf(" ");
  }
}

void print_hash_sym(int num_of_hash_sym) {
  for (int i = 0; i < num_of_hash_sym; i++) {
    printf("#");
  }
}
