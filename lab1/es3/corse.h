#ifndef CORSE_H
#define CORSE_H

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

#define MAXC 30

typedef struct Corse{
  char start[MAXC], end[MAXC], cod[MAXC];
  Date date;
  Time timeStart, timeEnd;
  int late;
} Corse;

Corse *readFile(FILE *infile, int lenFile, Corse *corse);
void printDataStructureCorse(int len, Corse *corse);
void printCorse(Corse corse);
void printOnFile(int len, FILE *outFile, Corse *corse);
int compareStartStationCorse(Corse c1, Corse c2);
int compareEndStationCorse(Corse c1, Corse c2);
int compareCodCorse(Corse c1, Corse c2);
Corse *corseSortedByDate(int len, Corse *corse);
Corse *corseSortedByCod(int len, Corse *corse);
Corse *corseSortedByStartingStation(int len, Corse *corse);
Corse *corseSortedByEndingStation(int len, Corse *corse);
Corse *corseFoundByStart(int len, Corse *corse);

#endif
