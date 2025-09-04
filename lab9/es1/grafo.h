#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "SimbolTable.h"

typedef struct Grafo *grafo;
typedef struct Archi Archi;

struct Grafo *createGrafo(int dim);
struct Grafo *readFile(FILE *inF);
void printGrafo(struct Grafo *g);
Archi *creaDag(struct Grafo *g);
#endif
