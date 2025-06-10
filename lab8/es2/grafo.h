#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "edge.h"

typedef struct Node{
  int link, weight;
  struct Node *next;
} Node;

typedef struct Grafo{
  int numV;
  int numE;
  int **mat;
  Edge *e;
  Node **listaAd;
} Grafo;

Grafo *readFile(FILE *infile);
void printMat(int **mat, int len);
void printEdgesList(Edge *e, int len);
Grafo *createListaAd(Grafo *g);
void printLinkedList(Node *h);
void sortAndPrint(Grafo *g);

#endif
