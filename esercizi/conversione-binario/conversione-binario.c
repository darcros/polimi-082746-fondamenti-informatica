#include <stdio.h>

/*
Esercizio: leggere un numero in formato decimale e stamparlo in formato binario.
*/

int main() {
  int decimale;

  do {
    printf("inserisci un numero positivo: ");
    scanf("%d", &decimale);
  } while (decimale < 0);

  // calcolo il numero di cifre di cui avrò bisogno
  int cifre = 0;
  int n = decimale;
  do {
    cifre++;
    n = n / 2;
  } while (n != 0);

  printf("%d (dec) -> ", decimale);

  // per ogni cifra (in ordine inverso)
  for (int i = cifre; i > 0; i--) {
    // calcolo il valore della n-esima cifra
    int cifra;
    int n = decimale;
    for (int j = 0; j < i; j++) {
      cifra = n % 2;
      n = n / 2;
    }

    printf("%d", cifra);
  }
  printf(" (bin)\n");

  return 0;
}
