
/*  ARRAYS & POINTERS — REAL LIFE QUICK NOTES
 *  Arrays = lockers. You only get keys 0 → size-1.
 *  Going beyond = breaking into someone else's locker (undefined behavior).
 *
 *  Strings are special.
 *  char arrays used as strings store a STOP SIGN → '\0' null terminator.
 *  int/float/struct arrays DO NOT have any built-in ending marker.
 */

#include <stdio.h>

int main() {

  /* ----------- 1D INT ARRAY ----------- */
  int nums[5] = {10, 20, 30, 40, 50};
  for (int i = 0; i < 5; i++)
    printf("[%d] = %d\n", i, nums[i]);

  printf("\nBytes nums uses = %zu\n", sizeof(nums));
  printf("Total elements  = %zu\n", sizeof(nums) / sizeof(nums[0]));

  /* ----------- 2D INT ARRAY ----------- */
  int grid[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  printf("\nGrid values:\n");
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 4; c++)
      printf("[%d][%d]=%d\n", r, c, grid[r][c]);

  printf("\nGrid bytes = %zu\n", sizeof(grid));
  printf("Rows       = %zu\n", sizeof(grid) / sizeof(grid[0]));
  printf("Cols       = %zu\n", sizeof(grid[0]) / sizeof(grid[0][0]));

  /* ----------- POINTER VIEW ----------- */
  int *p = nums; // points to first element
  printf("\nPointer walk:\n");
  for (int i = 0; i < 5; i++)
    printf("*(p+%d) = %d\n", i, *(p + i));

  // p does NOT know total elements — YOU must track size.

  /* ----------- STRINGS & CHAR ARRAYS ----------- */
  char str1[] = "Code"; // auto adds '\0' → {'C','o','d','e','\0'}
  char str2[4] = {'T', 'e', 's', 't'}; // NO '\0' → not a valid C string

  printf("\nstr1 prints fine → %s\n", str1);

  printf("sizeof(str1) = %zu (includes null)\n", sizeof(str1));
  // printf("%s", str2); // UNSAFE — no null terminator, may print garbage

  // Manual termination example:
  char manual[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // valid string
  printf("manual → %s\n", manual);

  return 0;
}

/* TL;DR STICKY NOTE
 * Arrays: indexes only 0 → size-1.
 * int/float/struct arrays have NO ending marker.
 * Strings = char arrays ending with '\0' (null terminator = stop sign).
 * sizeof(arr)/sizeof(arr[0]) → element count (only before pointer decay).
 * pointer doesn't know size — track it manually.
 */
