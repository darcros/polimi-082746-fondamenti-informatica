#include <stdio.h>

/*
Si scriva un programma C che legge da stdin un intero k e una sequenza di
caratteri di lunghezza arbitraria, e stampa su stdout la sequenza cifrata con la
"chiave" k (per brevità e semplicità, si considerino solo i caratteri
minuscoli).
*/

int main() {
  int k;
  char c;

  printf("inserisci la chiave k: ");
  scanf("%d", &k);

  // consuma il \n lasciato dalla precedente scanf
  scanf("\n");

  // riporta k nel range 0-26
  k = k % 26;

  do {
    scanf("%c", &c);

    // rendi tutte le lettere minusco
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';

    // applica offset solo alle lettere dell'alfabeto
    if (c >= 'a' && c <= 'z')
      c += k;

    printf("%c", c);
  } while (c != '\n');

  return 0;
}
