#include <stdbool.h>
#include <stdio.h>

#define N 8

bool isCyclical(int arr[N]) {
  int mask[N] = {0};

  int i = 0;
  while (true) {
    // siamo usciti dall'array: non è ciclico
    if (i < 0 || i >= N) {
      return false;
    }

    // siamo tornati in un posto già visitato: è ciclico
    if (mask[i]) {
      return true;
    }

    // segna la posizione che abbiamo appena visitato e passa alla prossima
    mask[i] = 1;
    i = arr[i];
  }
}

int main() {
  int v1[N] = {3, -3, 5, 6, 2, 4, 2, 11};
  int v2[N] = {5, -6, 7, 6, 2, 4, 2, 9};

  printf("v1 %s ciclico\n", isCyclical(v1) ? "è" : "non è");
  printf("v2 %s ciclico\n", isCyclical(v2) ? "è" : "non è");

  return 0;
}
