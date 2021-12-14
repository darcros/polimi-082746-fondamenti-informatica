#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cols, rows;  // Qui può avere senso che siano variabili globali...!!

char** leggiTabella(FILE* fp) {
  // carico la tabella di caratteri
  char** tabella = malloc(rows * sizeof(char));
  for (int i = 0; i < rows; i++) {
    // devo fare questa menata di allocare due stringhe per disfarmi del \0 che
    // sta alla fine della prima stringa, perchè in realtà la prima è una
    // stringa, la seconda è solo un array di char
    char* rigaStringaFile = malloc((cols + 1) * sizeof(char) + 1);
    char* rigaTabella = malloc(cols * sizeof(char));

    fscanf(fp, "%s", rigaStringaFile);
    memcpy(rigaTabella, rigaStringaFile, cols);
    free(rigaStringaFile);

    tabella[i] = rigaTabella;
  }
  return tabella;
}

void stampaTabella(char** tabella, int** maschera) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", maschera[i][j] ? '*' : tabella[i][j]);
    }
    printf("\n");
  }
}

int controllaCellaDirezione(char** tabella,
                            char* parola,
                            int cellX,
                            int cellY,
                            int dx,
                            int dy) {
  int i = 0;
  int x = cellX;
  int y = cellY;

  if (strcmp(parola, "ARMADIO") == 0 && dy == 1) {
    printf("a");
  }

  while (parola[i] != 0) {
    if (x < 0 || x >= cols || y < 0 || y >= rows) {
      return 0;
    }

    if (parola[i] != tabella[y][x]) {
      return 0;
    }

    x += dx;
    y += dy;
    i++;
  }

  return 1;
}

void cancellaParolaTovata(int** maschera,
                          char* parola,
                          int cellX,
                          int cellY,
                          int dx,
                          int dy) {
  int i = 0;
  int x = cellX;
  int y = cellY;

  while (parola[i] != 0) {
    if (x < 0 || x >= cols || y < 0 || y >= rows) {
      return;
    }

    maschera[y][x] = 1;

    x += dx;
    y += dy;
    i++;
  }
}

int cercaParola(char** tabella, char* parola, int** maschera) {
  // controlla ogni cella
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      // controlla ogni direzione
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx == 0 && dy == 0)  // non avrebbe senso controllare qusta
            continue;

          int trovata = controllaCellaDirezione(tabella, parola, x, y, dx, dy);
          if (trovata) {
            // segna sulla maschera che abbiamo trovato la parola
            cancellaParolaTovata(maschera, parola, x, y, dx, dy);
            return 1;
          }
        }
      }
    }
  }

  return 0;
}

int main() {
  int maxdim;
  FILE* fp;

  fp = fopen("crucipuzzle.txt", "r");
  if (fp == NULL) {
    printf("\n\n  ERRORE FILE \n\n");
    return 1;
  }

  fscanf(fp, "%d%d", &rows, &cols);
  if (rows > cols)
    maxdim = rows;
  else
    maxdim = cols;

  printf("\n  Rows: %d   Cols: %d   Maxdim: %d \n", rows, cols, maxdim);

  char** tabella = leggiTabella(fp);

  // creo maschera per tenere traccia di quali caratteri sono stati cancellati
  int** maschera = malloc(rows * sizeof(int));
  for (int i = 0; i < rows; i++) {
    maschera[i] = calloc(cols, sizeof(int));
  }

  printf("\n\n=== TABELLA ===\n");
  stampaTabella(tabella, maschera);
  printf("\n\n");

  // cotrollo tutte le parole
  char* parola = malloc(maxdim * sizeof(char) + 1);
  while (fscanf(fp, "%s", parola) != EOF) {
    printf("controllo la parola: '%s': ", parola);
    int trovata = cercaParola(tabella, parola, maschera);
    if (trovata) {
      printf("trovata\n");
    } else {
      printf("non trovata\n");
    }
  }
  free(parola);

  printf("\n\n=== SOLUZIONE DEL CRUCIPUZZLE ===\n");
  stampaTabella(tabella, maschera);

  printf("parola: ");
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (maschera[y][x] == 0) {
        printf("%c", tabella[y][x]);
      }
    }
  }
  printf("\n\n");

  return 0;
}
