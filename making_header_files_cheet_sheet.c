
/***********************************************************
    HEADER FILE CHEAT SHEET — IN ONE .c FILE

    This file demonstrates what normally goes inside a .h file
    and what belongs inside a .c file.
************************************************************/

// ----------------------------------------------------------
// 📌 This block represents what would normally be inside .h
// ----------------------------------------------------------

#ifndef STUDENT_H // include guard start
#define STUDENT_H

// Macros / Constants
#define MAX_NAME_LEN 50

// Struct / typedef
typedef struct {
  int id;
  char name[MAX_NAME_LEN];
} Student;

// Function declarations (prototypes)
void printStudent(const Student *s);
int add(int a, int b);

// Extern global variable declaration
extern int global_count;

#endif // STUDENT_H
// ----------------------------------------------------------
// 🔽 Everything above would normally be in student.h
// ----------------------------------------------------------
// 🔼 Everything below would normally be in student.c
// ----------------------------------------------------------

#include <stdio.h>
#include <string.h>

// Actual global variable definition
int global_count = 0;

// Function definitions (actual code)
void printStudent(const Student *s) {
  printf("ID: %d, Name: %s\n", s->id, s->name);
}

int add(int a, int b) { return a + b; }

// ----------------------------------------------------------
// main() just demonstrates usage
// ----------------------------------------------------------

int main() {
  Student st = {1, "Shubham"};
  printStudent(&st);

  printf("2 + 3 = %d\n", add(2, 3));

  global_count++;
  printf("global_count = %d\n", global_count);

  return 0;
}

/***********************************************************
What to remember:

.h file contains ↓
    • Function prototypes
    • Struct/typedef/enum
    • Macros & constants
    • extern global variables
    • Include guards

.c file contains ↓
    • Function implementations
    • Actual global variable definitions
    • Program logic

************************************************************/

// gcc header_cheatsheet.c -o demo
//./demo
