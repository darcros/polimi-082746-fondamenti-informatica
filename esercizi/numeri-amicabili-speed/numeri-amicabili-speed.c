#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int divisori(int a) {
  int n = 0;

  for (int i = 1; i < a; i++) {
    if (a % i == 0) {
      n += i;
      // printf("%d %% %d\n", a, i);
    }
  }

  return n;
}

/*
ESE: Trovare tutti i numeri amicabili minori di MAX nel minor tempo possibile.
*/

#define MAX 100000

int main() {
  unsigned int tabella[MAX] = {0};
  clock_t inizio = clock();

  for (int n = 1; n < MAX; n++) {
    for (int i = n * 2; i < MAX; i += n) {
      tabella[i] += n;
    }
  }

  clock_t tabellaCalcolata = clock();
  printf("tabella calcolata: %f secondi\n",
         (double)(tabellaCalcolata - inizio) / CLOCKS_PER_SEC);

  int tot = 0;
  for (unsigned int a = 1; a < MAX; a++) {
    for (unsigned int b = 1; b < a; b++) {
      if (tabella[a] == b && tabella[b] == a) {
        printf("%d\t%d\n", a, b);
        tot++;
      }
    }
  }

  clock_t fine = clock();
  printf("trovati numeri: %f secondi\n",
         (double)(fine - tabellaCalcolata) / CLOCKS_PER_SEC);
  printf("tempo totale: %f secondi\n",
         (double)(fine - inizio) / CLOCKS_PER_SEC);

  return 0;
}
