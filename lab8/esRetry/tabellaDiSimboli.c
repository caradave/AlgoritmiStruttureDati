#include "tabellaDiSimboli.h"

HashTable *createHashTable(int size){
  HashTable *ht = malloc(sizeof(HashTable));
  ht->size = 10*size;
  ht->numElem = 0;

  ht->tab = malloc(size*10*sizeof(Entry));
  for(int i=0; i<10*size; i++)
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

void insertHashTable(HashTable *ht, char nome[]){
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
}

int seachHashTable(HashTable *ht, char nome[]){
  int pos = hashCalculate(nome, ht->size);
  
  if(ht->tab[0].state == 0)
    return -1;

  while(strcmp(ht->tab[pos].nome, nome) != 0){
    pos += 1;
    pos = pos%ht->size;
  }
  return pos;
}
