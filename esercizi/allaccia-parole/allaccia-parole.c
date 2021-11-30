#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERLAPMINIMO 1

/* Restituisce 1 se p e q sono sovrapponibili con un suffisso/prefisso
   di esattamente n caratteri, 0 altrimenti */
int SovrapponibiliConNcaratteri(char* p, char* q, int n) {
  int l1 = strlen(p);
  // int l2 = strlen(q);
  // int minLen = l1 < l2 ? l1 : l2;

  for (int i = 0; i < n; i++) {
    if (p[l1 - n + i] != q[i]) {
      return 0;
    }
  }

  return 1;
}

/* Restituisce 0 se l'overlap è nullo o inferiore a OVERLAPMINIMO,
   altrimenti restituisce la misura dell'overlap **massimo** tra p e q */
int misuraoverlap(char* p, char* q) {
  int l1 = strlen(p);
  int l2 = strlen(q);
  int minLen = l1 < l2 ? l1 : l2;

  int maxOverlap = 0;
  for (int i = OVERLAPMINIMO; i < minLen; i++) {
    if (SovrapponibiliConNcaratteri(p, q, i)) {
      // NOTA A ME STESSO: non serve controllare che i > maxOverlap
      // perchè il for parte da OVERLAPMINIMO e va a salire
      maxOverlap = i;
    }
  }

  // cotrolla che il suf/pre-fisso sia proprio
  if (maxOverlap == l1 || maxOverlap == l2) {
    return 0;
  }

  return maxOverlap;
}

/* Stampa i primi n caratteri di p  */
void selectiveprint(char* p, int n) {
  for (int i = 0; i < n && p[i] != '\0'; i++) {
    putchar(p[i]);
  }

  return;
}

/* Stampa le parole allacciate come da specifica */
void stampa_allacciate(char* p1, char* p2) {
  int overlap = misuraoverlap(p1, p2);
  int l1 = strlen(p1);
  int l2 = strlen(p2);

  if (overlap == 0) {
    printf("(%s)[%s]", p1, p2);
  } else {
    printf("(");
    selectiveprint(p1, l1 - overlap);
    printf("[");
    selectiveprint(p2, l2 - overlap);
    printf(")");
    selectiveprint(p2 + overlap, l2 - overlap);
    printf("]");
  }
}

#define N 12

int main() {
  char* a[] = {"oca",         "spora", "isola",       "bugiardi",
               "imposta",     "corpo", "violoncello", "cortometraggi",
               "violoncello", "forma", "coraggio",    "trogolo"};

  char* b[] = {"carina",    "radici",     "lamento",    "giardino",
               "stazione",  "orazione",   "cellophane", "traggicamente",
               "cellulare", "formazione", "raggio",     "zangola"};

  int i;

  for (i = 0; i < N; i++) {
    stampa_allacciate(a[i], b[i]);
    printf("\n");
  }

  return 0;
}
