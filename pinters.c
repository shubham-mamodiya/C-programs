#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = malloc(4);
  int *q = p;
  free(p);
  free(q); // double free error
  return EXIT_SUCCESS;
}
