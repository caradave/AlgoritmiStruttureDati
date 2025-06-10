#include "edge.h"

Edge edgeCreate(char *nome, char *id){
  Edge e;

  strcpy(e.nome, nome);
  strcpy(e.IDrete, id);

  return e;
}

int checkInList(Edge *eList, Edge e, int len){
  for(int i=0; i<len; i++)
    if(strcmp(eList[i].nome, e.nome) == 0)
      return 1;
  return 0;
}

int edgesList(Edge *e, FILE *infile, int count){
  char nome1[MAXC], id1[MAXC], nome2[MAXC], id2[MAXC];
  int peso;
  count=0;

  struct Edge e1;

  while(fscanf(infile, "%s %s %s %s %d\n", nome1, id1, nome2, id2, &peso) != EOF){
    strcpy(e1.nome, nome1);
    strcpy(e1.IDrete, id1);
    if(checkInList(e, e1, count) == 0){
      (e)[count] = edgeCreate(nome1, id1);
      count++;
    }
    strcpy(e1.nome, nome2);
    strcpy(e1.IDrete, id2);
    if(checkInList(e, e1, count) == 0){
      (e)[count] = edgeCreate(nome2, id2);
      count++;
    }
  }
  return count;
}

void printEdges(struct Edge *e, int len){
  for(int i=0; i<len; i++)
    printf("%s %s\n", (e)[i].nome, (e)[i].IDrete);
}

void printEdge(struct Edge *e){
  printf("%s %s\n", e->nome, e->IDrete);
}

int getPos(Edge *e, Edge e1, int len){
  for(int i=0; i<len; i++)
    if(strcmp(e[i].nome, e1.nome) == 0 && strcmp(e[i].IDrete, e1.IDrete) == 0)
      return i;
  return -1;
      
}
