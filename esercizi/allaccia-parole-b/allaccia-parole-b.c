#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERLAPMINIMO 1

/* Restituisce 0 se l'overlap è nullo o inferiore a OVERLAPMINIMO,
   altrimenti restituisce la misura dell'overlap **massimo** tra p e q */
int misuraoverlap(char*, char*);
/* FUNZIONE  IN OMAGGIO - implementata in fondo */

/* Stampa le parole allacciate come da specifica */
void stampa_allacciate(char*, char*);
/* FUNZIONE  IN OMAGGIO - implementata in fondo */

char* allaccia(char*, char*);

#define N 12

int main() {
  char* a[] = {"oca",         "spora", "isola",       "bugiardi",
               "imposta",     "corpo", "violoncello", "cortometraggi",
               "violoncello", "forma", "coraggio",    "trogolo"};

  char* b[] = {"carina",    "radici",     "lamento",    "giardino",
               "stazione",  "orazione",   "cellophane", "traggicamente",
               "cellulare", "formazione", "raggio",     "zangola"};

  int i;
  char* p;

  for (i = 0; i < N; i++) {
    stampa_allacciate(a[i], b[i]);
    p = allaccia(a[i], b[i]);
    printf(" ---> %s\n", p ? p : "NULL");
  }
  printf("\n\n");

  return 0;
}

char* allaccia(char* p, char* q) {
  int overlap = misuraoverlap(p, q);
  if (overlap == 0) {
    return NULL;
  }

  char* newStr = (char*)malloc(overlap + 1);
  strncpy(newStr, q, overlap);

  return newStr;
}

/*
   Funzioni "regalate" dalla soluzione all'esercizio precedente
   (facendo finta di averlo svolto correttamente)
*/

int SovrapponibiliConNcaratteri(char* p, char* q, int n) {
  int i, lun_p = strlen(p);
  for (i = 0; i < n; i++)
    if (p[lun_p - n + i] != q[i])
      return 0;
  return 1;
}

int misuraoverlap(char* p, char* q) {
  int max_ov = strlen(p) - 1;
  if (max_ov >= strlen(q))
    max_ov = strlen(q) - 1;
  for (; max_ov >= OVERLAPMINIMO; max_ov--)
    if (SovrapponibiliConNcaratteri(p, q, max_ov))
      return max_ov;
  return 0;
}

void selectiveprint(char* p, int n) {
  while (n-- > 0)
    printf("%c", *(p++));
}

void stampa_allacciate(char* p1, char* p2) {
  int ov, l1;
  ov = misuraoverlap(p1, p2);
  if (ov == 0)
    printf("(%s)[%s]", p1, p2);
  else {
    l1 = strlen(p1);
    printf("(");
    selectiveprint(p1, l1 - ov);
    printf("[%s)%s]", p1 + l1 - ov, p2 + ov);
  }
}
