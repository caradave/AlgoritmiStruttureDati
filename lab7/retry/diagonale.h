#ifndef DIAGONALE_H
#define DIAGONALE_H

#include "elemento.h"

typedef struct Diagonale{
  Elemento **e;
  int numElem, diff;
  float punti;
} Diagonale;

Diagonale *creaDiag();
void distruggiDiag(Diagonale *d);
float calcolaPunteggio(Diagonale *d);
int calcolaDiff(Diagonale *d);
int checkAcro(Diagonale *d);
int checkLast(Diagonale *d);
void printDiagonale(Diagonale *d);

#endif
