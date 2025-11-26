#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OPEN 0x10
#define LEFT 0x8
#define UP 0x4
#define DOWN 0x2
#define RIGHT 0x1

struct cell {
  uint8_t meta_data; // 00011111, 000 just extra and unused bits.
  // 000<This><Left><Up><Down><Right> cells are open.
  // Any field will be 0 if that cell is not open or does not exists.
  //
  // bit4: OPEN
  // bit3: LEFT
  // bit2: UP
  // bit1: DOWN
  // bit0: RIGHT
};

void initialize(int size, struct cell arr[][size]);
void print_Grid(int size, struct cell arr[][size]);

int main(int argc, char *argv[]) {
  int n = 0;
  printf("Size of the Experiment: ");
  scanf("%d", &n);
  struct cell grid[n][n];

  print_Grid(n, grid);

  return 0;
}

// Initialize every Cell to not open
void initialize(int size, struct cell arr[][size]) {
  if (size < 0) {
    exit(2);
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr[i][j].meta_data = 0x0;
    }
  }
}

void print_Grid(int size, struct cell arr[][size]) {
  if (size < 0) {
    exit(3);
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[i][j].meta_data & OPEN) {
        printf(" "); // open cell
      } else {
        printf("#"); // closed
      }
    }
    printf("\n");
  }
}
