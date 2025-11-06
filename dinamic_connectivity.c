#include<stdio.h>
#include <stdlib.h>
#include <time.h>


// prototypes
void initlize_sequence(int arr[], int size);
int quick_Find(int arr[],int p,int q,int size);
void quick_Find_Union(int arr[],int p,int q,int size); 
void shuffle_Static_Array(int arr[], int size);
void swap_Integers(int *a, int *b);

int main(void){
  // It won't be random for every exicuation without seeding
  srand(time(NULL));

  int size = 0;
  printf("How many numbers of elements do you need: ");
  scanf("%d", &size);
  
  int connection_count = 0;
  printf("\nconnection counts: ");
  scanf("%d", &connection_count);
  
  int arr[size];
  initlize_sequence(arr, size);

  
  printf("\nUnion Format <number> connect to <number>: \n");
  for(int i = 0; i < connection_count; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    if ((p >= size) && (q >= size)) {
      printf("\n Invalid randge, Provide agian!\n");
      connection_count++;
    }
    quick_Find_Union(arr, p, q, size);
  }
  
  printf("\nResult: ");
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}





// it generates a random list that can be used as joining requests because all elements are distinct
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

// arr[i] = j means i is connected to j which is also a index of arr
void quick_Find_Union(int arr[],int p,int q,int size) {
  if ( ((p >= size) & (q >= size)) || (size < 0) ){
    printf("\n Invalid Quick Find request for connection %d %d within range %d", p, q, size);
    exit(EXIT_FAILURE);
  } 
  int pid = arr[p];
  int qid = arr[q];
  for (int i = 0; i < size; i++) {
    if (arr[i] == pid) {
      arr[i] = qid;
    }
  }
} 

int quick_Find(int arr[],int p,int q,int size) {
  if ( ((p >= size) && (q >= size)) || (size < 0) ){
    printf("\n Invalid Quick Find request for connection %d %d within range %d", p, q, size);
    exit(EXIT_FAILURE);
  } 
  return (arr[p] == arr[q]);
}

