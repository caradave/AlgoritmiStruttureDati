#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "edge.h"

typedef struct Node Node;

typedef struct Grafo{
  int numV;
  int numA;
  int **matA;
  struct Node *listaA;
  Edge *symbolTab;
} Grafo;

struct Grafo grafoInit();
#endif
