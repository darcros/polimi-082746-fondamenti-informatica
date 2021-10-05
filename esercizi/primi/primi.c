#include <stdio.h>

/*
Esercizio: Scrivere un programma che legge un numero intero positivo e controlla
se è primo o no.
*/

int main() {
  int n;
  printf("inserisci un numero: ");
  scanf("%d", &n);

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      printf("Non si tratta di un numero primo\n");
      return 0;
    }
  }

  printf("Si tratta di un numero primo\n");

  return 0;
}
