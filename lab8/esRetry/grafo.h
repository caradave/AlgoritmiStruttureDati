#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "tabellaDiSimboli.h"

typedef struct Grafo Grafo;

Grafo *createGrafo();
void readFile(FILE *inF, Grafo *g);

#endif
