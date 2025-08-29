#include "grafo.h"

#define MAXC 30

typedef struct Node{
  int v;
  struct Node *next;
} Node;

typedef struct Grafo{
  int numVertici;
  int numArchi;
  int **mat;
  Node **lista;
  HashTable *t;
} Grafo;

Grafo *createGrafo(){
  Grafo *g = malloc(sizeof(Grafo));

  g->numVertici = 0;
  g->numArchi = 0;
  g->mat = NULL;
  g->lista = NULL;
  g->t = NULL;

  return g;
}

int getLenFile(FILE *inF){
  int count=0, flusso; 
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC];
  while(fscanf(inF, "%s %s %s %s %d", id1, rete1, rete2, id2, &flusso) != EOF)
    count++;
  rewind(inF);
  return count;
}

int addIfNotInList(char **lista, char nome[], int pos){
  int check=0;
  for(int i=0; i<pos; i++)
      if(strcmp(lista[i], nome) == 0)
        check = 1;
  if(check == 0){
    printf("inserito un nome nella lista");
    strcpy(lista[pos], nome);
  }
  return pos++;
}

int createListaVertici(FILE *inF, char **lista, int lenF){
  int lenFile, flusso, count=0;
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC];
  printf("lenFile dentro la funzione: %d", lenF);

  
  for(int i=0; i<lenFile; i++){
    if(fscanf(inF, "%s %s %s %s %d", id1, rete1, id2, rete2, &flusso) != 5)
      printf("porcodio");
    printf("%s %s %s %s %d", id1, rete1, id2, rete2, flusso);
    // controllo per l'ID1 e se non c'è in lista lista lo inserisco
    count = addIfNotInList(lista, id1, count);
    
    // controllo per l'ID2, se non c'è lo inserisco in lista
    count = addIfNotInList(lista, id2, count);
    printf("elementi in lista: %d\n", count);
  }
  rewind(inF);
  return count;
}

void readFile(FILE *inF, Grafo *g){
  int numArchi, flusso, count=0, lenF=0;
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC];

  // scopro quanto è lungo il mio file
  lenF = getLenFile(inF);
  printf("lunghezza file: %d\n", lenF);

  // genero l'insieme diei vertici
  char **lista = malloc(lenF*2*sizeof(char *));
  for(int i=0; i<lenF*2; i++)
    lista[i] = malloc(MAXC*sizeof(char));
  int lenLista = createListaVertici(inF, lista, lenF);
  for(int i=0; i<lenLista; i++)
    printf("%s\n", lista[i]);

  Grafo *gInside = malloc(sizeof(Grafo));
  gInside->numVertici = lenLista;
  g->t = createHashTable(gInside->numArchi);
  printf("%d\n", gInside->numArchi);

}
