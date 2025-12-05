#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <stddef.h>
#include <stdint.h>

#define FLAG_OPEN 0x10
#define FLAG_LEFT 0x8
#define FLAG_UP 0x4
#define FLAG_DOWN 0x2
#define FLAG_RIGHT 0x1

#define BITVALUE(X, N) (((X) >> (N)) & 1U)

#define SETBIT(X, N) ((X) |= (1U << N))

struct Root {
  int row;
  int column;
};

struct Cell {
  uint8_t meta_data; // 00011111, 000 just extra and unused bits.
  // 000<This><Left><Up><Down><Right> cells are open.
  // Any field will be 0 if that cell is not open or does not exists.

  /* bit4: OPEN
   * bit3: LEFT
   * bit2: UP
   * bit1: DOWN
   * bit0: RIGHT
   */

  struct Root root;
  int size; // Number of connected Cells
};

extern uint8_t open_bit_index;
extern uint8_t left_bit_index;
extern uint8_t up_bit_index;
extern uint8_t down_bit_index;
extern uint8_t Right_bit_index;

int initialize(int grid_size, struct Cell arr[][grid_size]);

int print_Grid(int grid_size,
               struct Cell arr[][grid_size]); // For small training set
int print_Grid(int grid_size, struct Cell arr[][grid_size]);

int state_Grid(int grid_size, struct Cell arr[][grid_size]);

int get_Neighbors_State(int row, int column, int grid_size,
                        struct Cell arr[][grid_size]);

#endif // PERCOLATION_H
