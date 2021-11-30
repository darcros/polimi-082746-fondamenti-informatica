#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* conc_pars(char* s1, char* s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);

  // +1 per lasciare spazio per il \0 finale
  char* concat = (char*)malloc(l1 + l2 + 1);
  memcpy(concat, s1, l1);
  memcpy(concat + l1, s2, l2);

  return concat;
}

int main() {
  char p1[] = "Prima", p2[] = "Seconda";
  char x[] = "Buona", y[] = "Sera";
  char *par1, *par2;

  par1 = conc_pars(p1, p2);
  par2 = conc_pars(x, y);
  printf("\n Concatenazione : (%s) (%s)\n\n", par1, par2);
  free(par1);
  free(par2);

  return 0;
}
