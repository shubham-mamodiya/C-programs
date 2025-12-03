#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define FLAG_OPEN 0x10
#define FLAG_LEFT 0x8
#define FLAG_UP 0x4
#define FLAG_DOWN 0x2
#define FLAG_RIGHT 0x1

uint8_t open_bit_index = 4U; // 4th bit
uint8_t left_bit_index = 3U;
uint8_t up_bit_index = 2U;
uint8_t down_bit_index = 1U;
uint8_t Right_bit_index = 0U;

#define BITVALUE(X, N) (((X) >> (N)) & 1U)
#define SETBIT(X, N) ((X) |= (1U << N))

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
      if (arr[i][j].meta_data & FLAG_OPEN) {
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
  if (size <= 0 || row >= size || column >= size || row < 0 || column < 0) {
    free(arr);
    exit(7);
  }

  // bit4: OPEN
  // bit3: LEFT
  // bit2: UP
  // bit1: DOWN
  // bit0: RIGHT

  // upper left corner at index [0][0]
  // Because index 0, 0 can't have Cell above and left
  if (row == 0 && column == 0) {
    if (column + 1 < size) {
      if (BITVALUE(arr[row][column + 1].meta_data,
                   4)) // 4th bit of Cell to the right
        SETBIT(arr[row][column].meta_data, 0);
    }
    if (row + 1 < size) {
      if (BITVALUE(arr[row + 1][column].meta_data,
                   4)) // 4th bit Cell to the below
        SETBIT(arr[row][column].meta_data, 1);
    }
  }
  // lower left corner at the index [size - 1][0]
  else if (row == size - 1 && column == 0) {

    if (column + 1 < size) {
      if (BITVALUE(arr[row][column + 1].meta_data,
                   4)) // 4th bit of Cell to the right
        SETBIT(arr[row][column].meta_data, 0);
    }

    if (row - 1 >= 0) {
      if (BITVALUE(arr[row - 1][column].meta_data,
                   4)) // 4th bit Cell to the above
        SETBIT(arr[row][column].meta_data, 2);
    }
  }
}
