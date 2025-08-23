#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

int main(void){
  FILE *infile = fopen("elementi.txt", "r");
  

  fclose(infile);
  return 0;
}

void readFile(FILE *inF){
  int numElem;
  fscanf(inF, "%d\n", &numElem);

  Elemento **e = allocaVettore(numElem);

  for(int i=0; i<numElem && fscanf(inF, "%s %d %d %d %d %d %d %d\n")!=EOF; i++)
}
