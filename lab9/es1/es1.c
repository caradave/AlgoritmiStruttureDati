#include <stdio.h>
#include "grafo.h"

int main(void){
  FILE *inF = fopen("grafo3.txt", "r");

  if(inF == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  grafo g;
  g = readFile(inF);
  printf("fine del readFile 5\n");

  printGrafo(g);
  printf("fine del print grafo\n");

  creaDag(g);

  return 0;
}
