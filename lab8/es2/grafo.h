#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "edge.h"

typedef struct Grafo{
  int numV;
  int numE;
  int **mat;
  Edge **e;
} Grafo;

void readFile(FILE *infile);
#endif
