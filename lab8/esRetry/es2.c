#include <stdio.h>

#include "grafo.h"

int main(int argc, char *argv[]){
  
  if(argc != 2){
    printf("passato il numero sbagliato di argomenti\n");
    return -1;
  }

  FILE *inF = fopen(argv[1], "r");
  if(inF == NULL){
    printf("impossibilie aprire il file");
    return -2;
  }

  Grafo *g = createGrafo();
  readFile(inF, g);
  return 0;
}
