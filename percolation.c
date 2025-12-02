#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OPEN 0x10
#define LEFT 0x8
#define UP 0x4
#define DOWN 0x2
#define RIGHT 0x1

// TODO: Implement dinamic arrays

struct Root {
  int row;
  int cloumn;
};

struct Cell {
  uint8_t meta_data; // 00011111, 000 just extra and unused bits.
  // 000<This><Left><Up><Down><Right> cells are open.
  // Any field will be 0 if that cell is not open or does not exists.
  //
  // bit4: OPEN
  // bit3: LEFT
  // bit2: UP
  // bit1: DOWN
  // bit0: RIGHT
  struct Root root;
  int size; // Number of connected Cells
  // TODO: Implement a linked-list that keeps track of size for each
  // Tree(connected Cells or Cell that is connected to more then itself) to
  // reduce memory usage even further.
};

/* Means of Connection or connectivity
 * Every Cell is connected to itself.
 *  when Cell is open and neighbouring Cell (can be identified from fields) open
 * means connection can be established
 *
 */

void initialize(unsigned long size, struct Cell arr[][size]);
void print_Grid(unsigned long size,
                struct Cell arr[][size]); // For small training set

int main(int argc, char *argv[]) {
  srand(time(NULL));

  unsigned long size = 0;
  printf(
      "Size of the Experiment(0 to ~1.84e19 if computation is avialable): "); // NOTE: no more then 20000 for my 11 GB free memory
  scanf("%ld", &size);
  if (size <= 0) {
    printf("\n ---Invalid size---\n");
    return 1;
  }

  struct Cell(*grid)[size] =
      malloc(size * sizeof *grid); // 2D array of Cell structure
  if (!grid) {
    printf("Grid is not available, issue with malloc.");
    return 5;
  }
  initialize(size, grid);
  // print_Grid(size, grid);

  free(grid);
  return 0;
}

// Make each Cell connected to itself and Closed or blocked
void initialize(unsigned long size, struct Cell arr[][size]) {
  if (size <= 0) {
    exit(3);
    free(arr);
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr[i][j].meta_data = 0x0;
      arr[i][j].root.row = i;
      arr[i][j].root.cloumn = j;
      arr[i][j].size = 1; // Each Cell is connected to itself
    }
  }
}

void print_Grid(unsigned long size, struct Cell arr[][size]) {
  if (size <= 0) {
    free(arr);
    exit(4);
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

void state_Grid(unsigned long size, struct Cell arr[][size]) {
  if (size <= 0) {
    free(arr);
    exit(6);
  }
  for (unsigned int row = 0; row < size; row++) {
    for (unsigned int column = 0; column < size; column++) {
    }
  }
}

void get_Neighbours_State(unsigned long row, unsigned long column,
                          unsigned long size, struct Cell arr[][size]) {
  if (row >= size || column >= size) {
    free(arr);
    exit(7);
  }

  // Because index 0, 0 can't have Cell upside and left
  if (row == column == 0) {
  }
}
