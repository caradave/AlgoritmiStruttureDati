#include "corse.h"

Corse *readFile(FILE *infile, int lenFile, Corse *corse){
  corse = malloc(lenFile*sizeof(Corse));

  for(int i=0; i<lenFile; i++){
    fscanf(infile, "%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d", corse[i].cod, corse[i].start, corse[i].end, &corse[i].date.yy, &corse[i].date.mm, &corse[i].date.dd, &corse[i].timeStart.hh, &corse[i].timeStart.min, &corse[i].timeStart.sec, &corse[i].timeEnd.hh, &corse[i].timeEnd.min, &corse[i].timeEnd.sec, &corse[i].late);
  }

  return corse;
}

void printDataStructureCorse(int len, Corse *corse){
  for(int i=0; i<len; i++){
    printCorse(corse[i]);
    }
}

void printOnFile(int len, FILE *outFile, Corse *corse){
  for(int i=0; i<len; i++)
    fprintf(outFile, "%s %s %s %d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse[i].cod, corse[i].start, corse[i].end, corse[i].date.yy, corse[i].date.mm, corse[i].date.dd, corse[i].timeStart.hh, corse[i].timeStart.min, corse[i].timeStart.sec, corse[i].timeEnd.hh, corse[i].timeEnd.min, corse[i].timeEnd.sec, corse[i].late);
}

void printCorse(Corse corse){
  printf("%s %s %s %d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse.cod, corse.start, corse.end, corse.date.yy, corse.date.mm, corse.date.dd, corse.timeStart.hh, corse.timeStart.min, corse.timeStart.sec, corse.timeEnd.hh, corse.timeEnd.min, corse.timeEnd.sec, corse.late);
}

int compareStartStationCorse(Corse c1, Corse c2){
  if(strcmp(c1.start, c2.start))
    return 1;
  else if(!strcmp(c1.start, c2.start))
    return -1;
  else
    return 0;
}

int compareEndStationCorse(Corse c1, Corse c2){
  if(strcmp(c1.end, c2.end))
    return 1;
  else if(!strcmp(c1.end, c2.end))
    return -1;
  else
    return 0;
}

int compareCodCorse(Corse c1, Corse c2){
  if(strcmp(c1.cod, c2.cod))
    return 1;
  else if(!strcmp(c1.cod, c2.cod))
    return -1;
  else
    return 0;
}

Corse *swap(Corse *corse, int pos){
    Corse temp = corse[pos];
    corse[pos] = corse[pos+1];
    corse[pos+1] = temp;
  return corse;
}

Corse *corseSortedByDate(int len, Corse *corse){
  for(int i=0; i<len-1; i++)
    for(int k=0; k<len-i-1; k++){
      int compareResult = compareDate(corse[k].date, corse[k+1].date);
      if(compareResult == 0){
        if(compareTime(corse[k].timeStart, corse[k].timeStart)){
          corse = swap(corse, k);
        }
      }else if(compareResult == 1){
        corse = swap(corse, k);
      }
    }
  return corse;
}

Corse *corseSortedByCod(int len, Corse *corse){
  for(int i=0; i<len-1; i++)
    for(int k=0; k<len-i-1; k++)
      if(strcmp(corse[k].cod, corse[k+1].cod) > 0)
        corse = swap(corse, k);
  return corse;
}

Corse *corseSortedByStartingStation(int len, Corse *corse){
  for(int i=0; i<len-1; i++)
    for(int k=0; k<len-i-1; k++)
      if(strcmp(corse[k].start, corse[k+1].start) > 0)
        corse = swap(corse, k);
  return corse;
}

Corse *corseSortedByEndingStation(int len, Corse *corse){
  for(int i=0; i<len-1; i++)
    for(int k=0; k<len-i-1; k++)
      if(strcmp(corse[k].end, corse[k+1].end) > 0)
        corse = swap(corse, k);
  return corse;
}

Corse *corseFoundByStart(int len, Corse *corse){
  char name[MAXC];
  int lenName;

  printf("inserire il nome della stazione che si desidera cercare (anche parziale): ");
  scanf("%s", name);

  lenName = strlen(name);
  
  for(int i=0; i<len; i++){
    if(strncmp(name, corse[i].start, lenName) == 0){
      printCorse(corse[i]);
    }
  }

  return corse;
}
