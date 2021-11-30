#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
ESE: Trovare tutti i numeri amicabili minori di MAX nel minor tempo possibile.
*/

#define MAX_DEFAULT 10000000

int main(int argc, char* argv[]) {
  int max;

  if (argc == 2) {
    max = atoi(argv[1]);

    // se la conversione non avviene con successo atoi() restituisce 0
    if (max != 0) {
      printf("utilizzo max=%d\n", max);
    } else {
      max = MAX_DEFAULT;
      printf(
          "numero non valido passato come primo argomento, uso max=%d "
          "(default)\n",
          MAX_DEFAULT);
    }
  } else {
    printf("Nessun numero passato come argomento, uso max=%d (DEFAULT)\n",
           MAX_DEFAULT);
    max = MAX_DEFAULT;
  }

  clock_t inizio = clock();

  // Utilizzo un'array di interi dove a ogni indice corrisponde la somma dei
  // divisori di quel numero.
  //
  // NOTA 2: È importante usare calloc perchè il ciclo for sottostante si
  // aspetta che tutti i valori dell'array siano inizializzati a 0.
  unsigned int* sommeDivisori = calloc(max, sizeof(unsigned int));

  clock_t allocazione = clock();

  for (int n = 1; n < max; n++) {
    for (int i = n + n; i < max; i += n) {
      sommeDivisori[i] += n;
    }
  }

  clock_t tabellaCalcolata = clock();

  int tot = 0;
  for (unsigned int n = 1; n < max; n++) {
    int possibileAmico = sommeDivisori[n];

    int amicabili =
        // evitiamo di mostrare coppie duplicate
        possibileAmico < n
        // evitiamo di fare accessi out-of-bounds su sommeDivisori (non serve
        // controllare possibileAmico<0 perchè la somma di divisori positivi
        // non è mai <0)
        && possibileAmico < max
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
