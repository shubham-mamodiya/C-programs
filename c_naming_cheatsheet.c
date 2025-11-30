/*
 * C Naming Cheat Sheet
 * ---------------------
 * Quick reference for naming variables, functions, types,
 * files, macros, and constants in C.
 */

/*-----------------------------
  Variables
-----------------------------*/
/*
 * Use lower_snake_case
 * Be descriptive but short
 */
int counter;
float total_price;
char user_name[50];

/*-----------------------------
  Functions
-----------------------------*/
/*
 * lower_snake_case
 * Use verbs or verb phrases
 */
int get_user_age(void);
void print_result(int value);
float calculate_area(float width, float height);

/*-----------------------------
  Structs & Typedefs
-----------------------------*/
/*
 * Use PascalCase for struct typedefs
 * Use lower_snake_case for struct fields
 */
typedef struct User {
    int id;
    char name[100];
    float balance;
} User;

/*-----------------------------
  Enums
-----------------------------*/
/*
 * Enum types: PascalCase
 * Enum values: UPPER_SNAKE_CASE
 */
typedef enum Color {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE
} Color;

/*-----------------------------
  Macros & Constants
-----------------------------*/
/*
 * Use ALL_CAPS with underscores
 */
#define MAX_USERS 100
#define BUFFER_SIZE 1024
#define PI 3.14159

/*-----------------------------
  File Naming
-----------------------------*/
/*
 * snake_case filenames
 * header files end in .h
 * implementation files end in .c
 * match names: user.c <-> user.h
 */
// user.c, user.h

/*-----------------------------
  Prefixing & Namespacing
-----------------------------*/
/*
 * Avoid name collisions by prefixing
 * Project or module prefix recommended
 */
int app_load_data(void);
void app_save_data(const char *path);

/*-----------------------------
  Temporary Variables
-----------------------------*/
/*
 * Short but clear
 */
int i, j, k;  /* only for loops */

/*-----------------------------
  Extra Tips
-----------------------------*/
/*
 * - Do not use capitals for variables/functions
 * - Do not use very long names
 * - Be consistent
 * - Avoid ambiguous abbreviations
 */
