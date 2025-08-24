#include "diagonale.h"

Diagonale *creaDiag(){
  Diagonale *d = malloc(sizeof(Diagonale));
  d->e = malloc(5*sizeof(Elemento *));
  d->diff = 0;
  d->numElem = 0;
  d->punti = 0;

  return d;
}

void distruggiDiag(Diagonale *d){
  free(d->e);
  free(d);
}

void printDiagonale(Diagonale *d){
  printVettoreElementi(d->e, d->numElem);
}

float calcolaPunteggio(Diagonale *d){
  int somma=0;
  for(int i=0; i<d->numElem; i++)
    somma += getPoints(d->e[i]);
  return somma;
}

int calcolaDiff(Diagonale *d){
  int somma=0;
  for(int i=0; i<d->numElem; i++)
    somma += getDiff(d->e[i]);
  return somma;
}

int checkAcro(Diagonale *d){
  int check=0;
  for(int i=0; i<d->numElem; i++)
    if(getAcro(d->e[i]) == 1 || getAcro(d->e[i]) == 2)
      check = 1;
  return check;
}
