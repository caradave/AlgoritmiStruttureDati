#include "grafo.h"


struct Grafo *grafoInit(){

  Grafo *g = malloc(sizeof(struct Grafo));

  g->numV = 0;
  g->numE = 0;
  g->mat = NULL;
  g->e = NULL;
  return g;
}

int **allocaMat(int len){
  int **mat = malloc(len*sizeof(int *));

  for(int i=0; i<len; i++)
    mat[i] = malloc(len*sizeof(int));

  return mat;
}

void readFile(FILE *infile){
  Grafo *g = grafoInit();
  
  if(infile == NULL){
    printf("impossibile eseguire azioni sul file");
    return;
  }

  FILE *edgeF = infile;
  Edge **e;
  g->numE = edgesList(e, edgeF, g->numE);
  printEdges(e, g->numE);
}
