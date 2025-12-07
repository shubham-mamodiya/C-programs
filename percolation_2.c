#include "percolation_2.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: ./percolation_2 [size of experiment] [iterations for "
           "experiment ]");
    return 1;
  }

  // both are int declared in "percolation_2.h"
  grid_size = atoi(argv[1]);
  iter = atoi(argv[2]);

  if (grid_size < 0) {
    printf("!Invalid: Experiment size. \n\tMust be between 0 to 2 billion.");
    return 2;
  }

  if (iter < 0) {
    printf("!Invalid Iterations for experiment.\n\tMust be between 0 to 2 "
           "billion");
    return 3;
  }

  // grid to pointer to a 2D dynamic array in percolation_2.h
  grid = grid_size ? malloc(grid_size * sizeof(*grid)) : NULL;

  if (!grid) {
    printf("!No memory allocation of Experiment size %d", grid_size);
    return 4;
  }
  initialize(grid_size);
  return 0;
}

// Creates n-by-n grid, with all sites initially blocked
// returns 5 if grid_size is Invalid
int initialize(int grid_size) {
  if (grid_size < 0) {
    printf("!Invalid Perameter %d to initialize function", grid_size);
    return 5;
  }
  size_t index = 0;

  for (size_t idx = 0; idx < grid_size; idx++) {
    for (size_t jdx = 0; jdx < grid_size; jdx++) {
      grid[idx][jdx].number = index;
      grid[idx][jdx].size = 1;
      grid[idx][jdx].open = 0;
    }
  }

  return 0;
}

// opens the site (row, col) if it is not open already
// returns 6 if row or col is Invalid
int open(size_t row, size_t col) {
  if (row >= grid_size) {
    printf("!row index is Invalid %zu >= %d", row, grid_size);
    return 6;
  }
  if (col >= grid_size) {
    printf("!col index is Invalid %zu >= %d", col, grid_size);
    return 6;
  }
  grid[row][col].open = 1;
  return 0;
}

// is the site (row, col) open?
// returns 7 if row or col in Invalid
int isOpen(size_t row, size_t col) {
  if (row >= grid_size) {
    printf("!row index is Invalid %zu >= %d", row, grid_size);
    return 7;
  }
  if (col >= grid_size) {
    printf("!col index is Invalid %zu >= %d", col, grid_size);
    return 7;
  }
  return grid[row][col].open;
}

// returns the number of open sites
size_t numberOfOpenSites() {
  size_t opensites = 0;
  for (size_t idx = 0; idx < grid_size; idx++) {
    for (size_t jdx = 0; jdx < grid_size; jdx++) {
      if (grid[idx][jdx].open)
        opensites++;
    }
  }
  return opensites;
}

// connects neighbors of (row, col)
int connect_neighbors(int row, int col) {
  if (row >= grid_size || row < 0) {
    printf("!row index is Invalid %d >= %d or negative", row, grid_size);
    return 8;
  }
  if (col >= grid_size || col < 0) {
    printf("!col index is Invalid %d >= %d or negative", col, grid_size);
    return 8;
  }
  int dir[4][2] = {
      {0, -1}, // right
      {-1, 0}, // up
      {0, 1},  // left
      {1, 0}   // down
  };

  for (int idx = 0; idx < 4; idx++) {
    int next_row = dir[idx][0] + row;
    int next_col = dir[idx][1] + col;

    if (next_row >= 0 && next_row < grid_size && next_col >= 0 &&
        next_col < grid_size) {
      if (grid[next_row][next_col].open) {
      }
    }
  }
  return 0;
}

int root(unsigned int current) {
  if (current >= (grid_size * grid_size))
    return -1;

  unsigned int row = row_index(current);
  unsigned int col = col_index(current);
  while (grid[row][col].number != current) {
    current = grid[row][col].number;
    row = row_index(current);
    col = col_index(current);
  }
  return current;
}
