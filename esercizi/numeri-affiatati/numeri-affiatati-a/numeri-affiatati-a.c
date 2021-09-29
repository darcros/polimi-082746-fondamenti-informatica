#include <stdbool.h>
#include <stdio.h>

int digit_product(int n) {
  int product = 1;

  // printf("number: %d\n", n);
  do {
    int digit = n % 10;
    // printf("\tdigit: %d\n", digit);

    product *= digit;
    n /= 10;
  } while (n > 0);

  // printf("\tproduct: %d\n", product);
  return product;
}

int main() {
  printf("Coppie di numeri affiatati con 2 cifre:\n");

  for (int i = 0; i <= 99; i++) {
    for (int j = i + 1; j <= 99; j++) {
      int sum = i + j;
      int product = digit_product(i) * digit_product(j);

      if (sum == product) {
        printf("(%d, %d)\n", i, j);
      }
    }
  }

  return 0;
}
