#include <stdio.h>
#include <string.h>
#include "date.h"
#include "corse.h"

#define MAXC 30

void selectAction(int len, Corse *corse);
void selectBetweenDate(int len, Corse *corse);
void selectStationStart(int len, Corse *corse);
void selectStationEnd(int len, Corse *corse);
void selectBetweenDateLate(int len, Corse *corse);
void ritardoSum(int len, Corse *corse);

int main(void){
  FILE *infile = fopen("corse.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file\n");
    return -1;
  }
  
  int lenFile;
  fscanf(infile, "%d", &lenFile);
  
  Corse *corse;
  corse = readFile(infile, lenFile, corse);
  printDataStructure(lenFile, corse); 
  selectAction(lenFile, corse);

  fclose(infile);
  return 0;
}

void selectAction(int len, Corse *corse){
  
  printf("1) stampa di corse tra due date\n2) elencare tutte le corse partite da una certa fermata\n3) elencare tutte le fermate che fanno capolinea ad una certa fermata\n4) elencare tutte le corse partite con ritardo in un intervallo di dati\n5) elencare il ritardo totale ottenuto da una certa tratta\n");

  int scelta;
  scanf("%d", &scelta);

  switch (scelta){
    case 1:
      selectBetweenDate(len, corse);
    break;
    case 2:
      selectStationStart(len, corse);
    break;
    case 3:
      selectStationEnd(len, corse);
    break;
    case 4:
      selectBetweenDateLate(len, corse);
    break;
    case 5:
      ritardoSum(len, corse);
    break;
    default:
      printf("impossibile eseguire");
      return;
    break;
  }
}

void selectBetweenDate(int len, Corse *corse){
  Date dateStart, dateEnd;

  printf("inserire la data da cui si desidera iniziare: ");
  scanf("%d/%d/%d", &dateStart.dd, &dateStart.mm, &dateStart.yy);

  printf("inserire la data in cui si desidera terminare: ");
  scanf("%d/%d/%d", &dateEnd.dd, &dateEnd.mm, &dateEnd.yy);
  
  for(int i=0; i<len; i++){
    if(compareDate(corse[i].date, dateStart) >= 0 && compareDate(corse[i].date, dateEnd) <= 0)
      printCorse(corse[i]);
  }
}

void selectStationStart(int len, Corse *corse){
  char station[MAXC];

  printf("inserire la stazione desirata\n");
  scanf("%s", station);
  
  for(int i=0; i<len; i++){
    if(!strcmp(corse[i].start, station)){
      printCorse(corse[i]);
    }
  }
}

void selectStationEnd(int len, Corse *corse){
  char station[MAXC];

  printf("inserire la stazione desirata\n");
  scanf("%s", station);
  
  for(int i=0; i<len; i++){
    if(!strcmp(corse[i].end, station)){
      printCorse(corse[i]);
    }
  }
}

void selectBetweenDateLate(int len, Corse *corse){
  Date dateStart, dateEnd;

  printf("inserire la data da cui si desidera iniziare: ");
  scanf("%d/%d/%d", &dateStart.dd, &dateStart.mm, &dateStart.yy);

  printf("inserire la data in cui si desidera terminare: ");
  scanf("%d/%d/%d", &dateEnd.dd, &dateEnd.mm, &dateEnd.yy);
  
  for(int i=0; i<len; i++){
    if(compareDate(corse[i].date, dateStart) >= 0 && compareDate(corse[i].date, dateEnd) <= 0 && corse[i].late != 0)
      printCorse(corse[i]);
  }
}

void ritardoSum(int len, Corse *corse){
  char cod[MAXC];
  int late = 0;

  printf("inserire il codice desirato: ");
  scanf("%s", cod);
  
  for(int i=0; i<len; i++){
    if(!strcmp(corse[i].cod, cod)){
      late += corse[i].late;
    }
  }
  printf("il ritardo totale della tratta con codice %s e' stato %d\n", cod, late);
}

