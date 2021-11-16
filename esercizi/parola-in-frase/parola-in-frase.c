#include <stdio.h>
#include <string.h>

#define NF 200
#define NP 30

/*
  Sformatino di castagne e pistacchi
*/

char toLowerCase(char c) {
  if (c >= 'A' && c <= 'Z')
    return c + ('a' - 'A');

  return c;
}

int isWordChar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int pif(char* frase, char* parola) {
  int len = strlen(parola);
  int i = 0;
  int j = 0;

  // scorro tutta la frase
  while (frase[i] != '\0') {
    char prev = i == 0 ? '\0' : toLowerCase(frase[i - 1]);
    char next = toLowerCase(frase[i + 1]);
    char cf = toLowerCase(frase[i]);
    char cp = toLowerCase(parola[j]);

    // Per poter incrementare il contatore dei caratteri che combaciano:
    // 1. il carattere della frase e della parola devono combaciare
    // 2. dobbiamo essere
    //   - o dentro a una parola
    //   - o all'inizoi di una parola
    if (cf == cp && (j > 0 || (isWordChar(cf) && !isWordChar(prev)))) {
      j++;
    } else {
      // se i caratteri non cambaciano, resetto il contatore dei match
      j = 0;
    }

    // l'intera parola combacia
    if (j == len) {
      // se questa è la fine della parola: parola trovata per intero e da sola, FINE
      if (isWordChar(cf) && !isWordChar(next)) {
        return 1;
      }

      // ... altrimenti resetto il contatore dei match
      j = 0;
    }

    i++;
  }

  return 0;
}

int main() {
  char frase[NF], parola[NP];

  strcpy(frase, "Sformatino di castagne e pistacchi");
  printf("\n  La frase : %s\n", frase);
  strcpy(parola, "castagne");
  printf(" '%s' %se' contenuta nella frase\n", parola,
         pif(frase, parola) ? "" : "NON ");
  strcpy(parola, "Sforma");
  printf(" '%s' %se' contenuta nella frase\n", parola,
         pif(frase, parola) ? "" : "NON ");
  strcpy(parola, "tacchi");
  printf(" '%s' %se' contenuta nella frase\n", parola,
         pif(frase, parola) ? "" : "NON ");
  strcpy(parola, "PIstACchi");
  printf(" '%s' %se' contenuta nella frase\n", parola,
         pif(frase, parola) ? "" : "NON ");
  strcpy(parola, "asta");
  printf(" '%s' %se' contenuta nella frase\n", parola,
         pif(frase, parola) ? "" : "NON ");

  while (1) {
    printf("\n La frase : ");
    gets(frase);
    while (strcmp(parola, "stop")) {
      printf("\n   Una parola : ");
      scanf("%s", parola);
      printf("      '%s' %se' contenuta nella frase\n", parola,
             pif(frase, parola) ? "" : "NON ");
    }
    strcpy(parola, "foo");
    fflush(stdin);
  }

  return 0;
}
