#include <stdio.h>

#define N 5

// void printMat(int mat[N][N]) {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       printf("%3d ", mat[i][j]);
//     }
//     printf("\n\n");
//   }
// }

void printMat(int mat[N][N]) {
  // stampa riga in alto
  printf("┌");
  for (int j = 0; j < N; j++) {
    printf("───");

    if (j != N - 1)
      printf("┬");
  }
  printf("┐\n");

  // stampa righe dei numeri
  for (int i = 0; i < N; i++) {
    // stampa riga di numeri
    printf("│");
    for (int j = 0; j < N; j++) {
      printf("%3d│", mat[i][j]);
    }
    printf("\n");

    // stampa riga orizzontale
    if (i != N - 1) {
      printf("├");
      for (int j = 0; j < N; j++) {
        printf("───");

        if (j != N - 1)
          printf("┼");
      }
      printf("┤\n");
    }
  }

  // stampa riga finale
  // stampa riga in alto
  printf("└");
  for (int j = 0; j < N; j++) {
    printf("───");

    if (j != N - 1)
      printf("┴");
  }
  printf("┘\n");
}

int main() {
  int mat[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int index = i * N + j;
      mat[i][j] = index + 1;
    }
  }

  printf("matrice iniziale:\n");
  printMat(mat);

  int r, c;
  printf("inserisci r: ");
  scanf("%d", &r);
  printf("inserisci c: ");
  scanf("%d", &c);

  if (r < 0 || c < 0 || r >= N || c >= N) {
    printf("indici fuori dalla matrice");
    return 1;
  }

  int k = mat[r][c];
  int kIndex = r * N + c;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == r && i != c) {
        mat[i][j] = 2 * k;
      } else {
        int index = i * N + j;

        if (index < kIndex)
          mat[i][j] += k;
        else
          mat[i][j] -= k;
      }
    }
  }

  printf("matrice modificata:\n");
  printMat(mat);

  return 0;
}
