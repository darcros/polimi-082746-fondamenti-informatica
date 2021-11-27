#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NF 200
#define NP 30

int startsWith(char* s1, char* s2) {
  int i = 0;
  while (s2[i] != '\0') {
    // Se la prima stringa è più corta della seconda
    if (s1[i] == '\0')
      return 0;

    if (tolower(s1[i]) != tolower(s2[i]))
      return 0;

    i++;
  }

  return 1;
}

int pif(char* frase, char* parola) {
  int len = strlen(parola);
  int i = 0;

  // Scorro tutta la frase
  while (frase[i] != '\0') {
    // Se siamo all'inizio di una parola
    if (isalpha(frase[i]) && (i == 0 || !isalpha(frase[i - 1]))) {
      // Se la parola che abbiamo trovato inizia con la parola che cerchiamo
      if (startsWith(&frase[i], parola)) {
        i += len;  // considero "consumata" la parte di frase che è stata
                   // matchata dal startsWith()

        // Se la parola che abbiamo trovato finisce subito dopo il match della
        // parola che cerchiamo, allora la parola che abbbiamo trovato è uguale
        // alla parola che cerchiamo
        if (isalpha(frase[i - 1]) && !isalpha(frase[i])) {
          return 1;
        }
      }
    }

    i++;
  }

  // sono arrivato alla fine della frase e non ho trovato nulla
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
