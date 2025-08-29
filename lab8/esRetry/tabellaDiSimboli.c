#include "tabellaDiSimboli.h"

HashTable *createHashTable(int size){
  HashTable *ht = malloc(sizeof(HashTable));
  ht->size = 2*size;
  ht->numElem = 0;

  ht->tab = malloc(ht->size*sizeof(Entry));
  for(int i=0; i<ht->size; i++)
    ht->tab[i].state = 0;

  return ht;
}

int hashCalculate(char name[], int tabDim){
  int pos=0;
  int len = strlen(name);

  for(int i=0; i<len; i++)
    pos = (pos + (name[i]-'A')) % tabDim;

  return pos;
}

int insertHashTable(HashTable *ht, char nome[], char network[]){
  int pos = hashCalculate(nome, ht->size);

  if(ht->size == ht->numElem)
    exit(-1);

  while(ht->tab[pos].state != 0){
    pos += 1;
    pos = pos%ht->size;
  }

  ht->numElem++;
  ht->tab[pos].state = 1;
  strcpy(ht->tab[pos].nome, nome);
  strcpy(ht->tab[pos].network, network);

  return pos;
}

int searchHashTableByName(HashTable *ht, char nome[]){
  int pos = hashCalculate(nome, ht->size);
  
  if(ht->numElem == 0)
    return -1;

  while(strcmp(ht->tab[pos].nome, nome) != 0){
    pos += 1;
    pos = pos%ht->size;
  }
  return pos;
}

char *searchHashTableByIndex(HashTable *ht, int pos){
  return ht->tab[pos].nome;
}

char *searchHashTableByIndexReturnWithNetwork(HashTable *ht, int index){
  char *string = malloc((MAXC*2+1)*sizeof(char));
  strcat(string, ht->tab[index].nome);
  strcat(string, " ");
  strcat(string, ht->tab[index].network);
  return string;
}
