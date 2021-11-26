#include <stdio.h>

#define ARR_SIZE 9

void sort(int* arr, int start, int end);
void merge(int* arr, int start, int middle, int end);
void print(int arr[], int len);
void swap(int* a, int* b);

int main() {
  int arr[ARR_SIZE] = {10, 9, 0, 1, -5, -1, 23, 14, -2};
  printf("Array originale: ");
  print(arr, ARR_SIZE);

  sort(arr, 0, ARR_SIZE - 1);
  printf("Array ordinato:  ");
  print(arr, ARR_SIZE);

  return 0;
}

void print(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%3d ", arr[i]);
  }
  printf("\n");
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int* arr, int start, int end) {
  int len = end - start + 1;

  // base: array di 1 o 0 celle
  if (len <= 1)
    // è già ordinato per forza
    return;

  // base: array di 2 celle
  if (len == 2) {
    // controlla se è ordinato ed eventualmente swappare
    if (arr[start] > arr[end]) {
      swap(&arr[start], &arr[end]);
    }
    return;
  }

  // caso induttivo
  int middle = (start + end) / 2;
  sort(arr, start, middle);
  sort(arr, middle + 1, end);
  merge(arr, start, middle, end);
}

// unisce due sottoarray contigui in un array ordinato
void merge(int* arr, int start, int middle, int end) {
  // per ogni elemento dell'array di sinistra
  for (int i = start; i <= middle; i++) {
    // se l'elemento di sinistra è maggiore del primo elemento del l'array di
    // destra allora swap
    if (arr[i] > arr[middle + 1])
      swap(&arr[i], &arr[middle + 1]);

    // rirdino solo l'array di destra, quello di sinistra è garantito che sia
    // ordinato
    sort(arr, middle + 1, end);
  }
}
