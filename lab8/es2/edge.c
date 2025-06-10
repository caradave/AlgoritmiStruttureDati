#include "edge.h"

Edge edgeCreate(char *nome, char *id){
  Edge e;

  strcpy(e.nome, nome);
  strcpy(e.IDrete, id);

  return e;
}

int checkNotInList(Edge *eList, Edge e, int len){
  printf("valore len: %d\n", len);
  for(int i=0; i<len; i++)
    if(strcmp(eList[i].nome, e.nome) == 0)
      return 1;
  return 0;
}

int edgesList(Edge **e, FILE *infile, int count){
  char nome1[MAXC], id1[MAXC], nome2[MAXC], id2[MAXC];
  int peso;
  count=0;

  while(fscanf(infile, "%s %s %s %s %d\n", nome1, id1, nome2, id2, &peso) != EOF)
    count++;

  *e = malloc((count*2)*sizeof(struct Edge));

  rewind(infile);
  count = 0;
  struct Edge e1;


  while(fscanf(infile, "%s %s %s %s %d\n", nome1, id1, nome2, id2, &peso) != EOF){
    strcpy(e1.nome, nome1);
    strcpy(e1.IDrete, id1);
    if(checkNotInList(*e, e1, count) == 0){
      *(e)[count] = edgeCreate(nome1, id1);
      count++;
    }
  }

  return count;
}

void printEdges(struct Edge *e, int len){
  for(int i=0; i<len; i++)
    printf("%s %s\n", (e)[i].nome, &(e)[i].IDrete);
}

void printEdge(struct Edge *e){
  printf("%s %s\n", e->nome, e->IDrete);
}