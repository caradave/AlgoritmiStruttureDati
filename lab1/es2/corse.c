#include "corse.h"

Corse *readFile(FILE *infile, int lenFile, Corse *corse){
  corse = malloc(lenFile*sizeof(Corse));

  for(int i=0; i<lenFile; i++){
    fscanf(infile, "%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d", corse[i].cod, corse[i].start, corse[i].end, &corse[i].date.yy, &corse[i].date.mm, &corse[i].date.dd, &corse[i].timeStart.hh, &corse[i].timeStart.min, &corse[i].timeStart.sec, &corse[i].timeEnd.hh, &corse[i].timeEnd.min, &corse[i].timeEnd.sec, &corse[i].late);
  }

  return corse;
}

void printDataStructure(int len, Corse *corse){
  for(int i=0; i<len; i++){
    printCorse(corse[i]);
    }
}

void printCorse( Corse corse){
  printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse.cod, corse.start, corse.end, corse.date.yy, corse.date.mm, corse.date.dd, corse.timeStart.hh, corse.timeStart.min, corse.timeStart.sec, corse.timeEnd.hh, corse.timeEnd.min, corse.timeEnd.sec, corse.late);
}
