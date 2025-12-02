/*
 * Dynamic Arrays & Multidimensional Arrays in C — Cheat Sheet
 * -----------------------------------------------------------
 * This file summarizes how to create dynamic arrays of any dimension.
 */

#include <stdio.h>
#include <stdlib.h>

/* =============================
   1. BASIC DYNAMIC ARRAY (1D)
   ============================= */
void example_1D() {
    int n = 10;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) arr[i] = i;

    free(arr);
}

/* ==========================================
   2. RESIZING A DYNAMIC ARRAY WITH realloc
   ========================================== */
void example_realloc() {
    int n = 10;
    int *arr = malloc(n * sizeof(int));

    int new_n = 20;
    int *tmp = realloc(arr, new_n * sizeof(int));
    if (!tmp) {
        free(arr);
        return;
    }
    arr = tmp;

    free(arr);
}

/* =============================================
   3. ARRAY OF STRUCTS (NO NULL TERMINATOR NEEDED)
   ============================================= */
typedef struct {
    int id;
    float score;
    char name[50];
} Item;

void example_struct_array() {
    int n = 5;
    Item *items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
    }

    free(items);
}

/* =============================
   4. 2D ARRAY — METHOD 1
   Array of pointers (jagged allowed)
   ============================= */
void example_2D_pointer() {
    int rows = 3, cols = 4;
    int **arr = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
        arr[i] = malloc(cols * sizeof(int));

    // free
    for (int i = 0; i < rows; i++) free(arr[i]);
    free(arr);
}

/* =========================================
   5. 2D ARRAY — METHOD 2 (Single block)
   Fastest, best for higher dimensions
   ========================================= */
void example_2D_single_block() {
    int rows = 3, cols = 4;
    int *arr = malloc(rows * cols * sizeof(int));

    #define IDX(i,j) ((i) * cols + (j))
    arr[IDX(1,2)] = 42;

    free(arr);
}

/* ================================================
   6. 2D ARRAY — METHOD 3 (Pointer-to-array syntax)
   Keeps arr[i][j] syntax but dynamic size
   ================================================ */
void example_2D_ptr_array() {
    int rows = 3, cols = 4;
    int (*arr)[cols] = malloc(rows * sizeof *arr);

    arr[1][2] = 99;

    free(arr);
}

/* ================================================
   7. 3D & HIGHER-DIMENSION ARRAYS (Single block)
   Best general solution for 3D, 4D, ...
   ================================================ */
void example_3D_single_block() {
    int X = 3, Y = 4, Z = 5;

    int *arr = malloc(X * Y * Z * sizeof(int));

    #define IDX3(i,j,k) ((i) * Y * Z + (j) * Z + (k))

    arr[IDX3(1,2,3)] = 7;

    free(arr);
}

/* =============================
   8. DYNAMIC MEMORY MANAGEMENT NOTES
   ============================= */
/*
 - malloc(size): allocates raw memory, uninitialized.
 - calloc(n, size): allocates and zero-initializes.
 - realloc(ptr, new_size): resizes a block; may move it.
 - free(ptr): releases memory; ptr becomes invalid.

 Common pitfalls:
 - Never use memory after free.
 - Always check allocation results.
 - Prefer single-block allocation for multidimensional arrays.
 - memset can initialize larger blocks.
*/

/* =============================
   9. AMAZING EXAMPLES
   ============================= */

/* Example A: Auto-growing dynamic array (vector-like) */
typedef struct {
    int *data;
    int size;
    int capacity;
} DynArray;

void da_init(DynArray *a) {
    a->size = 0;
    a->capacity = 4;
    a->data = malloc(a->capacity * sizeof(int));
}

void da_push(DynArray *a, int value) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        int *tmp = realloc(a->data, a->capacity * sizeof(int));
        if (!tmp) return;
        a->data = tmp;
    }
    a->data[a->size++] = value;
}

void da_free(DynArray *a) {
    free(a->data);
}

/* Example B: Storing 3D positions in single-block memory */
typedef struct {
    float x, y, z;
} Vec3;

void example_vec3_grid() {
    int X = 10, Y = 10, Z = 10;
    Vec3 *grid = malloc(X * Y * Z * sizeof(Vec3));

    #define VEC3_IDX(i,j,k) ((i) * Y * Z + (j) * Z + (k))

    grid[VEC3_IDX(2,3,4)].x = 1.0f;
    grid[VEC3_IDX(2,3,4)].y = 2.0f;
    grid[VEC3_IDX(2,3,4)].z = 3.0f;

    free(grid);
}

/* =============================
   10. SAFE DYNAMIC MEMORY PRACTICES
   ============================= */
/*
 1. Always check malloc/calloc/realloc results.
    Example:
        int *p = malloc(n * sizeof(int));
        if (!p) { /* handle failure */ }

 2. For realloc, use a temporary pointer to avoid losing memory:
        int *tmp = realloc(p, new_size);
        if (!tmp) { free(p); return; }
        p = tmp;

 3. Initialize memory when needed (calloc or memset).

 4. Prevent leaks: every malloc must have exactly one free.
    - Do not exit early without freeing.
    - Do not overwrite pointers before freeing.
    - Do not double-free.

 5. Avoid use-after-free:
        free(p);
        p = NULL; // optional but safer

 6. Avoid out-of-bounds access:
        for (int i = 0; i < size; i++) { ... }

 7. Prefer single-block allocation for 2D/3D arrays to minimize complexity.

 8. Use structs to group ownership of dynamic memory.

 9. Use valgrind for debugging memory issues:
        valgrind --leak-check=full ./app

 10. Golden Rules:
     - Check allocations
     - Free exactly once
     - Never use freed memory
     - Never access outside bounds
     - Prefer contiguous blocks
*/

/* ==========================================
   END OF CHEAT SHEET
   ========================================== */

int main() {
    return 0;
}
