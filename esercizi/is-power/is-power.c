#include <stdio.h>

int is_power(int n, int b) {
  // 1 è potenza di tutti i numeri perchè qualsiasi numero elevato a 0 fa 1
  if (n == 1)
    return 1;

  // nessun numero (tranne 1, ma lo abbiamo già controllato) è potenza di 1
  if (b == 1)
    return 0;

  if (n == 0 && b == 0)
    return 1;

  if (n == 0 || b == 0)
    return 0;

  return n % b == 0 && is_power(n / b, b);
}

int main() {
  int n, b;

  n = 8;
  b = 2;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 1;
  b = 2;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 1;
  b = 38;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 38;
  b = 1;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 0;
  b = 2;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 2;
  b = 0;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  n = 0;
  b = 0;
  printf("\n %3d %se' una potenza di %2d\n", n, is_power(n, b) ? "" : "NON ",
         b);

  return 0;
}