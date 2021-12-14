#include <stdio.h>
#include <stdlib.h>

#define SIZE_D 100
#define SIZE_V 10

typedef struct t_el {
  struct {
    int day;
    int month;
    int year;
  } data;
  float temperature;
  char description[SIZE_D];
  int vettore[SIZE_V];
} Tipo;

typedef struct Elem {
  Tipo dato;
  struct Elem* next;
} Nodo;

Nodo* InsCoda(Nodo* lista, Tipo t) {
  Nodo* p;
  if (lista == NULL) {
    p = (Nodo*)malloc(sizeof(Nodo));
    p->next = NULL;
    p->dato = t;
    return p;
  } else {
    lista->next = InsCoda(lista->next, t);
    return lista;
  }
}

void saveList(Nodo* lista, FILE* fp) {
  Nodo* cur = lista;

  while (cur != NULL) {
    Tipo t = cur->dato;
    fprintf(fp, "%d %d %d\n", t.data.day, t.data.month, t.data.year);
    fprintf(fp, "%f\n", t.temperature);
    fprintf(fp, "%s", t.description);
    for (int i = 0; i < SIZE_V; i++) {
      fprintf(fp, "%d ", t.vettore[i]);
    }
    fprintf(fp, "\n");

    cur = cur->next;
  }
}

/* possiamo ignorare per brevità i problemi dovuti a indisponibilità di memoria
 */
Nodo* loadList(FILE* fp) {
  Nodo* list = NULL;

  while (1) {
    Tipo t;
    int n = fscanf(fp, "%d %d %d\n", &t.data.day, &t.data.month, &t.data.year);
    if (n == EOF) {
      break;
    }

    fscanf(fp, "%f\n", &t.temperature);
    fgets(t.description, SIZE_D, fp);
    for (int i = 0; i < SIZE_V; i++) {
      fscanf(fp, "%d", &t.vettore[i]);
    }

    list = InsCoda(list, t);
  }

  return list;
}

void dealloca(Nodo* p) {
  if (p != NULL) {
    dealloca(p->next);
    free(p);
  }
  return;
}

int main() {
  FILE* fp;
  Nodo* lista = NULL;

  if ((fp = fopen("lista_su_file_input.txt", "r")) == NULL) {
    printf("\n\n  ERRORE APERTURA FILE IN LETTURA\n\n");
    return -1;
  }

  printf("\n\n  INIZIO  \n\n");
  lista = loadList(fp); /* Carica al lista da file */
  printf("\n\n  LISTA CARICATA  \n\n");

  fclose(fp);

  if (!(fp = fopen("lista_su_file_output.txt", "w"))) {
    printf("\n\n  ERRORE APERTURA FILE IN SCRITTURA\n\n");
    return -2;
  }

  saveList(lista, fp);
  dealloca(lista);
  fclose(fp);

  printf("\n\n  ARRIVEDERCI E GRAZIE\n\n");

  return 0;
}
