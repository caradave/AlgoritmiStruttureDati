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

int checkNotInList(Edge *eList, Edge e, int len);
int edgesList(Edge **e, FILE *infile, int count);
void printEdges(Edge **e, int len);
void printEdge(struct Edge *e);

#endif
