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

// migliorabile usando il setaccio di Eratostene
bool is_prime(int n) {
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  printf(
      "Coppie di numeri affiatati con 2 cifre, in cui il numero maggiore è "
      "primo:\n");

  for (int i = 0; i <= 99; i++) {
    for (int j = i + 1; j <= 99; j++) {
      int sum = i + j;
      int product = digit_product(i) * digit_product(j);
      int max = i > j ? i : j;

      if (sum == product && is_prime(max)) {
        printf("(%d, %d)\n", i, j);
      }
    }
  }

  return 0;
}
