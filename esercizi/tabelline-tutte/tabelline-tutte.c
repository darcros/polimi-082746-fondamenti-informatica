#include <stdio.h>

/*
Esercizio: Scrivere un programma (per il "ripasso globale" delle tabelline) che
riceve da stdin due interi, n e k, e stampa la «tabellona» di tutte le tabelline
da 2 a n, limitandosi al k-esimo valore.
*/

int main() {
  int n, k;
  printf("inserisci n: ");
  scanf("%d", &n);
  printf("inserisci k: ");
  scanf("%d", &k);

  printf("\t");
  for (int i = 0; i <= k; i++) {
    printf("%d\t", i);
  }
  printf("\n");

  for (int i = 0; i <= k; i++) {
    printf("=========");
  }
  printf("\n");

  for (int i = 2; i <= n; i++) {
    printf("%d:\t", i);
    for (int j = 0; j <= k; j++) {
      printf("%d\t", i * j);
    }
    printf("\n");
  }

  return 0;
}
