#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototypes
void initialize_sequence(int arr[], int size);
int quick_Find_Connected(int arr[], int p, int q, int size);
void quick_Find_Union(int arr[], int p, int q, int size);
int quick_Union_Connected(int arr[], int p, int q, int size);
void quick_Union_Union(int arr[], int p, int q, int size);
int weighted_Quick_Union_Connected(int arr[], int p, int q, int size);
void weighted_Quick_Union_Union(int arr[], int p, int q, int size,
                                int weights[]);
int root(int arr[], int x, int size);
int f_Root(int arr[], int x, int size);
void flat_Tree(int arr[], int size);
void shuffle_Static_Array(int arr[], int size);
void swap_Integers(int *a, int *b);

int main(void) {
  // It won't be random for every execution without a new seeding
  srand(time(NULL));

  // size for connection components or elements in the intier connection
  int size = 0;
  printf("How many numbers of elements do you need: ");
  scanf("%d", &size);
  if (size <= 0) {
    printf("Invalid size length. It should be greater then 0.");
    return 1;
  }

  int connection_count = 0;
  printf("\nconnection counts: ");

  scanf("%d", &connection_count);
  if (connection_count <= 0) {
    printf("Invalid Connection counts. It should be greater then 0.");
    return 2;
  }

  // Element == vlaue, means element is connected to value(also an index)
  int arr[size];
  initialize_sequence(arr, size);

  // size array for Weighted Quick Union
  int weights[size];
  for (int i = 0; i < size; i++) {
    weights[i] = 1; // because each element is connected to itself
  }

  // making unions
  printf("\nUnion Format <number> connect to <number>: \n");
  for (int i = 0; i < connection_count; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    if (p < 0 || q < 0 || p >= size || q >= size) {
      printf("\n Invalid range, Provide again!\n");
      i--;
      continue;
    }
    quick_Union_Union(arr, p, q,
                      size); // change here for diffrent Union algorithm
  }

  // asking for connection checks
  int choise;
  while (1) {
    // choise for continuation, 1 for continue.
    printf("Do you want to check connection type 1 for yes anything else for "
           "not: ");
    choise = 0;
    scanf("%d", &choise);
    if (choise != 1) {
      break;
    }

    // conditions for safety
    printf("Connection check Request Format <number> to <number>: \n");
    int p = -1; // scanf can also return -ve values
    int q = -1;
    scanf("%d %d", &p, &q);
    if ((p >= size) || q >= size || p < 0 || q < 0) {
      printf(
          "\n Invalid Quick Find request for connection %d %d within range %d",
          p, q, size);
      continue;
    }

    if (quick_Union_Connected(arr, p, q, size)) {
      printf("\nConnected!\n");
    } else {
      printf("\n Not Connected!\n");
    }
  }
  return 0;
}

// it generates a random list that can be used as joining requests because all
// elements are distinct
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

void initialize_sequence(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

// arr[i] = j means i is connected to j which is also a index of arr
void quick_Find_Union(int arr[], int p, int q, int size) {
  // if (((p >= size) && (q >= size)) || (size < 0)) { wrong
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf("\n Invalid Quick Find request for connection %d %d within range %d",
           p, q, size);
    exit(3);
  }
  int pid = arr[p];
  int qid = arr[q];
  for (int i = 0; i < size; i++) {
    if (arr[i] == pid) {
      arr[i] = qid;
    }
  }
}

int quick_Find_Connected(int arr[], int p, int q, int size) {
  //  if (((p >= size) && (q >= size)) || (size < 0)) {
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf("\n Invalid Quick Find request for connection %d %d within range %d",
           p, q, size);
    exit(4);
  }
  return (arr[p] == arr[q]);
}

int root(int arr[], int x, int size) {
  if (x < 0 || x >= size) {
    printf("Invalid request!, %d is out of range.", x);
    exit(5);
  }
  while (arr[x] != x) {
    x = arr[x];
  }
  return x;
}

int quick_Union_Connected(int arr[], int p, int q, int size) {
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf("\n Invalid Quick Find request for connection %d %d within range %d",
           p, q, size);
    exit(6);
  }
  return (root(arr, p, size) == root(arr, q, size));
}

void quick_Union_Union(int arr[], int p, int q, int size) {
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf(
        "\n Invalid Quick union request for connection %d %d within range %d",
        p, q, size);
    exit(7);
  }
  int root_of_p = root(arr, p, size);
  int root_of_q = root(arr, q, size);
  arr[root_of_p] = arr[root_of_q];
}

int weighted_Quick_Union_Connected(int arr[], int p, int q, int size) {
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf("\n Invalid Quick Find request for connection %d %d within range %d",
           p, q, size);
    exit(8);
  }
  return (root(arr, p, size) == root(arr, q, size));
}

void weighted_Quick_Union_Union(int arr[], int p, int q, int size,
                                int weights[]) {
  // The approach is to connect smaller connected elements with bigger connected
  // elements connection menas connect roots
  if ((p >= size) || q >= size || p < 0 || q < 0) {
    printf(
        "\n Invalid Quick union request for connection %d %d within range %d",
        p, q, size);
    exit(9);
  }
  int root_of_p = root(arr, p, size);
  int root_of_q = root(arr, q, size);

  if (root_of_p == root_of_q) {
    arr[root_of_q] = root_of_p;
  }

  // connect smaller tree with larger tree
  if (weights[root_of_q] < weights[root_of_p]) {
    arr[root_of_q] = root_of_p;
  } else {
    arr[root_of_p] = root_of_q;
  }
}

// Flattens the tree to two nodes
void flat_Tree(int arr[], int size) {
  for (int i; i < size; i++) {
    arr[i] = root(arr, i, size);
  }
}

// Flat tree and find root keeps track that each brach is no more then three
// nodes in size
int f_Root(int arr[], int x, int size) {
  if (x < 0 || x >= size) {
    printf("Invalid request!, %d is out of range.", x);
    exit(10);
  }
  while (arr[x] != x) {
    arr[x] = arr[arr[x]]; // connect this node to root three above
    x = arr[x];
  }
  return x;
}
