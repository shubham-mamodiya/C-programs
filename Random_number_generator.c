#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <openssl/rand.h>

// Prototyps
void psudo_Random(int min, int max, int count);
void random_on_linux(int min, int max, int count);
int random(void);

int main(void) {
  int count = 10;
  int min = 0;
  int max = 10;
  
  psudo_Random(min, max, count);
  random_on_linux(min, max, count); 

  return 0;
}


void psudo_Random(int min,int max, int count) {
  printf("Printing random numbers between %d, %d: ", min, max);
  
  // changing the seed

  srand(time(NULL));
  // loop for n(count) random numbers 
  for (int i = 0; i < count; i++){
    int number = rand() % (max - min + 1);
    printf("%d ", number);
  }
}




