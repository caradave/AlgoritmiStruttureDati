#ifndef SIMBOLTABLE_H
#define SIMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ST{
  char **vett;
  int lenVett;
  int pos;
  int MAXlen;
} ST;

struct ST *createST(int dim, int maxc);
void insertInTab(ST *t, char *nome);
int getIndex(ST *t, char *nome);
void printST(ST *t);
char *getName(ST *t, int pos);
#endif
