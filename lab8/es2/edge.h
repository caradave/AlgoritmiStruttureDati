#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 30

typedef struct Edge{
  char nome[MAXC];
  char IDrete[MAXC];
} Edge;

struct Edge edgeCreate(char nome[], char IDrete[]);
char *getWeight(struct Edge e);
int edgeCompare(struct Edge e1, struct Edge e2);
int initSymbolTab(struct Edge *e, FILE *inF);
int getIndexEdge(struct Edge *e, struct Edge e1, int len);

#endif
