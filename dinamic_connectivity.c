#include<stdio.h>
#include <stdlib.h>
#include <time.h>


// prototypes
void shuffle_Static_Array(int arr[], int size);
void swap_Integers(int *a, int *b);
void initlize_sequence(int arr[], int size);

int main(void){
  // It won't be random for every exicuation without seeding
  srand(time(NULL));

  int size;
  scanf("%d", &size);

  int arr[size];


}






void shuffle_Static_Array(int arr[], int size) {

    for (int i = size - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    swap_Integers(&arr[i], &arr[j]);
  }
}

void swap_Integers(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void initlize_sequence(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}
