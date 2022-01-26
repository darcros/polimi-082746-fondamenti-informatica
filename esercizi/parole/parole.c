#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_whitespace(char c) {
  return c == ' ' || c == '\n';
}

char* find_start(char* s) {
  while (*s != '\0' && is_whitespace(*s)) {
    s++;
  }

  return s;
}

char* find_end(char* s) {
  while (*s != '\0' && !is_whitespace(*s)) {
    s++;
  }

  return s;
}

int stesse_parole(char* s1, char* s2) {
  char *start1, *start2, *end1, *end2;
  int l1, l2;

  start1 = find_start(s1);
  start2 = find_start(s2);

  end1 = find_end(start1);
  end2 = find_end(start2);

  while (*start1 != '\0' && *start2 != '\0') {
    l1 = end1 - start1;
    l2 = end2 - start2;

    if (l1 != l2) {
      return 0;
    }

    if (strncasecmp(start1, start2, l1) != 0) {
      return 0;
    }

    start1 = find_start(end1);
    start2 = find_start(end2);

    end1 = find_end(start1);
    end2 = find_end(start2);
  };

  return 1;
}

int main() {
  char* a1 = "Ciao  Come stai\n\nBeNIssimo";
  char* a2 = "\nCiao\nCome stai Benissimo";

  char* b1 = "Ciao  Comestai\n\nBeNIssimo";
  char* b2 = "\nCiao\nCome stai  Benissimo";

  int a = stesse_parole(a1, a2);
  int b = stesse_parole(b1, b2);

  printf("a:%d\n", a);
  printf("b:%d\n", b);

  return 0;
}
