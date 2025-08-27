#include <stdio.h>
#include <stdlib.h>

typedef struct Node *link;

typedef struct Node{
  int edge;
  link next;
} Node;

typedef struct Edge{
  int v1, v2;
} Edge;

typedef struct Grafo{
  int **mat;
  link *lista;
  Edge *edges;
  int numVertici, numEdges;
} Grafo;

link newNode(link h, int edge){
  link x = malloc(sizeof(Node));

  if(x == NULL)
    return NULL;
  
  x->edge = edge;
  x->next = h;
  return x;
}

void readGrafo(Grafo *g, FILE *inf){
  int numVertici, v1, v2, numEdges=0, maxNumEdges;
  fscanf(inf, "%d\n", &numVertici);
  maxNumEdges = 2*numVertici;
  
  link *lista = malloc(numVertici*sizeof(link));
  Edge *e = malloc(2*numVertici*sizeof(Edge));
  int **mat = malloc(numVertici*sizeof(int *));
  for(int i=0; i<numVertici; i++)
    mat[i] = calloc(numVertici, sizeof(int));

  while(fscanf(inf, "%d %d\n", &v1, &v2) != EOF){
    mat[v1][v2] = 1;
    mat[v2][v1] = 1;
    lista[v1] = newNode(lista[v1], v2);
    lista[v2] = newNode(lista[v2], v1);

    if(numEdges == maxNumEdges){
      maxNumEdges = numEdges*2;
      e = realloc(e, numEdges*2*sizeof(Edge));
    }

    e[numEdges].v1 = v1;
    e[numEdges].v2 = v2;
    numEdges++;
    
  }
  g->mat = mat;
  g->lista = lista;
  g->edges = e;
  g->numVertici = numVertici;
  g->numEdges = numEdges;
}

typedef struct Partition{
  int numVertici;
  int *vertici;
} Partition;

typedef struct PartitionWrapped{
  Partition *p;
  int numPartition;
} PartitionWrapped;

void readPartition(FILE *fPartition, PartitionWrapped *p){
  int numPartition, numVertici;

  fscanf(fPartition, "%d", &numPartition);
  Partition *pInside = malloc(numPartition*sizeof(struct Partition));
  
  for(int i=0; i<numPartition; i++){
    fscanf(fPartition, "%d\n", &numVertici);
    pInside[i].vertici = malloc(numVertici*sizeof(int));
    pInside[i].numVertici = numVertici;

    for(int k=0; k<numVertici; k++)
      fscanf(fPartition, "%d ", &pInside[i].vertici[k]);
  }
  p->numPartition = numPartition;
  p->p = pInside;
}

void checkDomaticR(Grafo *g, int vert, int *check){
  if(g->lista[vert] == NULL || check[g->lista[vert]->edge] == 1)
    return;
  for(link i= g->lista[vert]; i->next != NULL; i=i->next){
    check[vert] = 1;
    checkDomaticR(g, g->lista[vert]->edge, check);
  }
}

int checkDomaticW(Grafo *g, PartitionWrapped *p){
  int *check = malloc(g->numVertici * sizeof(int));

  for(int i=0; i<p->numPartition; i++){
    for(int k=0; k<p->p->numVertici; k++)
      checkDomaticR(g, p->p->vertici[i], check);
  }
  return -1;
}
