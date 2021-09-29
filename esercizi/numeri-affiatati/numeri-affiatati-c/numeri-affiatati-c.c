#include <stdbool.h>
#include <stdio.h>

int digit_product(int n) {
  int product = 1;

  do {
    int digit = n % 10;
    product *= digit;
    n /= 10;
  } while (n > 0);

  return product;
}

int main() {
  int n;
  printf("Inserisci la soglia: ");
  scanf("%d", &n);

  printf("Coppie di numeri affiatati minori di %d:\n", n);
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = i + j;
      int product = digit_product(i) * digit_product(j);

      if (sum == product) {
        printf("(%d, %d)\n", i, j);
      }
    }
  }

  return 0;
}
