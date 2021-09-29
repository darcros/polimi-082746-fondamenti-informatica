#include <stdio.h>

int main() {
  int n;

  printf("Inserisci un numero intero positivo: ");
  scanf("%d", &n);

  printf("I divisori propri di %d sono:", n);
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      printf(" %d", i);
    }
  }
  printf("\n");

  return 0;
}
