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

#define row_index(x) (x / grid_size)
#define col_index(x) (x % grid_size)

int initialize(int grid_size);
int open(size_t row, size_t col);
int isOpen(size_t row, size_t col);
int isFull(size_t row, size_t col);
size_t numberofopensites();

#endif // !PERCOLATION_2
