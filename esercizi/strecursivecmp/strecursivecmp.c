#include <stdio.h>
#include <string.h>

int strecursivecmp(char* s1, char* s2) {
  if (*s1 < *s2)
    return -1;

  if (*s1 > *s2)
    return 1;

  // a questo punto s1 è uguale a s2, non serve controllare entrambi
  if (*s1 == '\0')
    return 0;

  return strecursivecmp(s1 + 1, s2 + 1);
}

int main() {
  int x, r;
  char p1[30], p2[30];

  printf("%s\n", strecursivecmp("zucca", "zucca") == 0 ? "    OK" : " ERRORE");
  printf("%s\n",
         strecursivecmp("zucca", "cenerentola") == 1 ? "    OK" : " ERRORE");
  printf("%s\n",
         strecursivecmp("cenerentola", "zucca") == -1 ? "    OK" : " ERRORE");
  printf("%s\n",
         strecursivecmp("Zucca", "cenerentola") == -1 ? "    OK" : " ERRORE");
  printf("%s\n",
         strecursivecmp("cenere", "cenerentola") == -1 ? "    OK" : " ERRORE");
  printf("%s\n",
         strecursivecmp("cenerentola", "cenere") == 1 ? "    OK" : " ERRORE");

  do {
    printf("\n\n  Parole da confrontare : ");
    scanf("%s%s", p1, p2);
    x = strcmp(p1, p2);
    r = strecursivecmp(p1, p2);
    printf("         strcmp( %s , %s ) = %d\n", p1, p2, x);
    printf(" strecursivecmp( %s , %s ) = %d  %s        \n", p1, p2, r,
           x == r ? "OK !" : "E R R O R E , O R R O R E !");
  } while (1);

  return 0;
}
