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

int checkInList(Edge *eList, Edge e, int len);
int edgesList(Edge *e, FILE *infile, int count);
void printEdges(Edge *e, int len);
void printEdge(struct Edge *e);
int getPos(Edge *e, Edge e1, int len);
Edge edgeCreate(char *nome, char *id);

#endif
