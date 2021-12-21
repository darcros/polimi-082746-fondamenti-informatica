#include <stdio.h>
#include <stdlib.h>

typedef int TipoElemento;

typedef struct EL {
  TipoElemento info;
  struct EL* prox;
} ElemLista;

typedef ElemLista* ListaDiElem;

/*************************************************************
                        PROTOTIPI
*************************************************************/

/* Prima meta' */

ListaDiElem Inizializza(void);

int ListaVuota(ListaDiElem lista);

int Dimensione(ListaDiElem lista);
int DimensioneRic(ListaDiElem lista);

int VerificaPresenza(ListaDiElem lista, TipoElemento elem);
int VerificaPresenzaRic(ListaDiElem lista, TipoElemento elem);
int ContaOccorrenze(ListaDiElem lista, TipoElemento elem);
int ContaOccorrenzeRic(ListaDiElem lista, TipoElemento elem);

ListaDiElem InsInTesta(ListaDiElem lista, TipoElemento elem);
ListaDiElem InsInFondo(ListaDiElem lista, TipoElemento elem);
ListaDiElem InsInFondoRic(ListaDiElem lista, TipoElemento elem);
ListaDiElem InsInOrd(ListaDiElem lista, TipoElemento elem);
ListaDiElem InsInOrdRic(ListaDiElem lista, TipoElemento elem);

ListaDiElem CancellaUno(ListaDiElem lista, TipoElemento elem);
ListaDiElem CancellaUnoRic(ListaDiElem lista, TipoElemento elem);
ListaDiElem CancellaTutti(ListaDiElem lista, TipoElemento elem);
ListaDiElem CancellaTuttiRic(ListaDiElem lista, TipoElemento elem);

/* Seconda meta' */

void VisualizzaLista(ListaDiElem lista);
void VisualizzaListaRovesciata(ListaDiElem lista);

void DistruggiLista(ListaDiElem lista);
void DistruggiListaRic(ListaDiElem lista);

ListaDiElem InvertiClonando(ListaDiElem lista, int keepSource);
ListaDiElem InvertiRiusando(ListaDiElem lista);
ListaDiElem InvertiRiusandoRic(ListaDiElem lista);

ListaDiElem OrdinaCrescente(ListaDiElem lista);
ListaDiElem OrdinaCrescenteRic(ListaDiElem lista);

int sum(ListaDiElem lista);
int sumRic(ListaDiElem lista);

int min(ListaDiElem lista);
int max(ListaDiElem lista);
int minRic(ListaDiElem lista);
int maxRic(ListaDiElem lista);

float avg(ListaDiElem lista);
float avgRic(ListaDiElem lista);

ListaDiElem EliminaDuplicati(ListaDiElem lista);
ListaDiElem EliminaDuplicatiRic(ListaDiElem lista);

/*************************************************************
                     IMPLEMENTAZIONE
*************************************************************/

void todo() {
  printf("\n ***********************************************\n");
  printf(" **       FUNZIONE  NON  IMPLEMENTATA !       **\n");
  printf(" ***********************************************\n ");
}

ListaDiElem Inizializza(void) {
  return NULL;
}

int ListaVuota(ListaDiElem lista) {
  return lista == NULL;
}

ListaDiElem InsInTesta(ListaDiElem lista, TipoElemento elem) {
  ListaDiElem punt;
  punt = (ListaDiElem)malloc(sizeof(ElemLista));
  punt->info = elem;
  punt->prox = lista;
  return punt;
}

int Dimensione(ListaDiElem lista) {
  int count = 0;
  while (!ListaVuota(lista)) {
    lista = lista->prox;
    count++;
  }
  return count;
}

int DimensioneRic(ListaDiElem lista) {
  if (lista)
    return 1 + DimensioneRic(lista->prox);
  return 0;
}

int VerificaPresenza(ListaDiElem lista, TipoElemento elem) {
  ListaDiElem cur = lista;
  while (cur != NULL) {
    if (cur->info == elem) {
      return 1;
    }

    cur = cur->prox;
  }

  return 0;
}

int VerificaPresenzaRic(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL)
    return 0;

  if (lista->info == elem)
    return 1;

  return VerificaPresenzaRic(lista->prox, elem);
}

int ContaOccorrenze(ListaDiElem lista, TipoElemento elem) {
  int count = 0;

  ListaDiElem cur = lista;
  while (cur != NULL) {
    if (cur->info == elem) {
      count++;
    }

    cur = cur->prox;
  }

  return count;
}

int ContaOccorrenzeRic(ListaDiElem lista, TipoElemento elem) {
  return lista && ((lista->info == elem) + VerificaPresenzaRic(lista->prox, elem));
}

ListaDiElem InsInFondo(ListaDiElem lista, TipoElemento elem) {
  ListaDiElem ptr = (ListaDiElem)malloc(sizeof(ElemLista));
  ptr->info = elem;
  ptr->prox = NULL;

  if (lista == NULL) {
    return ptr;
  }

  ListaDiElem cur = lista;
  while (cur->prox != NULL) {
    cur = cur->prox;
  }
  cur->prox = ptr;

  return lista;
}

