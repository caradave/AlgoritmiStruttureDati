#include "grafo.h"

#define MAXC 30

typedef struct Arco{
  int v, w, weight;
} Arco;

typedef struct Archi{
  Arco *a;
  int numArchi;
} Archi;

struct Grafo{
  int numVertici, numArchi;
  int **mat;
  Arco *archi;
  ST *st;
};


struct Grafo *createGrafo(int dim){
  grafo g = malloc(sizeof(grafo));

  g->mat = malloc(dim*sizeof(int *));
  for(int i=0; i<dim; i++)
    g->mat[i] = calloc(dim, sizeof(int));

  g->archi = malloc(dim*dim*2*sizeof(struct Arco));
  g->st = createST(dim, MAXC);
  g->numVertici = dim;
  g->numArchi = 0;
  return g;
}

static void aggiungiArco(struct Grafo *g, int v, int w, int weight){
  g->archi[g->numArchi].v = v;
  g->archi[g->numArchi].w = w;
  g->archi[g->numArchi].weight = weight;
  g->numArchi = g->numArchi+1;
}

struct Grafo *readFile(FILE *inF){
  int len;
  char nome[MAXC], v[MAXC], w[MAXC];

  fscanf(inF, "%d", &len);
  
  grafo g = createGrafo(len);

  for(int i=0; i<len; i++){
    fscanf(inF, "%s", nome);
    insertInTab(g->st, nome);
  }

  int weight;
  int x, y, i=0;
  while(fscanf(inF, "%s %s %d", v, w, &weight) != EOF){
    x = getIndex(g->st, v);
    y = getIndex(g->st, w);
    g->mat[x][y] = weight;
    aggiungiArco(g, x, y, weight);
  }
  return g;
}

static void printArchi(struct Grafo *g, struct Arco *a, int len){
  for(int i=0; i<len; i++){
    printf("%s %s %d\n", getName(g->st, a[i].v), getName(g->st, a[i].w), a[i].weight);
  }
}

void printGrafo(struct Grafo *g){
  printST(g->st);

  for(int i=0; i<g->numVertici; i++){
    for(int k=0; k<g->numVertici; k++)
      printf("%d ", g->mat[i][k]);
    printf("\n");
  }
  printArchi(g, g->archi, g->numArchi);
}

/* NON FUNZIONA, CI SOLO PERSO UN GIORNO E MEZZO DI LAVORO
int checkSol(Arco *sol, int len){
  int numVertici = len+1;
  int *inDegree = calloc(numVertici, sizeof(int));
  int *outDegree = calloc(numVertici, sizeof(int));

  for(int i=0; i<len; i++){
    inDegree[sol[i].w]++;
    outDegree[sol[i].v]++;
  }

  int in=0, out=0, sink=0, source=0;
  for(int i=0; i<numVertici; i++){
    if(inDegree[i] == 1)
      in++;
    if(outDegree[i] == 1)
      out++;
    if(inDegree[i] == 0)
      source++;
    if(outDegree[i] == 0)
      sink++;
  }

  free(inDegree);
  free(outDegree);

  if(source != 1 || sink != 1 || in != numVertici-1 || out != numVertici-1)
    return 0;
  return 1;
}

void checkR(struct Arco *sol, int *vett, int len){
  
}

int check(Arco *sol, int len){
  int *vettIn = calloc(len+1, sizeof(int));
  int *vettOut = calloc(len+1, sizeof(int));
  int *visited = calloc(len+1, sizeof(int));
  for(int i=0; i<len; i++){
    visited[sol[i].w] ++;
    // if(visited[sol[i].v] == 0)
      // visited[sol[i].v]++;
  }

  // printf("vettore degli outDegree\n");
  // for(int i=0; i<len+1; i++)
   // printf("%d ", vettOut[i]);
  printf("vettore visited\n ");
  for(int i=0; i<len+1; i++)
    printf("%d ", visited[i]);

  printf("\n");


  for(int i=0; i<len+1; i++)
    if(vettOut[i] != 1 || vettIn[i] != 1){
      free(vettOut);
      free(vettIn);
      return 0;
    }

  return 1;
}*/

void DfsR(struct Grafo *g, int *time, int *pre, int *post){

}

void GraphDfs(struct Grafo *g, Arco Sol, int k){
  int *pre = malloc(g->numVertici*sizeof(int));
  int time = 0;

  for(int i=0; i<g->numVertici; i++)
    pre[i] = -1;

  DfsR(g, &time, pre);
}

void comb_sempl(int pos, Arco *val, Arco *sol, int n, int k, int start, Archi *finalSol, struct Grafo *g) {
  int i;
  if (pos >= k) {
    printArchi(g, sol, k);
    int checkSol = check(sol, k);
    printf("valore check: %d\n\n", checkSol);
    if(checkSol == 1){
      printArchi(g, sol, k);
      printf("\n\n");
    }
    return;
  }
  for (i=start; i<n; i++) {
    sol[pos] = val[i];
    comb_sempl(pos+1, val, sol, n, k, i+1, finalSol, g);
  }
  return;
}

Archi *creaDag(struct Grafo *g){
  Arco *sol = malloc((g->numVertici-1)*sizeof(Arco));
  Archi *finalSol;


  
  comb_sempl(0, g->archi, sol, g->numArchi, g->numVertici-1, 0, finalSol, g);

  return finalSol;
}
