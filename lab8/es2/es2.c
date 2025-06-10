#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void){
  FILE *infile = fopen("grafo.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  } 
  Grafo *g = readFile(infile);
  printEdgesList(g->e, g->numE);
  printMat(g->mat, g->numE);
  
  g = createListaAd(g);
  sortAndPrint(g);
  fclose(infile);
  return 0;
}
