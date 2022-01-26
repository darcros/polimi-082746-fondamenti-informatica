#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float x;
  float y;
} Punto;

typedef struct ND {
  Punto P;
  struct ND* next;
} Nodo;

typedef Nodo* Linea;

Linea insTesta(Linea l, Punto p) {
  Linea h = (Linea)malloc(sizeof(Nodo));
  h->P = p;
  h->next = l;
  return h;
}

void dealloca(Linea l) {
  if (l == NULL) {
    return;
  }

  dealloca(l->next);
  free(l);
}

Punto* mid(Punto A, Punto B) {
  Punto* m = (Punto*)malloc(sizeof(Punto));
  m->x = (A.x + B.x) / 2.0;
  m->y = (A.y + B.y) / 2.0;
  return m;
}

Linea riduci(Linea l) {
  if (!l)
    return NULL;

  Linea l2 = NULL;
  Linea cur = l;
  while (cur->next != NULL) {
    Punto* m = mid(cur->P, cur->next->P);
    l2 = insTesta(l2, *m);
    free(m);

    cur = cur->next;
  }

  return l2;
}

Punto* baricentro(Linea l) {
  if (!l)
    return NULL;

  Linea tmp1 = riduci(l);  // per evitare che l venga deallocata nel while sotto
  Linea tmp2 = NULL;

  while (tmp1->next != NULL) {
    tmp2 = riduci(tmp1);
    dealloca(tmp1);

    tmp1 = tmp2;
  }

  Punto* m = (Punto*)malloc(sizeof(Punto));
  *m = tmp1->P;
  dealloca(tmp1);

  return m;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("argomenti sbagliati\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    printf("errore file\n");
    return 1;
  }

  Linea l = NULL;
  Punto p;
  while (fscanf(fp, "%f %f", &p.x, &p.y) != EOF) {
    l = insTesta(l, p);
  }

  Punto* bb = baricentro(l);
  if (!bb) {
    printf("Mannaggia!\n");
  } else {
    printf("%f %f\n", bb->x, bb->y);
  }

  dealloca(l);
  free(bb);

  return 0;
}
