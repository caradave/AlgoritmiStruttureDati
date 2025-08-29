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

int addIfNotInList(char **listaVertici, char **listaNetwork, char nome[], char network[], int pos){
  int check=0;
  for(int i=0; i<pos; i++)
      if(strcmp(listaVertici[i], nome) == 0)
        check = 1;
  if(check == 0){
    strcpy(listaVertici[pos], nome);
    strcpy(listaNetwork[pos], nome);
    pos++;
  }
  return pos;
}

int createListaVertici(FILE *inF, char **listaVertici, char **listaNetwork, int lenF){
  int flusso, count=0;
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC];
  
  for(int i=0; i<lenF; i++){
    // leggo il file in maniera tale che possa inserire nella lista i nomi dei vertici e dei network
    fscanf(inF, "%s %s %s %s %d\n", id1, rete1, id2, rete2, &flusso);
    // controllo per l'ID1 e se non c'è in lista lista lo inserisco
    count = addIfNotInList(listaVertici, listaNetwork, id1, rete1, count);
    
    // controllo per l'ID2, se non c'è lo inserisco in lista
    count = addIfNotInList(listaVertici, listaNetwork, id2, rete2, count);
  }
  rewind(inF);
  return count;
}

void riempiMat(FILE *inF, Grafo *g){
  int flusso, posID1, posID2;
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC]; 

  while(fscanf(inF, "%s %s %s %s %d", id1, rete1, id2, rete2, &flusso) != EOF){
    posID1 = searchHashTableByName(g->t, id1);
    posID2 = searchHashTableByName(g->t, id2);
    g->mat[posID1][posID2] = flusso;
    g->mat[posID2][posID1] = flusso;
  }
}

void readFile(FILE *inF, Grafo *g){
  int numArchi, flusso, count=0, lenF=0, pos;
  char id1[MAXC], rete1[MAXC], id2[MAXC], rete2[MAXC];

  // scopro quanto è lungo il mio file e di conseguenza quello è il mio numero di archi
  lenF = getLenFile(inF);
  g->numArchi = lenF;

  // genero l'insieme dei vertici, prima allocando e poi riempiendo
  char **listaVertici = malloc(lenF*2*sizeof(char *));
  char **listaNetwork = malloc(lenF*2*sizeof(char *));
  for(int i=0; i<lenF*2; i++){
    listaVertici[i] = malloc(MAXC*sizeof(char));
    listaNetwork[i] = malloc(MAXC*sizeof(char));
  }

  g->numVertici = createListaVertici(inF, listaVertici, listaNetwork, lenF);

  // aggiorno il grafo passato per refecence e creo la HashTable
  g->t = createHashTable(g->numVertici);

  // riempio la HashTable
  for(int i=0; i<g->numVertici; i++)
    pos = insertHashTable(g->t, listaVertici[i], listaNetwork[i]);

  // alloco la matrice delle adiacenze
  g->mat = malloc(g->t->size*sizeof(int *));
  for(int i=0; i<g->t->size; i++)
    g->mat[i] = calloc(g->t->size, sizeof(int)); 

  riempiMat(inF, g);
  
  for(int i=0; i<g->t->size; i++){
    for(int k=0; k<g->t->size; k++)
      printf("%d ", g->mat[i][k]);
    printf("\n");
  }
}