ListaDiElem InsInFondoRic(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL) {
    ListaDiElem ptr = (ListaDiElem)malloc(sizeof(ElemLista));
    ptr->info = elem;
    ptr->prox = NULL;

    return ptr;
  }

  lista->prox = InsInFondo(lista->prox, elem);

  return lista;
}

ListaDiElem InsInOrd(ListaDiElem lista, TipoElemento elem) {
  ListaDiElem ptr = (ListaDiElem)malloc(sizeof(ElemLista));
  ptr->info = elem;
  ptr->prox = NULL;

  if (lista == NULL) {
    return ptr;
  }

  ListaDiElem cur = lista;
  ListaDiElem next = lista->prox;
  while (next != NULL && next->info < elem) {
    cur = cur->prox;
    next = next->prox;
  }

  cur->prox = ptr;
  ptr->prox = next;

  return lista;
}

ListaDiElem InsInOrdRic(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL || lista->info > elem) {
    ListaDiElem ptr = (ListaDiElem)malloc(sizeof(ElemLista));
    ptr->info = elem;
    ptr->prox = lista;

    return ptr;
  }

  lista->prox = InsInOrdRic(lista->prox, elem);
  return lista;
}

ListaDiElem CancellaUno(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL) {
    return lista;
  }

  if (lista->info == elem) {
    ListaDiElem tail = lista->prox;
    free(lista);
    return tail;
  }

  ListaDiElem cur = lista;
  ListaDiElem next = lista->prox;
  while (next != NULL && next->info != elem) {
    cur = cur->prox;
    next = next->prox;
  }

  // Se sono arrivato alla fine (NEXT == NULL) significa che non ho trovato
  // l'elemento da cancellare, e quindi non devo fare nulla
  if (next != NULL) {
    ListaDiElem tail = next->prox;
    free(next);
    cur->prox = tail;
  }

  return lista;
}

ListaDiElem CancellaUnoRic(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL) {
    return lista;
  }

  if (lista->info == elem) {
    ListaDiElem tail = lista->prox;
    free(lista);
    return tail;
  }

  lista->prox = CancellaUnoRic(lista->prox, elem);
  return lista;
}

ListaDiElem CancellaTutti(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL) {
    return lista;
  }

  if (lista->info == elem) {
    ListaDiElem tail = lista->prox;
    free(lista);
    lista = tail;
  }

  ListaDiElem cur = lista;
  while (cur != NULL && cur->prox != NULL) {
    if (cur->prox->info == elem) {
      ListaDiElem tail = cur->prox->prox;
      free(cur->prox);
      cur->prox = tail;
    }

    cur = cur->prox;
  }

  return lista;
}

ListaDiElem CancellaTuttiRic(ListaDiElem lista, TipoElemento elem) {
  if (lista == NULL) {
    return lista;
  }

  if (lista->info == elem) {
    ListaDiElem tail = lista->prox;
    free(lista);
    lista = tail;
  }

  lista->prox = CancellaUnoRic(lista->prox, elem);
  return lista;
}

void DistruggiLista(ListaDiElem lista) {
  if (lista == NULL) {
    return;
  }

  ListaDiElem cur = lista;

  while (cur != NULL) {
    ListaDiElem tail = cur->prox;
    free(cur);
    cur = tail;
  }
}

void DistruggiListaRic(ListaDiElem lista) {
  if (lista == NULL) {
    return;
  }

  DistruggiListaRic(lista->prox);
  free(lista);
}

void VisualizzaLista(ListaDiElem lista) {
  if (ListaVuota(lista))
    printf(" --/\n");
  else if (ListaVuota(lista->prox))
    printf(" %d --/\n", lista->info);
  else {
    printf(" %d -->", lista->info);
    VisualizzaLista(lista->prox);
  }
}

void VisualizzaListaRovesciata(ListaDiElem lista) {
  if (ListaVuota(lista))
    printf(" /-- ");
  else if (ListaVuota(lista->prox))
    printf(" /-- %d", lista->info);
  else {
    VisualizzaListaRovesciata(lista->prox);
    printf(" <-- %d", lista->info);
  }
}

/* Se keepsource � 1 conserva la lista originale, se � 0 la dealloca */
ListaDiElem InvertiClonando(ListaDiElem lista, int keepSource) {
  ListaDiElem invertita = Inizializza();

  ListaDiElem cur = lista;
  while (cur != NULL) {
    lista = InsInTesta(lista, cur->info);
    cur = cur->prox;
  }

  if (!keepSource) {
    DistruggiLista(invertita);
  }

  return invertita;
}

