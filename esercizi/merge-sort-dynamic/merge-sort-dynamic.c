#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 9

/*
Implementazione del merge sort.

La funzione sort() è uguale a `esercizi/merge-sort`. La funzione merge() è
reimplementata per utilizzare meno tempo, utilizza la memoria dinamica per
creare un array di supporto per effettura il merge.
*/

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

  // caso base: array di 1 o 0 celle
  if (len <= 1)
    // è già ordinato per forza
    return;

  // caso base: array di 2 celle
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
  // Alloco un array di interi della dimenzione dei due sotto-array contigue di
  // cui devo effetuare il merge
  int* tmp = malloc(sizeof(int) * (end - start + 1));

  int i = start;       // indice primo arr
  int j = middle + 1;  // indice secondo arr
  int k = 0;           // indice tmp

  // Ricopia in tmp gli elementi del primo e del secondo array in ordine.
  // Se avanzano elementi del primo arrayo del secondo array li ricopia tutti in
  // tmp. (nota: ci sono due cicli while ma solo uno viene eseguito).
  while (i < middle + 1 && j <= end)
    tmp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
  while (i < middle + 1)
    tmp[k++] = arr[i++];
  while (j <= end)
    tmp[k++] = arr[j++];

  // Copia tutto da tmp, che ora è ordinato, alla posizione originariamente
  // occupata dai due array
  while (--k >= 0)
    arr[k + start] = tmp[k];

  free(tmp);
}
