#include <stdio.h>

/*
Esercizio: Scrivere un programma che legge da stdin una sequenza (di lunghezza a
priori illimitata) di numeri interi positivi, terminata da 0, e indica, alla
fine della sequenza, qual è la lunghezza della massima sottosequenza costituita
da numeri in ordine strettamente crescente.
*/

int main() {
  int seq = 0;
  int max = 0;
  // visto che i numeri dovrebbero essere tutti positivi -1 è minore di
  // qualsiasi primo numero possa essere inserito
  int prev = -1;
  int n;

  while (1) {
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &n);

    if (n == 0) {
      printf("Lunghezza massima = %d\n", max);
      break;
    }

    if (n > prev) {
      seq++;
    } else {
      seq = 1;
    }
    prev = n;

    if (seq > max) {
      max = seq;
    }
  }

  return 0;
}
