#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 100

typedef struct Elemento Elemento;

Elemento **allocaVettore(int numElem);
Elemento *creaElemento(char nome[MAXC], int type, int entry, int exit, int prec, int ending, int val, int diff);
#endif
