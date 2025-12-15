#include "percolation_2.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int is_top = 0;
int is_bottom = 0;

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
      index++;
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

  int status = 0; // storage for function return values

  /* This part is just a trick to make it faster. but, it is not valid
   * approach*/
  if (row == 0) {
    if (!is_top) {
      top = grid[row][col].number;
      is_top = 1;
    } else {
      status = connect_to_root(row, col, top);
      if (status) {
        return status;
      }
    }
  }

  if (row == (grid_size - 1)) {
    if (!is_bottom) {
      bottom = grid[row][col].number;
      is_bottom = 1;
    } else {
      status = connect_to_root(row, col, bottom);
      if (status) {
        return status;
      }
    }
  }
  /* end */

  status = connect_neighbors(row, col);
  if (status) {
    return status; // probably
  }
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

  int current_root = find_root(grid[row][col].number);
  int current_root_row = row_index(current_root);
  int current_root_col = col_index(current_root);
  if (current_root == -1) {
    printf("!Cell (row, col) is not on grid.");
    return 9;
  }
  unsigned int current_root_size =
      grid[current_root_row][current_root_col].size;

  for (int idx = 0; idx < 4; idx++) {
    int next_row = dir[idx][0] + row;
    int next_col = dir[idx][1] + col;

    // only if neighboring Cell is on the grid
    if (next_row >= 0 && next_row < grid_size && next_col >= 0 &&
        next_col < grid_size) {
      // only if neighboring Cell is open
      if (grid[next_row][next_col].open) {
        // root of neighbor and it's index
        int neighbor_root = find_root(grid[next_row][next_col].number);
        int neighbor_root_row = row_index(neighbor_root);
        int neighbor_root_col = col_index(neighbor_root);
        unsigned int neighbor_root_size =
            grid[neighbor_root_row][neighbor_root_col].size;

        // connect small tree with bigger on
        if (current_root != neighbor_root) {
          if (grid[row][col].size < grid[next_row][next_col].size) {
            grid[row][col].number = neighbor_root;
            grid[neighbor_root_row][neighbor_root_col].size +=
                current_root_size;
          } else {
            grid[next_row][next_col].number = current_root;
            grid[row][col].size += neighbor_root_size;
          }
        }
      }
    }
  }
  return 0;
}

// finds the root of root parameter and makes the tree flat
// return -1 when root is Invalid
int find_root(unsigned int root) {
  if (root >= (grid_size * grid_size))
    return -1;

  unsigned int current = root;

  // Finding the root
  unsigned int row = row_index(root);
  unsigned int col = col_index(root);
  while (grid[row][col].number != root) {
    root = grid[row][col].number;
    row = row_index(root);
    col = col_index(root);
  }

  // Flattening the tree and making each Cell to point to it's root
  while (current != root) {
    current = grid[row][col].number;
    grid[row][col].number = root;
    row = row_index(current);
    col = col_index(current);
  }

  return root;
}

// connect (row, col) to root (top or bottom)
int connect_to_root(int row, int col, unsigned int root) {
  if (row >= grid_size || row < 0) {
    printf("!row index is Invalid %d >= %d or negative", row, grid_size);
    return 10;
  }
  if (col >= grid_size || col < 0) {
    printf("!col index is Invalid %d >= %d or negative", col, grid_size);
    return 10;
  }

  int current_root = find_root(grid[row][col].number);
  int current_root_row = row_index(current_root);
  int current_root_col = col_index(current_root);
  if (current_root == -1) {
    printf("!Cell (row, col) is not on grid.");
    return 11;
  }
  unsigned int current_root_size =
      grid[current_root_row][current_root_col].size;

  // indices for root
  int root_row = row_index(root_row);
  int root_col = col_index(root_col);
  if (root_row >= grid_size || root_row < 0) {
    printf("!row index is Invalid %d >= %d or negative", row, grid_size);
    return 10;
  }
  if (root_col >= grid_size || root_col < 0) {
    printf("!col index is Invalid %d >= %d or negative", col, grid_size);
    return 10;
  }

  unsigned int root_size = grid[root_row][root_col].size;

  // connect this Cell to the root
  if (current_root != root) {

    if (grid[row][col].size < grid[root_row][root_col].size) {
      grid[row][col].number = root;
      grid[root_row][root_col].size += current_root_size;
    }
  }

  return 0;
}
