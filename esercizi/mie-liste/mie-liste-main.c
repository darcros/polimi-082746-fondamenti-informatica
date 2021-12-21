#include <stdio.h>

#include "./mie-liste.h"

int ric = 0;

char menu() {
  char x;

  printf("\n");
  printf("\n 0 : cambia modo        (ora: %s)",
         ric ? "ricorsivo" : "iterativo");
  printf("\n 1 : inserisci in testa");
  printf("\n 2 : inserisci in coda");
  printf("\n 3 : cancella prima occorrenza");
  printf("\n 4 : cancella ogni occorrenza");
  printf("\n 5 : inserisci in ordine");
  printf("\n 6 : inverti (riusando i nodi)");
  printf("\n 7 : conta nodi");
  printf("\n 8 : riordina");
  printf("\n 9 : distruggi tutto");
  printf("\n a : verifica presenza");
  printf("\n b : conta occorrenze");
  printf("\n c : elimina duplicati");
  printf("\n d : somma dei valori");
  printf("\n e : trova max e min");
  printf("\n f : valor medio");
  printf("\n");

  scanf("%c", &x);
  if (x == '\n')
    scanf("%c", &x);

  return x;
}

int main() {
  int val, v1, v2;
  ListaDiElem l1;

  /* Iniziamo con una lista non vuota */
  l1 = InsInTesta(InsInTesta(InsInTesta(InsInTesta(Inizializza(), 13), 9), 7),
                  5);

  char scelta;
  do {
    printf("\n\n  ");
    VisualizzaLista(l1);
    scelta = menu();

    switch (scelta) {
      case '0':
        ric = !ric;
        break;
      case '1':
        printf("\n Val da inserire in testa : ");
        scanf("%d", &val);
        l1 = InsInTesta(l1, val);
        break;
      case '2':
        printf("\n Val da inserire in coda : ");
        scanf("%d", &val);
        if (ric)
          l1 = InsInFondoRic(l1, val);
        else
          l1 = InsInFondo(l1, val);
        break;
      case '3':
        printf("\n Val di cui eliminare la prima occ. : ");
        scanf("%d", &val);
        if (ric)
          l1 = CancellaUnoRic(l1, val);
        else
          l1 = CancellaUno(l1, val);
        break;
      case '4':
        printf("\n Val di cui eliminare TUTTE le occ. : ");
        scanf("%d", &val);
        if (ric)
          l1 = CancellaTuttiRic(l1, val);
        else
          l1 = CancellaTutti(l1, val);
        break;
      case '5':
        printf("\n Val da inserire : ");
        scanf("%d", &val);
        if (ric)
          l1 = InsInOrdRic(l1, val);
        else
          l1 = InsInOrd(l1, val);
        break;
      case '6':
        if (ric)
          l1 = InvertiRiusandoRic(l1);
        else
          l1 = InvertiRiusando(l1);
        break;
      case '7':
        if (ric)
          printf("\n i nodi sono: %d", DimensioneRic(l1));
        else
          printf("\n i nodi sono: %d", Dimensione(l1));
        break;
      case '8':
        if (ric)
          l1 = OrdinaCrescenteRic(l1);
        else
          l1 = OrdinaCrescente(l1);
        break;
      case '9':
        if (ric)
          DistruggiListaRic(l1);
        else
          DistruggiLista(l1);
        l1 = Inizializza();
        printf(
            "\n  [ ATTENZIONE: se la deallocazione non e' implementata... hai "
            "appena prodotto garbage! ]\n");
        break;
      case 'a':
        printf("\n Val da cercare : ");
        scanf("%d", &val);
        if (ric)
          val = VerificaPresenzaRic(l1, val);
        else
          val = VerificaPresenza(l1, val);
        printf("\n Valore%s presente nella lista", val ? "" : " NON");
        break;
      case 'b':
        printf("\n Val da cercare : ");
        scanf("%d", &val);
        if (ric)
          val = ContaOccorrenzeRic(l1, val);
        else
          val = ContaOccorrenze(l1, val);
        printf("\n Valore presente  %d  volt%s\n", val, val == 1 ? "a" : "e");
        break;
      case 'c':
        if (ric)
          l1 = EliminaDuplicatiRic(l1);
        else
          l1 = EliminaDuplicati(l1);
        break;
      case 'd':
        if (ListaVuota(l1))
          v1 = 0;
        else if (ric)
          v1 = sumRic(l1);
        else
          v1 = sum(l1);
        printf("\n   somma dei valori = %d   \n", ric ? sumRic(l1) : sum(l1));
        break;
      case 'e':
        if (ListaVuota(l1))
          printf("\n   In una lista vuota min e max non sono definiti! \n");
        else {
          if (ric) {
            v1 = maxRic(l1);
            v2 = minRic(l1);
          } else {
            v1 = max(l1);
            v2 = min(l1);
          }
          printf("\n   min = %d        max = %d \n", v1, v2);
        }
        break;
      case 'f':
        if (ListaVuota(l1))
          printf("\n   In una lista vuota la media non e' definita! \n");
        else
          printf("\n   media = %.2f   \n", ric ? avgRic(l1) : avg(l1));
        break;
    }
  } while (1);

  return 0;
}
