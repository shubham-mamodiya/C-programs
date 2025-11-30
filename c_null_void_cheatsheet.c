// null_void_cheatsheet.c
// Complete cheat sheet for NULL, null byte, void, and void* in C

#include <stddef.h> // for NULL
#include <stdio.h>

/* ==========================
   NULL (null pointer macro)
   ========================== */
// NULL is a macro that expands to a null pointer constant.
// It usually expands to ((void*)0) or 0.
// Used to represent 'no object' or 'invalid pointer'.

void example_null_pointer() {
    int *p = NULL;   // pointer to nothing
    if (p == NULL) {
        printf("p is NULL\n");
    }
}

/* ====================
   Null pointer value
   ==================== */
// Special pointer value meaning "points to no object".
// Bit pattern is implementation-defined.
// You cannot dereference a null pointer.

/* ==================
   Null character '\0'
   ================== */
// '\0' is the character with value 0 (a byte of zero).
// Used to terminate C strings.

void example_null_char() {
    char s[4] = {'c', 'a', 't', '\0'}; // explicit termination
    printf("%s\n", s);                 // prints: cat
}

/* ================
   Integer literal 0
   ================ */
// The literal 0 is special in C: if assigned to a pointer, it becomes
// a null pointer value.

void example_zero_null() {
    int *p = 0;  // same as NULL
    if (!p) {
        printf("p is null via zero literal.\n");
    }
}

/* ========
   void
   ======== */
// Type meaning "no value" or "empty type".
// Used in: function returns, function parameters, and generic pointers.

void func_returns_nothing(void) {
    printf("This function returns nothing.\n");
}

/* =============
   void * pointer
   ============= */
// A generic pointer type that can point to any object.
// You must cast it back before dereferencing.

void example_void_pointer() {
    int x = 42;
    void *vp = &x;        // ok
    int *ip = vp;         // implicit conversion allowed in C
    printf("%d\n", *ip); // prints 42
}

/* =========================
   Things NOT in C
   ========================= */
// nullptr   -> only in C++
// null      -> NOT a keyword
// void vars -> illegal: you cannot create "void v;"

int main() {
    example_null_pointer();
    example_null_char();
    example_zero_null();
    func_returns_nothing();
    example_void_pointer();
    return 0;
}
