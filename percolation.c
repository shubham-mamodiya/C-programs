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

void initialize(short size, struct Cell arr[][size]);
void print_Grid(short size, struct Cell arr[][size]);

int main(int argc, char *argv[]) {
  srand(time(NULL));

  short n = 0;
  printf("Size of the Experiment upto 4000 possible: ");
  scanf("%hd", &n);
  if (n <= 0) {
    printf("\n ---Invalid size---\n");
    return 1;
  } else if (n > 4000) {
    printf("Size greater then 4000 will generate Segmentation fault due to "
           "Stack Overflow.\n Every average linux distibution have about 8MB "
           "for Stack.\n This program is not ment to run any experiments "
           "bigger then 4000 in size.");
    return 2;
    ;
  }
  struct Cell grid[n][n];
  initialize(n, grid);

  print_Grid(n, grid);

  return 0;
}

// Make each Cell connected to itself and Closed or blocked
void initialize(short size, struct Cell arr[][size]) {
  if (size < 0) {
    exit(3);
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

void print_Grid(short size, struct Cell arr[][size]) {
  if (size < 0) {
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

void randomized_Connections(short size, struct Cell grid[size][size]) {}

// void psudo_Random_Generator(int size, int)
