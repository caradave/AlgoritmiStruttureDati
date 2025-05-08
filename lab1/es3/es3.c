#include <stdio.h>
#include "corse.h"

#define MAXC 30

void selectAction(int len, Corse *corse);
void printData(int len, Corse *corse);

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
//  printDataStructureCorse(lenFile, corse); 
  selectAction(lenFile, corse);

  fclose(infile);
  return 0;
}

void selectAction(int len, Corse *corse){
  
  printf("1) stampa a video o su file del contenuto del log\n2) ordinamento del vettore per data\n3) ordinamento del vettore per codice di tratta\n4) ordinamento del vettore per per stazione di partenza\n5) ordinamento del vettore per stazione di arrivo\n6) ricerda di una tratta per stazione di arrivo (anche parziale)\n");
  int scelta;
  scanf("%d", &scelta);

  switch (scelta){
    case 1:
      printData(len, corse); 
    break;
    case 2:
      corse = corseSortedByDate(len, corse);
      printDataStructureCorse(len, corse);
    break;
    case 3:
      corse = corseSortedByCod(len, corse);
      printDataStructureCorse(len, corse);
    break;
    case 4:
      corse = corseSortedByStartingStation(len, corse);
      printDataStructureCorse(len, corse);
    break;
    case 5:
      corse = corseSortedByEndingStation(len, corse);
      printDataStructureCorse(len, corse);
    break;
    case 6:
      corse = corseFoundByStart(len, corse);
    break;
    default:
      printf("impossibile eseguire");
      return;
    break;
  }
}


void printData(int len, Corse *corse){
  int scelta;

  printf("1) se si desidera stampare il file a video\n2) se si desidera stampare su un file\n");
  scanf("%d", &scelta);

  if(scelta == 1){
    printDataStructureCorse(len, corse);
  }else{
    char fileName[MAXC];
    FILE *outFile;

    printf("inserire il nome del file: ");
    scanf("%s", fileName);

    outFile = fopen(fileName, "w");

    if(outFile == NULL)
      printf("impossibile aprire il file");
    else
      printOnFile(len, outFile, corse);
    
    fclose(outFile);
  }
}
