#include <stdio.h>
#include <stdlib.h>

/*
Un mazzo completo di carte da gioco francesi contiene 52 carte, di 4 semi
distinti.
Rappresentiamo le carte con un valore v, compreso tra 1 e 13 (asso,
due ... dieci ... donna, re), e un seme s (1=picche, 2=fiori, 3=quadri,
4=cuori).
Un file di testo pu`o descrivere un insieme arbitrario di carte, anche
vuoto, contenendo una sequenza di loro rappresentazioni nella forma (v,s) con
parentesi e virgola esplicitamente contenute nel file; le descrizioni delle
carte sono consecutive, senza nessun altro carattere intermedio, fino alla fine
del file, e contengono valori validi (diversamente, il file non `e ben formato,
ma per semplicit`a trascureremo questa eventualit`a).
Si codifichi un programma C che riceve come unico parametro da linea di comando
il nome del file (una stringa che assumiamo essere non vuota e ben formata) e
stampa su stdout ”OK” se il file esiste e descrive un mazzo completo, con tutte
e sole le 52 carte, ”KO” altrimenti (il file non c’`e, qualche carta manca,
oppure `e duplicata).
`E ovviamente possibile definire funzioni e strutture dati ausiliarie.
*/

#define VALORI 13
#define SEMI 4

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Utilizzo: %s [percorso al file del mazzo di carte]\n", argv[0]);
    return -1;
  }

  char* path = argv[1];
  FILE* fileMazzo = fopen(path, "r");

  if (fileMazzo == NULL) {
    printf("Impossibile aprire il file\n");
    return -1;
  }

  int lookup[VALORI][SEMI] = {0};

  int valore;
  int seme;

  while (fscanf(fileMazzo, "(%d,%d)", &valore, &seme) != EOF) {
    if (lookup[valore - 1][seme - 1]) {
      // contiene due volte la stessa carta
      printf("KO 1\n");
      return 0;
    }

    lookup[valore - 1][seme - 1] = 1;
  }

  for (int i = 0; i < VALORI; i++) {
    for (int j = 0; j < SEMI; j++) {
      if (!lookup[i][j]) {
        // manca una carta
        printf("KO\n");
        return 0;
      }
    }
  }

  printf("OK\n");
  return 0;
}
