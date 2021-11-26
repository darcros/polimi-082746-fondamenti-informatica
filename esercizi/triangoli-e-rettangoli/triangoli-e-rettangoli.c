#include <stdbool.h>
#include <stdio.h>

/*
  Margine di tolleranza per il controllo di uguaglianza sui float
*/
#define FLOAT_EPSILON 0.0001

/*
  Un punto sul piano cartesiano, definito dalle coordinate x e y
*/
typedef struct {
  float x;
  float y;
} point;

/*
  Un triangolo, formato da 3 punti.
*/
typedef point triangle[3];

/*
  Rappresenta il tipo di triangolo: equilateros, isoscele, scaleno.
*/
typedef enum {
  equilateral,
  isosceles,
  scalene,
} triangleType;

/*
  Un rettangolo con i lati paralleli agli assi, definito dal suo punto a
  nord-ovest e il suo punto a sud-est.
*/
typedef struct {
  point nw;  // north-west
  point se;  // south-east
} rectangle;

/*
  Restituisce quadrato della distanza.
  È più veloce che fare la radice quadrata e per comparare i lati va bene lo
  stesso.
*/
float distSquared(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

/*
  Dato un triangolo calcola la relazione tra i suoi lati.
*/
triangleType getTriangleType(triangle t) {
  float ab = distSquared(t[0], t[1]);
  float bc = distSquared(t[1], t[2]);
  float ca = distSquared(t[2], t[0]);

  if ((ab - bc) < FLOAT_EPSILON && (bc - ca) < FLOAT_EPSILON) {
    return equilateral;
  }

  if ((ab - bc < FLOAT_EPSILON) || (bc - ca < FLOAT_EPSILON) ||
      (ca - ab < FLOAT_EPSILON)) {
    return isosceles;
  }

  return scalene;
}

void printTriangle(triangle t) {
  printf("Triangolo: A(%f, %f) B(%f, %f) C(%f, %f)\n", t[0].x, t[0].y, t[1].x,
         t[1].y, t[2].x, t[2].y);
}

/*
  Dato un triangolo restituisce true se questo è valido (ovvero il punto
  nord-ovest è situato veramente più in alto a sinistra del punto sud-est),
  altrimenti restituisce false.
*/
bool isValid(rectangle r) {
  return (r.nw.x < r.se.x) && (r.nw.y > r.se.y);
}

/*
  Restitusice la "bounding box" (ovvero l'inviluppoo di due rettangoli).
  Questa funzione presume che i due rettangoli siano validi come specificato da
  `bool isValid(const rectangle* r)`.
*/
rectangle getBoudingBox(rectangle a, rectangle b) {
  rectangle r;

  r.nw.x = a.nw.x > b.nw.x ? a.nw.x : b.nw.x;
  r.nw.y = a.nw.y > b.nw.y ? a.nw.y : b.nw.y;
  r.se.x = a.se.x < b.se.x ? a.se.x : b.se.x;
  r.se.x = a.se.x < b.se.x ? a.se.x : b.se.x;

  return r;
}

void printRectangle(rectangle r) {
  printf("Rettangolo: NW(%f, %f) SE(%f, %f)\n", r.nw.x, r.nw.y, r.se.x, r.se.y);
}

int main() {
  // punto a)
  triangle t = {
      {0, 5},
      {5, 0},
      {0, 0},
  };

  printf("t: ");
  printTriangle(t);

  switch (getTriangleType(t)) {
    case equilateral:
      printf("Il triangolo è equilatero\n");
      break;

    case isosceles:
      printf("Il triangolo è isoscele\n");
      break;

    case scalene:
      printf("Il triangolo è scaleno\n");
      break;
  }

  // punto b)
  rectangle r1 = {
      {0, 5},
      {5, 0},
  };

  rectangle r2 = {
      {-4, 4},
      {0, 0},
  };

  printf("r1: ");
  printRectangle(r1);
  printf("r2: ");
  printRectangle(r2);

  printf("r1 %s valido\n", isValid(r1) ? "è" : "non è");
  printf("r2 %s valido\n", isValid(r2) ? "è" : "non è");

  rectangle bb = getBoudingBox(r1, r2);
  printf("bb: ");
  printRectangle(bb);

  // TODO: trovare l'intersezione tra i due rettangoli

  return 0;
}
