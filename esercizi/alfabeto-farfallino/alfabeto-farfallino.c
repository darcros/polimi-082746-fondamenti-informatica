#include <stdio.h>

int main() {
  char c;

  do {
    scanf("%c", &c);

    // to lower case
    if (c >= 'A' && c <= 'Z')
      c += 'a' - 'A';

    switch (c) {
      case 'a':
        printf("afa");
        break;

      case 'e':
        printf("efe");
        break;

      case 'i':
        printf("ifi");
        break;

      case 'o':
        printf("ofo");
        break;

      case 'u':
        printf("ufu");
        break;

      default:
        printf("%c", c);
        break;
    }
  } while (c != '\n');

  return 0;
}
