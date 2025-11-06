// cool_syntax_demo.c
#include <stdio.h>
#include <stdlib.h>

// 🔹 Bit field struct
struct Flags {
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
};

// 🔹 Function pointers
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

// 🔹 Macros with # and ##
#define STRINGIFY(x) #x
#define MAKE_VAR(name) int var_##name

// 🔹 Struct for compound literal demo
struct Point {
    int x, y;
};

int main(void) {
    // 1. Ternary operator
    int x = 10;
    int y = (x > 5) ? 100 : 200;
    printf("Ternary: y = %d\n", y);

    // 2. Comma operator
    int a = (printf("Hello, "), 42);
    printf("Comma operator result = %d\n", a);

    // 3. Compound literal
    int *arr = (int[]){1, 2, 3, 4};
    printf("Compound literal array: %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);

    // 4. Designated initializer
    int nums[5] = {[0] = 10, [3] = 20};
    printf("Designated init: %d %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4]);

    struct Point p = (struct Point){.x = 10, .y = 20};
    printf("Point: (%d, %d)\n", p.x, p.y);

    // 5. Bit fields
    struct Flags f = {1, 0, 1};
    printf("Flags: bold=%d italic=%d underline=%d\n", f.bold, f.italic, f.underline);

    // 6. for(;;) infinite loop (with break)
    int counter = 0;
    for (;;) {
        if (++counter > 2) break;
        printf("Looping... counter=%d\n", counter);
    }

    // 7. Function pointers
    int (*op)(int, int) = add;
    printf("Function pointer add: %d\n", op(2, 3));
    op = mul;
    printf("Function pointer mul: %d\n", op(2, 3));

    // 8. Macros
    printf("Macro stringify: %s\n", STRINGIFY(Hello World));
    MAKE_VAR(test);  // expands to int var_test
    var_test = 42;
    printf("Macro concat var_test = %d\n", var_test);

    // 9. goto cleanup pattern
    FILE *fp = fopen("does_not_exist.txt", "r");
    if (!fp) goto error;
    fclose(fp);

    return 0;

error:
    perror("File error");
    return 1;
}

/************* ARRAY BASICS *************/
int arr[5];           // array of 5 ints
arr[i];               // element i
*arr;                 // same as arr[0]
*(arr + i);           // same as arr[i]
&arr[i];              // address of element i

/************* ARRAY DECAYS TO POINTER *************/
int *p = arr;         // arr becomes pointer to first element
p[2];                 // valid, same as arr[2]

/************* PASSING ARRAY TO FUNCTION *************/
void fun(int arr[], int size);   // equivalent to:
void fun(int *arr, int size);    // arr becomes pointer

fun(arr, 5);          // ✅ call — no brackets

void fun(int arr[], int size) {
    arr[0] = 10;       // valid (modifies original array)
}

/************* SIZE OF ARRAY *************/
int a[10];
int size = sizeof(a) / sizeof(a[0]);   // ✅ works here

void fun2(int arr[]) {
    sizeof(arr);      // ❌ arr is pointer here, NOT full array
}

/************* POINTER VS ARRAY *************/
int *p = arr;         // pointer to first element
p++;                 // ✅ pointer moves to next element
arr++;               // ❌ invalid, arrays can't move

/************* DYNAMIC ARRAY *************/
int *d = malloc(n * sizeof(int));
fun(d, n);

/************* FIXED-SIZE ARRAY IN FUNCTION *************/
void fun3(int (*arr)[10]) {   // array must be size 10
    (*arr)[3] = 100;
}

int a2[10];
fun3(&a2);



////////////////////////////////////////////////////////////////*
  //   !num means is num == 0
  // num in a condition means asking is num != 0
  // a boolien function returns 1 for True 
  // and 0 for false 
  // non boolien function return 0 for success or say true 
  // non zero for error or say false 
    /*
       HOW IF STATEMENTS WORK IN C
       -----------------------------
       if (something)  → runs when "something" is TRUE

       TRUE in C  = any non-zero value
       FALSE in C = zero (0)

       So these are true:
            if (5)
            if (-7)
            if (100)

       And these are false:
            if (0)
            if (false)
    */

  /*
  SUMMARY
  ----------------------------------------------------
  - C treats 0 as false, anything else as true
  - if (value) runs when value is true (non-zero)
  - if (!value) runs when value is false (zero)
  - return true;  means return 1
  - return false; means return 0
  - && = AND
  - || = OR
  - !  = NOT
*/