ListaDiElem InvertiRiusando(ListaDiElem lista) {
  // lista vuota
  if (lista == NULL) {
    return lista;
  }

  // lista di 1 elemento
  if (lista->prox == NULL) {
    return lista;
  }

  ListaDiElem prev = NULL;
  ListaDiElem cur = lista;
  ListaDiElem succ = cur->prox;

  while (succ != NULL) {
    ListaDiElem curCopy = cur;
    cur->prox = prev;

    prev = curCopy;
    cur = succ;
    succ = succ->prox;
  }
  cur->prox = prev;  // collega l'ultimo

  return cur;
}

// funzione helper per InvertiRiusandoRic
ListaDiElem CollegaInFondoRic(ListaDiElem a, ListaDiElem b) {
  if (a == NULL) {
    return b;
  }

  a->prox = CollegaInFondoRic(a->prox, b);
  return a;
}

ListaDiElem InvertiRiusandoRic(ListaDiElem lista) {
  // caso base: lista vuota
  if (lista == NULL) {
    return lista;
  }

  // passo induttivo: inverti la coda
  ListaDiElem coda = InvertiRiusandoRic(lista->prox);

  // stacca la testa e riattaccala in fondo alla coda invertita
  ListaDiElem testa = lista;
  testa->prox = NULL;
  lista = CollegaInFondoRic(coda, lista);

  return lista;
}

// Qui ho un po' imbrogliato perchè creo un'altra lista dove inserisco le cose
// in ordine
ListaDiElem OrdinaCrescente(ListaDiElem lista) {
  ListaDiElem sorted = Inizializza();

  ListaDiElem cur = lista;
  while (cur != NULL) {
    InsInOrd(sorted, cur->info);
    cur = cur->prox;
  }

  DistruggiLista(lista);

  return sorted;
}

// Funzione helper per OrdinaCrescenteRic che inserisce una testa in ordine in
// una lista.
// NOTA: questa funzione se ne frega di cosa c'è attaccato dopo la testa, per
// l'uso che ne faccio non è un problema ma in altri casi potrebbe creare
// garbage.
ListaDiElem CollegaTestaInOrdineRic(ListaDiElem lista, ListaDiElem testa) {
  if (lista == NULL || lista->info > testa->info) {
    testa->prox = lista;
    return testa;
  }

  lista->prox = CollegaTestaInOrdineRic(lista->prox, testa);
  return lista;
}

ListaDiElem OrdinaCrescenteRic(ListaDiElem lista) {
  // caso base: 0 elementi
  if (lista == NULL) {
    return lista;
  }

  // caso base: 1 elemnto
  if (lista->prox == NULL) {
    return lista;
  }

  // passo induttivo: ordina la coda
  ListaDiElem codaOrdinata = OrdinaCrescenteRic(lista->prox);

  // metti la testa nel posto giusto nella coda
  ListaDiElem listaOrdinata = CollegaTestaInOrdineRic(codaOrdinata, lista);

  return listaOrdinata;
}

ListaDiElem EliminaDuplicati(ListaDiElem lista) {
  ListaDiElem cur = lista;
  while (cur != NULL) {
    cur->prox = CancellaTutti(cur->prox, cur->info);
    cur = cur->prox;
  }

  return lista;
}

/* Questa, forse, non è proprio immediata da comprendere... ma è indubbiamente
 * elegante... è in omaggio, ma solo perché è appena passato il black friday :)
 */
ListaDiElem EliminaDuplicatiRic(ListaDiElem lista) {
  if (!ListaVuota(lista))
    lista->prox =
        EliminaDuplicatiRic(CancellaTuttiRic(lista->prox, lista->info));
  return lista;
}

int sum(ListaDiElem lista) {
  int sum = 0;

  ListaDiElem cur = lista;
  while (cur != NULL) {
    sum += cur->info;
    cur = cur->prox;
  }

  return lista->info;
}

int sumRic(ListaDiElem lista) {
  if (lista == NULL) {
    return 0;
  }

  return lista->info + sumRic(lista->prox);
}

int min(ListaDiElem lista) {
  if (lista == NULL) {
    return 0;
  }

  int min = lista->info;
  ListaDiElem cur = lista;
  while (cur != NULL) {
    if (cur->info < min) {
      min = cur->info;
    }

    cur = cur->prox;
  }

  return min;
}

int max(ListaDiElem lista) {
  if (lista == NULL) {
    return 0;
  }

  int max = lista->info;
  ListaDiElem cur = lista;
  while (cur != NULL) {
    if (cur->info > max) {
      max = cur->info;
    }

    cur = cur->prox;
  }

  return max;
}

int minRic(ListaDiElem lista) {
  if (lista == NULL) {
    return 0;
  }

  int minCoda = min(lista->prox);
  return minCoda < lista->info ? minCoda : lista->info;
}

int maxRic(ListaDiElem lista) {
  if (lista == NULL) {
    return 0;
  }

  int maxCoda = min(lista->prox);
  return maxCoda > lista->info ? maxCoda : lista->info;
}

/* in omaggio! */
float avg(ListaDiElem lista) {
  return (float)sum(lista) / Dimensione(lista);
}

float avgRic(ListaDiElem lista) {
  return (float)sumRic(lista) / DimensioneRic(lista);
}
