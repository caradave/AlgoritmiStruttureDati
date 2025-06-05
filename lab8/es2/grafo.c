#include "grafo.h"

typedef struct Node{
  int v;
  int weight;
  struct Node *next;
} Node;

struct Grafo grafoInit(){
  struct Grafo g;

  g.numV = 0;
  g.numA = 0;
  g.matA = NULL;
  g.listaA = NULL;
  g.symbolTab = NULL;

  return g;
}

int **allocateMat(int dim){
  int **mat = malloc(dim * sizeof(int *));

  for(int i=0; i<dim; i++)
    mat[i] = malloc(dim * sizeof(int));

  return mat;
}

void readFile(FILE *inF){
  char nome1[MAXC], IDrete1[MAXC], nome2[MAXC], IDrete2[MAXC];
  int weight;

  FILE *file = inF;

  struct Grafo g = grafoInit();

  g.numV = initSymbolTab(g.symbolTab, file);
  
  g.matA = allocateMat(g.numV);

  while(fscanf(inF, "%s %s %s %s %d\n", nome1, IDrete1, nome2, IDrete2, &weight)){
    int x=getIndexEdge(g.symbolTab, edgeCreate(nome1, IDrete1), g.numV);
    int y = getIndexEdge(g.symbolTab, edgeCreate(nome2, IDrete2), g.numV);
    g.matA[x][y] = weight;
    g.numA++;
  }
}
