#include <stdio.h>

#define N 8
#define K 4

int ciclico(int*, int);

/* Questa funzione è giusta "per decreto"
  (l'esercizio era già stato assegnato in un lab precedente) */
int ciclicoIterativoGiustoPerDecreto(int v[], int dim) {
  int posizione = 0, passi = 0;
  while (posizione >= 0 && posizione < dim && passi <= dim) {
    posizione = v[posizione];
    passi++;
  }
  return passi > dim;
}

int main() {
  int test[K][N] = {{3, -3, 5, 6, 2, 4, 2, 11},
                    {5, -6, 7, 6, 2, 4, 2, -1},
                    {1, 2, 3, 4, 5, 6, 7, 0},
                    {1, 2, 3, 4, 5, 6, 7, 10}};
  int i, r, k;

  for (k = 0; k < K; k++) {
    r = ciclico(test[k], N);
    i = ciclicoIterativoGiustoPerDecreto(test[k], N);
    printf("\n%s (test[%d] %se' ciclico, %stu lo dichiari %sciclico)\n\n",
           i == r ? "   ok   " : "*ERRORE*", k, i ? "" : "NON ",
           i == r ? "e " : "*MA* ", r ? "" : "NON ");
  }

  return 0;
}

int ciclico_helper(int v[], int dim, int pos, int steps) {
  if (steps > dim)
    return 1;

  if (pos < 0 || pos > dim - 1)
    return 0;

  return ciclico_helper(v, dim, v[pos], steps + 1);
}

int ciclico(int v[], int dim) {
  return ciclico_helper(v, dim, 0, 0);
}