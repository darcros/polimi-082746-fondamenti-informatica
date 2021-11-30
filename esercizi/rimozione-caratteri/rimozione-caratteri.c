#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rimuovi(char*, char);

int main() {
  char p[] = "Esercizio semplice", q[] = "Esercizio SEMPLICE", frase[100];
  char c;
  char* nuova;

  c = 's';
  printf("\n Rimuovo '%c' da \"%s\" : ", c, p);
  nuova = rimuovi(p, c);
  printf("\"%s\"\n", nuova);
  free(nuova);

  c = 'I';
  printf("\n Rimuovo '%c' da \"%s\" : ", c, q);
  nuova = rimuovi(q, c);
  printf("\"%s\"\n", nuova);
  free(nuova);

  while (1) {
    printf("\n\n Dammi una frase da trattare : ");
    fflush(stdin); /* Svuoto il buffer per sicurezza */
    gets(frase);
    printf("\n e il carattere da togliere : ");
    fflush(stdin); /* Svuoto il buffer per sicurezza */
    scanf("%c", &c);

    nuova = rimuovi(frase, c);
    printf("\n Frase senza '%c' : \"%s\"\n", c, nuova);
    free(nuova); /* prima di continuare DEALLOCO la stringa vecchia (o diventa
                    garbage) */
  }

  return 0;
}

char* rimuovi(char* s, char c) {
  int newLen = 0;

  int i = 0;
  while (s[i] != '\0') {
    if (s[i] != c) {
      newLen++;
    }

    i++;
  }

  char* newString = (char*)malloc(newLen);

  i = 0;      // indice su s
  int j = 0;  // indice su newString
  while (s[i] != '\0') {
    if (s[i] != c) {
      newString[j] = s[i];
      j++;
    }

    i++;
  }

  return newString;
}
