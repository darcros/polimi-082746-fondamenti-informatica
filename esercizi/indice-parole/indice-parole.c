#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATORS " .,;:+*-/!?'()\t\n\"\\<>"

/* L'indice si costruisce in memoriasotto forma di una lista di parole
   che conserva anche il numero di occorrenze trovate di ogni parola */
typedef struct st_Elem {
  char wor[30]; /* La parola */
  int occ;      /* Il numero di occorrenze */
  struct st_Elem* next;
} Node;

Node* ins_ord(
    Node*,
    char*); /* Inserimento ordinato "condizionato" nell'indice di parole */

int isSep(char);
void writeToFile(Node*, FILE*);
void dealloca(Node*);

int mf = 0; /* Misura la massima frequenza di una parola nel file - Può servire
               a qualcosa conoscerla? */

int leggiParola(FILE* fp, char* s) {
  int i = 0;

  char c;
  while ((c = fgetc(fp)) != EOF && !isSep(c)) {
    s[i] = c;
    i++;
  }
  s[i] = '\0';

  return c == EOF ? EOF : 1;
}

Node* costruisciIndice(FILE* fp) {
  Node* index = NULL;
  char* s = malloc(30 * sizeof(char));

  while (leggiParola(fp, s) != EOF) {
    if (strlen(s) > 3) {
      index = ins_ord(index, s);
    }
  }
  return index;
}

int main() {
  FILE* fp;

  // char * filein  = "divinacommedia_input.txt";
  char* filein = "dolcenera_tutta.txt";
  // char* filein = "dolcenera_incipit.txt";

  char* fileout = "Indice_Parole_output.txt";

  if ((fp = fopen(filein, "r")) == NULL) {
    printf("\n\n  ERRORE APERTURA FILE %s IN LETTURA\n\n", filein);
    return -1;
  }

  // costruisco indice
  Node* index = costruisciIndice(fp);

  fclose(fp); /* riuso fp */

  if (!(fp = fopen(fileout, "w"))) {
    printf("Errore aprendo %s in scrittura", fileout);
    return -2;
  }

  writeToFile(index, fp); /* Stampa l'indice, inizialmente vuoto */
  fclose(fp);             /* posso già chiudere il file */

  printf("\n\n");
  writeToFile(index,
              stdout); /* Stampa l'indice... anche a schermo! Barbatrucco! */
  printf("\n\n (max freq: %d)\n", mf);

  dealloca(index);

  return 0;
}

/*** Ben tre funzioni omaggio - ben più di un qualsiasi Cashback! ***/

Node* ins_ord(Node* head, char w[]) {
  Node *cur = head, *prev = NULL; /* Due puntatori di supporto */
  Node* t;

  while (cur != NULL && strcmp(cur->wor, w) <= 0) {
    prev = cur;
    cur = cur->next;
  }

  if (prev != NULL && strcmp(prev->wor, w) == 0) {
    prev->occ += 1;
    if (prev->occ >
        mf) /* PER TROVARE LA MASSIMA FREQUENZQA, che è una variabile globale */
      mf = prev->occ;
    return head;
  }

  t = (Node*)malloc(sizeof(Node));
  strcpy(t->wor, w);
  t->occ = 1;
  t->next = cur;

  if (prev == NULL)
    return t;
  else {
    prev->next = t;
    return head;
  }
}

/* returns 1 if c is in SEPARATORS, 0 otherwise */
int isSep(char c) {
  char* s = SEPARATORS;
  while (*s != '\0')
    if (*(s++) == c)
      return 1;
  return 0;
}

void writeToFile(Node* h, FILE* fp) {
  if (h == NULL)
    fprintf(fp, "INDICE VUOTO\n");

  while (h != NULL) {
    fprintf(fp, "%s (%d)\n", h->wor, h->occ);
    h = h->next;
  }
  return;
}

void dealloca(Node* p) {
  if (p != NULL) {
    dealloca(p->next);
    free(p);
  }
  return;
}
