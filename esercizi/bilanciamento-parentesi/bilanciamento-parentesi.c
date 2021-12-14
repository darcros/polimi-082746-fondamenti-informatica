#include <stdio.h>
#include <stdlib.h>

/********************************************
   Definizione della pila e delle sue funzioni
*********************************************/
typedef struct sNode {
  char simbolo;
  struct sNode* nextPtr;
} StackNode;

typedef StackNode* StackNodePtr;

/* In questa versione, la pila è passata per indirizzo */
void push(StackNodePtr*, char);
char pop(StackNodePtr*);
int isEmpty(StackNodePtr);
StackNodePtr init(void);

/********************************************
   Analisi della sequenza di caratteri
*********************************************/

/* SI SCRIVA IL CODICE DELLA FUNZIONE check() */

int check(char* sequenza, StackNodePtr* pila) {
  /* ... */

  int i = 0;
  while (sequenza[i] != '\0') {
    switch (sequenza[i]) {
      case '(':
        push(pila, ')');
        break;

      case '[':
        push(pila, ']');
        break;

      case '{':
        push(pila, '}');
        break;

      case ')':
      case ']':
      case '}':
        if (isEmpty(pila)) {
          return 0;
        }

        char expected = pop(pila);
        if (sequenza[i] != expected) {
          return 0;
        }
        break;

      default:
        printf("Carattere sconosciuto: %c", sequenza[i]);
        break;
    }

    i++;
  }

  return isEmpty(pila);
}

/* Non fa altro che inizializzare la pila e invocare la funzione di analisi */

int analizza(char* sequenza) {
  StackNodePtr snp = init();  // inizializza la pila
  return check(sequenza, &snp);
}

int main() {
  char x, line[100];  // sequenza digitata da verificare

  printf("\n Analizziamo sequenze di parentesi inserite da stdin\n  ");
  do {
    printf(
        "\n Digitare le sequenze di simboli da analizzare (\"end\" per "
        "finire)\n\n  ");
    fgets(line, 100, stdin);
    printf("\n Simboli %sbilanciati\n\n", analizza(line) ? "" : "NON ");
  } while (strcmp(line, "end\n"));

  return 0;
}

/*************************************
 gestione della pila presa dalle slide
 *************************************/

void push(StackNodePtr* topPtr, char simb) {
  StackNodePtr newPtr;
  newPtr = (StackNodePtr)malloc(sizeof(StackNode));
  if (newPtr != NULL) {
    newPtr->simbolo = simb;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  } else
    printf("%d not inserted. No memory available.\n", simb);
}

char pop(StackNodePtr* topPtr) {
  StackNodePtr tempPtr = *topPtr;
  char popValue = (*topPtr)->simbolo;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue;
}

int isEmpty(StackNodePtr topPtr) {
  return topPtr == NULL;
}

StackNodePtr init(void) {
  return NULL;
}