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
