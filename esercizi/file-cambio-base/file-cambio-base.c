#include <stdio.h>
#include <string.h>

/*
ESERCIZIO:
Un file testuale memorizza ”a parole” una sequenza di interi positivi, con la
seguente convenzione:
- Ogni riga rappresenta un intero, le cui cifre sono espresse "a parole" - Ogni
riga `e terminata dalla stringa "***"
- Le cifre si riferiscono alla codifica in base cinque degli interi.

Ad esempio, il file:
uno uno tre ***
uno zero ***
due quattro ***
uno tre zero uno ***

esprime ”a parole” gli interi 113(5), 10(5), 24(5), e 1301(5), che corrispondono
rispettivamente a 33dec, 5dec, 14dec e 201dec in base dieci.

Si scriva un programma C che riceve come parametro da linea di comando il nome
del file da analizzare, ne interpreta il contenuto ”ricostruendo” gli interi ivi
rappresentati ”a parole”, e ne stampa la media su stdout (in base dieci). Nel
caso del file d’esempio (dove 33+5+14+201=253) il programma stamperà 63,25.
*/

// la parola più lunga è "quattro" che contiene 8 caratteri (7 lettere e il \0)
#define WORD_MAX_LEN 8
#define LINE_END "***"

int wordToDigit(char* s) {
  char* digits[] = {"zero",   "uno", "due",   "tre",  "quattro",
                    "cinque", "sei", "sette", "otto", "nove"};

  for (int i = 0; i < 10; i++) {
    if (strcmp(s, digits[i]) == 0) {
      return i;
    }
  }

  return -1;
}

int readLine(FILE* fp) {
  int n = 0;
  char word[8];

  while (fscanf(fp, "%s", word) != EOF) {
    if (strcmp(word, LINE_END) == 0) {
      return n;
    }

    int digit = wordToDigit(word);
    n = n * 10 + digit;
  }

  return EOF;
}

int toBase10(int n, int fromBase) {
  int base10 = 0;
  int pow = 1;

  while (n > 0) {
    int cifra = n % 10;
    base10 += cifra * pow;
    pow *= fromBase;

    n = n / 10;
  }

  return base10;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Utilizzo corretto: %s [percorso file]\n", argv[0]);
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Impossibile aprire il file");
    return 1;
  }

  int n;
  int i = 0;
  int tot;

  while ((n = readLine(fp)) != EOF) {
    int base10 = toBase10(n, 5);
    printf("%d(5) -> %d(10)\n", n, base10);  // printf solo per motivi di debug
    tot += base10;
    i++;
  }

  double avg = (double)tot / i;
  printf("la media è: %f\n", avg);

  return 0;
}
