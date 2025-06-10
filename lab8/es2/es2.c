#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void){
  FILE *infile = fopen("grafo.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  } 
  readFile(infile);

  fclose(infile);
  return 0;
}
