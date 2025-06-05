#include "edge.h"

struct Edge edgeCreate(char nome[], char IDrete[]){
  struct Edge e;

  strcpy(e.nome, nome);
  strcpy(e.IDrete, IDrete);

  return e;
}

char *getNome(struct Edge e){
  return (e.nome);
}

char *getIDrete(struct Edge e){
  return e.IDrete;
}

int edgeNotInList(struct Edge *e, struct Edge e1, int len){
  for(int i=0; i<len; i++)
    if(edgeCompare(e[i], e1))
      return -1;
  return 1;
}

int initSymbolTab(struct Edge *e, FILE *inF){
  int count=0;

  char nome1[MAXC], IDrete1[MAXC], nome2[MAXC], IDrete2[MAXC];
  int val;

  while(fscanf(inF, "%s %s %s %s %d", nome1, IDrete1, nome2, IDrete2, &val) != EOF){
    if(edgeNotInList(e, edgeCreate(nome1, IDrete1), count) == 1){
      count++;
      e = realloc(e, count*sizeof(struct Edge));
      e[count] = edgeCreate(nome1, IDrete1);
    }
    if(edgeNotInList(e, edgeCreate(nome2, IDrete2), count) == 1){
      count++;
      e = realloc(e, count*sizeof(struct Edge));
      e[count] = edgeCreate(nome2, IDrete2);
    }
  }
  return count;
}

int edgeCompare(struct Edge e1, struct Edge e2){
  if(strcmp(e1.nome, e2.nome) == 1 && strcmp(e1.IDrete, e2.IDrete) == 1)
    return 1;
  return -1;
}

int getIndexEdge(struct Edge *e, struct Edge e1, int len){
  for(int i=0; i<len; i++)
    if(edgeCompare(e[i], e1) == 1)
      return i;
  return -1;
}

