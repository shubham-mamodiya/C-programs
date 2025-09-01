#include <stdio.h>

int main() {
  char name[50];

  printf("What is your name: ");
  fgets(name, 50, stdin);
  printf("Hello %s", name);
}
