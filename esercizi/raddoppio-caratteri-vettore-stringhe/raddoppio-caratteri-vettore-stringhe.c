#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

char* raddoppia_singolo(char* s, char c) {
  int newLen = 0;
  int i = 0;
  while (s[i] != '\0') {
    newLen += s[i] != c ? 1 : 2;
    i++;
  }
  newLen++;  // spazio per '\n'

  char* raddoppiato = (char*)malloc(newLen);
  i = 0;
  int j = 0;
  while (s[i] != '\0') {
    if (s[i] != c) {
      raddoppiato[j] = s[i];
      j += 1;
    } else {
      raddoppiato[j] = s[i];
      raddoppiato[j + 1] = s[i];
      j += 2;
    }

    i++;
  }
  raddoppiato[newLen] = '\0';

  return raddoppiato;
}

void raddoppia(char* src[], char* dst[], int len, char c) {
  for (int i = 0; i < len; i++) {
    dst[i] = raddoppia_singolo(src[i], c);
  }
}

void print(char* v[], int dim) {
  int i;
  for (i = 0; i < dim; i++)
    printf(" %12s", v[i]);
  printf("\n");
}

int main() {
  char *sorgente[N] = {"Casa", "Scuola", "Macchina", "Bicicletta"},
       *destinazione[N] = {0};

  print(sorgente, N);
  raddoppia(sorgente, destinazione, N, 'c');
  print(destinazione, N);

  return 0;
}
