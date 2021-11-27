#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NF 200
#define NP 30

// Controlla se la prima stringa inizia con la seconda stringa
int startsWith(char* s1, char* s2) {
  // caso base: tute le stringhe iniziano con la stringa vuota
  if (*s2 == '\0')
    return 1;

  // caso base: abbiamo trovato due caratteri diversi
  if (tolower(*s1) != tolower(*s2))
    return 0;

  // passo induttivo: consumo un carattere da entrambe le stringhe e rimando il
  // controllo alla prossima chiamata
  return startsWith(s1 + 1, s2 + 1);
}

int pif(char* frase, char* parola) {
  // caso base: tutte le frasi contengono la parola vuota
  if (*parola == '\0')
    return 1;

  // caso base: abbiamo consumato tutta la frase e non abbiamo trovato la parola
  if (*frase == '\0')
    return 0;

  // caso base: la parola che cerchiamo è all'inizio della notra frase
  if (startsWith(frase, parola)) {
    // controlliamo anche che la parola che abbiamo trovato non sia parte di una
    // parola più grossa, quindi dobbiamo avere un carattere non alfabetico
    // prima e dopo la parola trovata
    char* fineMatch = frase + strlen(parola);
    if (!isalpha(*(frase - 1)) && !isalpha(*fineMatch)) {
      return 1;
    }

    // ottimizzazione: qui potremmo non fare nulla (tanto il passo induttivo che
    // c'è sotto farà avanzare di un carattere la ricerca) però  abbiamo già
    // controllato tramite la funzione startsWith() un numero di caratteri pari
    // alla lunghezza della parola, e quindi possiamo saltarli
    return pif(fineMatch, parola);
  }

  // passo induttivo: consumo un carattere e rimando il controllo alla prossima
  // chiamata
  return pif(frase + 1, parola);
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
