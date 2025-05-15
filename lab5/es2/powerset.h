#ifndef POWERSET_H
#define POWERSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SubVect{
  int *v;
  int lenV;
  struct SubVect *next;
} SubVext;

struct SubVect *newNode(struct SubVect *h, int *v, int lenV);
struct SubVect *powerset_div_conq(int pos, int *val, int *sol, int n, int start, struct SubVect *h);
void printPowerset(struct SubVect *h);

#endif
