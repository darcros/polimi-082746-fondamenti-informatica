#include <stdio.h>
#include <string.h>

#define N 30

/*
  Da copiare e incollare invece di ridigitarle ogni volta:

  La banana assomiglia assai alla patata ma poco all' ananas .
  Tutti sapevano che anna aveva otto radar ma pochi la onorarono !
  Tutti sapevano che il nonno di Anna aveva otto radar ma pochi lo onorarono !

*/

int paln(char* par, int len) {
  for (int i = 0; i < len / 2; i++) {
    if (par[i] != par[len - 1 - i])
      return 0;
  }

  return 1;
}

int pal(char* par) {
  return paln(par, strlen(par));
}

int pal_tra(char* par) {
  int len = strlen(par) - 1;

  return paln(par, len) || paln(par + 1, len);
}

int main() {
  int p = 0, pt = 0, lun = 4;
  char parola[N] = "init";

  printf("\n Digita una frase\n  ");

  while (lun > 1) {
    scanf("%s", parola);
    lun = strlen(parola);
    if (lun > 2)
      if (pal(parola)) {
        p++;
        printf("  %s e' palindroma\n", parola);
      } else if (pal_tra(parola)) {
        pt++;
        printf("  %s e' palindroma con trasporto\n", parola);
      }
  }
  printf(
      "\n Hai digitato in totale %d parol%s palindrom%s propri%s e %d con "
      "trasporto\n",
      p, p == 1 ? "a" : "e", p == 1 ? "a" : "e", p == 1 ? "a" : "e", pt);

  return 0;
}
