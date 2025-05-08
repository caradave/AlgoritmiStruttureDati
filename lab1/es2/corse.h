#ifndef CORSE_H
#define CORSE_H

#include <string.h>
#include <stdlib.h>
#include "date.h"

#define MAXC 30

typedef struct Time{
  int hh, min, sec;
} Time;

typedef struct{
  char start[MAXC], end[MAXC], cod[MAXC];
  Date date;
  Time timeStart, timeEnd;
  int late;
} Corse;

Corse *readFile(FILE *infile, int lenFile, Corse *corse);
void printDataStructure(int len, Corse *corse);
void printCorse(Corse corse);
#endif
