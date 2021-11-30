#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
ESE: Trovare tutti i numeri amicabili minori di MAX nel minor tempo possibile.
*/

#define MAX 10000000

int main() {
  clock_t inizio = clock();

  // Utilizzo un'array di interi dove a ogni indice corrisponde la somma dei
  // divisori di quel numero.
  //
  // NOTA 1: Qui *potrei* usare un array statico di dimensione MAX però a quanto
  // pare c'è un limite alla dimensione allocabile sullo stack, nel mio caso con
  // gcc (Ubuntu 10.3.0-1ubuntu1) 10.3.0 con un valore MAX 10000000 si ottiene
  // un segfault.
  // NOTA 2: È importante usare calloc perchè il ciclo for sottostante si
  // aspetta che tutti i valori dell'array siano inizializati a 0.
  unsigned int* sommeDivisori = calloc(MAX, sizeof(unsigned int));

  clock_t allocazione = clock();

  for (int n = 1; n < MAX; n++) {
    for (int i = n + n; i < MAX; i += n) {
      sommeDivisori[i] += n;
    }
  }

  clock_t tabellaCalcolata = clock();

  int tot = 0;
  for (unsigned int n = 1; n < MAX; n++) {
    int possibileAmico = sommeDivisori[n];

    int amicabili =
        // evitiamo di mostrare coppie duplicate
        possibileAmico < n
        // evitiamo di fare accessi out-of-bounds su sommeDivisori (non serve
        // controllare possibileAmico<0 perchè la somma di divisori positivi
        // non è mai <0)
        && possibileAmico < MAX
        // controlla che i numeri siano amicabili
        && sommeDivisori[possibileAmico] == n;

    if (amicabili) {
      printf("%d\t%d\n", n, possibileAmico);
      tot++;
    }
  }

  clock_t fine = clock();

  printf("\n=== RIASSUNTO ===\n");
  printf("%d coppie trovate\n", tot);
  printf("allocazione tabella delle somme dei divisori: %f secondi\n",
         (double)(allocazione - inizio) / CLOCKS_PER_SEC);
  printf("calcolo delle somme dei divisori: %f secondi\n",
         (double)(tabellaCalcolata - allocazione) / CLOCKS_PER_SEC);
  printf("ricerca coppie: %f secondi\n",
         (double)(fine - tabellaCalcolata) / CLOCKS_PER_SEC);
  printf("tempo totale: %f secondi\n",
         (double)(fine - inizio) / CLOCKS_PER_SEC);

  return 0;
}
