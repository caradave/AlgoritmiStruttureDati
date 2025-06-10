#include "grafo.h"

struct Grafo *grafoInit(){
  Grafo *g = malloc(sizeof(struct Grafo));

  g->numV = 0;
  g->numE = 0;  

  return g;
}

int **allocaMat(int len){
  int **mat = malloc(len*sizeof(int *));

  for(int i=0; i<len; i++){
    mat[i] = malloc(len*sizeof(int));
    for(int k=0; k<len; k++)
      mat[i][k] = 0;
  }

  return mat;
}

int getLenFile(FILE *infile){
  char nome1[MAXC], id1[MAXC], nome2[MAXC], id2[MAXC];
  int peso;
  int count=0;

  while(fscanf(infile, "%s %s %s %s %d\n", nome1, id1, nome2, id2, &peso) != EOF)
    count++;

  return count;
}

void edgeCopy(Edge *e1, Edge *e2, int len){
  for(int i=0; i<len; i++)
    e2[i] = e1[i];
}

void populateMat(int **mat, Edge *e, int len, FILE *file){
  char nome1[MAXC], id1[MAXC], nome2[MAXC], id2[MAXC];
  int peso, x, y;
  int count=0;

  while(fscanf(file, "%s %s %s %s %d\n", nome1, id1, nome2, id2, &peso) != EOF){
    x = getPos(e, edgeCreate(nome1, id1), len);
    y = getPos(e, edgeCreate(nome2, id2), len);
    mat[y][x] = peso;
    mat[x][y] = peso;
  }
}

void printMat(int **mat, int len){
  for(int i=0; i<len; i++){
    for(int k=0; k<len; k++)
      printf("%3d ", mat[i][k]);
    printf("\n");
  }
}

void printEdgesList(Edge *e, int len){
  printEdges(e, len);
}

Grafo *readFile(FILE *infile){
  Grafo *g = grafoInit();
  
  if(infile == NULL){
    printf("impossibile eseguire azioni sul file");
    return NULL;
  }

  Edge *e = malloc(getLenFile(infile)*sizeof(Edge));

  rewind(infile);
  g->numE = edgesList(e, infile, g->numE);
  g->e = malloc(g->numE * sizeof(Edge));

  edgeCopy(e, g->e, g->numE);
  free(e);

  
  rewind(infile);
  g->mat = allocaMat(g->numE);
  populateMat(g->mat, g->e, g->numE, infile);

  return g;
}

Node *newNode(Node *h, int weight, int posConnected){
  Node *x = malloc(sizeof(Node));
  if(x == NULL)
    return NULL;

  x->link = posConnected;
  x->weight = weight;

  x->next = h;
  return x;
}

Grafo *createListaAd(Grafo *g){
  g->listaAd = malloc(g->numE*sizeof(Node*));

  for(int i=0; i<g->numE; i++){
    g->listaAd[i] = NULL;
    for(int k=0; k<g->numE; k++){
      if(g->mat[i][k] != 0)
        g->listaAd[i] = newNode(g->listaAd[i], k, g->mat[i][k]);
    }
    printLinkedList(g->listaAd[i]);
  }

  return g;
}

void printLinkedList(Node *h){
  for(Node *x=h; x != NULL; x=x->next)
    printf("%d %d\n", x->link, x->weight);
}

void bubbleSort(Edge *e, int len){
  for(int i=0; i<len; i++)
    for(int k=i+1; k<len; k++){
      if(strcmp(e[i].nome, e[k].nome) > 0){
        Edge temp = e[i];
        e[i] = e[k];
        e[k] = temp;
      }
    }
}

void sortAndPrint(Grafo *g){
  Edge *eSorted = malloc(g->numE * sizeof(Edge));

  for(int i=0; i<g->numE; i++)
    eSorted[i] = g->e[i];

  bubbleSort(eSorted, g->numE);
  for(int i=0; i<g->numE; i++){
    printf("%s %s, archi connessi:\n", eSorted[i].nome, eSorted[i].IDrete);
    for(int k=0; k<g->numE; k++)
      if(g->mat[i][k] != 0)
        printf("%s %s, peso: %d\n", g->e[k].nome, g->e[i].IDrete, g->mat[i][k]);
    printf("\n");
  }
}

int checkSubCompleteSubGraph(Grafo *g){
  char s1[MAXC], s2[MAXC], s3[MAXC];

  printf("inserire i nomi dei 3 archi: ");
  scanf("%s %s %s", s1, s2, s3);

  int pos1, pos2, pos3;

  for(int i=0; i<g->numE; i++){
    if(strcmp(g->e[i].nome, s1) == 0)
      pos1 = i;
    if(strcmp(g->e[i].nome, s2) == 0)
      pos2 = i;
    if(strcmp(g->e[i].nome, s3) == 0)
      pos3 = i;
  }

  int count=0;
  if(g->mat[pos1][pos2] != 0 && g->mat[pos1][pos3] != 0)
    count++;
  if(g->mat[pos2][pos1] != 0 && g->mat[pos2][pos3] != 0)
    count++;
  if(g->mat[pos3][pos1] != 0 && g->mat[pos3][pos2] != 0)
    count++;

  if(count == 3)
    return 1;
  return 0;
}
