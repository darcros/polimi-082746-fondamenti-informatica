#include <stdbool.h>
#include <stdio.h>

int main() {
  int n;

  printf("Inserisci un numero n: ");
  scanf("%d", &n);

  for (int fattore = 2; fattore < n; fattore++) {
    // filtro solo numeri primi
    int primo = 1;
    for (int i = 2; i < fattore && primo; i++) {
      if (fattore % i == 0) {
        primo = 0;
      }
    }

    if (!primo) {
      continue;
    }

    // controllo se è divisore e divido
    if (n % fattore != 0) {
      continue;
    }

    int potenza = 0;
    while (n % fattore == 0) {
      n = n / fattore;
      potenza++;
    }

    if (potenza == 1) {
      printf("%d ", fattore);
    } else if (potenza > 1) {
      printf("%d^%d ", fattore, potenza);
    }
  }

  if (n != 1) {
    printf("%d ", n);
  }

  printf("\n");

  return 0;
}
