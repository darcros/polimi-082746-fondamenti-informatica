#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// versione che SOSTITUISCE DIRETTAMENTE la stringa passata per indirizzo
void strmul(char** s, int n) {
  char* newStr = (char*)malloc(strlen(*s) * n + 1);
  newStr[0] = '\0';  // metto '/0' così newStr è stringa vuota

  for (int i = 0; i < n; i++) {
    strcat(newStr, *s);
  }

  free(*s);
  *s = newStr;
}

// versione ERRATA che restituisce una ALTRA NUOVA stringa (*non* è quello che
// si richiede)
char* strmulWRONG(char* s, int n) {
  char* ris = (char*)malloc(strlen(s) * n + 1);
  strcpy(ris, s);
  while (n-- > 1)
    strcat(ris, s);

  return ris;
}

int main() {
  char x[] = "Buona", y[] = "Sera";
  char *par1, *par2;

  strcpy(par1 = (char*)malloc(strlen(x) + 1), x);
  strcpy(par2 = (char*)malloc(strlen(y) + 1), y);

  par1 = strmulWRONG(par1,
                     3);  // ERRORE!!! Si produce garbage!! vero? dove? quale?

  strmul(&par2, 4);

  printf("\n Moltiplicazioni :\n    %s x %d ==> (%s)\n    %s x %d ==> (%s)\n\n",
         x, 3, par1, y, 4, par2);
  free(par1);
  free(par2);

  return 0;
}
