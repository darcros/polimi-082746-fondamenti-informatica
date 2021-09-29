#include <stdio.h>

int main() {
  int anno;

  printf("Quale anno ti interessa? ");
  scanf("%d", &anno);

  if (anno < 1582) {
    printf("Anno NON bisestile");
  } else {
    if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0) {
      printf("Anno bisestile\n");
    } else {
      printf("Anno NON bisestile\n");
    }
  }

  return 0;
}
