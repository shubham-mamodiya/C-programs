#include "percolation.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

uint8_t open_bit_index = 4U; // 4th bit
uint8_t left_bit_index = 3U;
uint8_t up_bit_index = 2U;
uint8_t down_bit_index = 1U;
uint8_t Right_bit_index = 0U;

/* Means of Connection or connectivity
 * Every Cell is connected to itself.
 *  when Cell is open and neighbouring Cell (can be identified from fields) open
 * means connection can be established
 *
 */

int main(int argc, char *argv[]) {

  srand(time(NULL));

  int grid_size = 0;
  printf("Size of the Experiment(0 to ~1.84e19 if computation is "
         "available): "); // NOTE: no more than 20000 for my 11 GB free memory
  scanf("%d", &grid_size);

  if (grid_size < 0) {
    printf("\n ---Invalid size---\n");
    return 1;
  }

  struct Cell(*grid)[grid_size] =
      grid_size ? malloc(grid_size * sizeof *grid) : NULL;
  // grid is a pointer to an array of <size> Cell structure (2D array)
  // no allocation if grid_size is 0

  if (!grid) {
    printf("Grid is not available, issue with malloc.");
    return 5;
  }

  int initialisation_status = initialize(grid_size, grid);
  if (initialisation_status) {
    free(grid);
    return initialisation_status;
  }
  // print_Grid(size, grid);

  free(grid);
  return 0;
}

/* Make each Cell connected to itself and Closed or blocked
 * Returns 3 if size <= 0, else 0*/
int initialize(int grid_size, struct Cell arr[][grid_size]) {
  if (grid_size < 0) {
    return 3;
  }
  for (int i = 0; i < grid_size; i++) {
    for (int j = 0; j < grid_size; j++) {
      arr[i][j].meta_data = 0x0;
      arr[i][j].root.row = i;
      arr[i][j].root.column = j;
      arr[i][j].size = 1; // Each Cell is connected to itself
    }
  }
  return 0;
}

/* Useful only based on terminal size
 * Returns 4 when size <= 0, else 0*/
int print_Grid(int grid_size, struct Cell arr[][grid_size]) {
  if (grid_size < 0) {
    return 4;
  }
  for (int i = 0; i < grid_size; i++) {
    for (int j = 0; j < grid_size; j++) {
      if (arr[i][j].meta_data & FLAG_OPEN) {
        printf(" "); // open cell
      } else {
        printf("#"); // closed
      }
    }
    printf("\n");
  }
  return 0;
}

/* changes Mata_data for each Cell in a 2d array
 * return 6 when size is < 0, else 0*/
int state_Grid(int grid_size, struct Cell arr[][grid_size]) {
  if (grid_size < 0) {
    return 6;
  }
  for (unsigned int row = 0; row < grid_size; row++) {
    for (unsigned int column = 0; column < grid_size; column++) {
      get_Neighbors_State(row, column, grid_size, arr);
    }
  }
  return 0;
}

/* It will change meta_data of a Cell in a 2d grid of Cells
 * return's 7 when size, row or column are Invalid, else 0*/
int get_Neighbors_State(int row, int column, int grid_size,
                        struct Cell arr[][grid_size]) {
  if (grid_size <= 0 || row >= grid_size || column >= grid_size) {
    return 7;
  }

  /* bit 4: OPEN
   * bit 3: LEFT
   * bit 2: UP
   * bit 1: DOWN
   * bit 0: RIGHT
   */

  int dir[4][2] = {
      {0, 1},  // Right
      {1, 0},  // down
      {-1, 0}, // up
      {0, -1}  // left
  };

  for (int idx = 0; idx < 4; idx++) {
    int next_row = (int)row + dir[idx][0];
    int next_column = (int)column + dir[idx][1];

    if (next_row >= 0 && next_row < grid_size && next_column >= 0 &&
        next_column < grid_size) {
      if (BITVALUE(arr[next_row][next_column].meta_data, 4)) {
        SETBIT(arr[row][column].meta_data, idx);
      }
    }
  }
  return 0;
}
