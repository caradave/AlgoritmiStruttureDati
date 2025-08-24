#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 100

typedef struct Elemento Elemento;

Elemento **allocaVettore(int numElem);
void DistruggiElemento(Elemento **e, int numElem);
Elemento *creaElemento(char nome[MAXC], int type, int entry, int exit, int prec, int ending, float val, int diff);

void printVettoreElementi(Elemento **e, int len);
float getPoints(Elemento *e);
int getDiff(Elemento *e);
int getAcro(Elemento *e);
int checkEntryOut(Elemento *e1, Elemento *e2);
int checkFirstEntry(Elemento *e);
int checkPrec(Elemento *e);
int checkEnding(Elemento *e);

#endif
