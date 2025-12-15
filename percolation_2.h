#ifndef PERCOLATION_2
#define PERCOLATION_2

#include <stddef.h>

typedef struct Cell {
  unsigned int number;
  unsigned int open : 1;
  unsigned int size;
} Cell;

extern int grid_size;
extern int iter;
extern Cell (*grid)[0];
extern Cell virtual_top;
extern Cell virtual_bottom;

/* This is just a claver trick, but not acceptable*/
extern unsigned int top;
extern int is_top; // First open Cell at the top and all open Cell in
                   // first row are connected to it
extern unsigned int bottom;
extern int is_bottom; // First open Cell at the bottom row and all open
                      // Cell in bottom row are connected to it

#define row_index(x) (x / grid_size)
#define col_index(x) (x % grid_size)

int initialize(int grid_size);
int open(size_t row, size_t col);
int isOpen(size_t row, size_t col);
int isFull(size_t row, size_t col);
size_t numberofopensites();
int connect_neighbors(int row, int col);
int find_root(unsigned int root);
int connect_to_root(int row, int col, unsigned int root);

#endif // !PERCOLATION_2
