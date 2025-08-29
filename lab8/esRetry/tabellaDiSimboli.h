#ifndef TABELLADISIMBOLI_H
#define TABELLADISIMBOLI_H

#include <stdlib.h>
#include <string.h>

#define MAXC 30

typedef struct Entry{
  char nome[MAXC];
  char network[MAXC];
  int state;
} Entry;

typedef struct HashTable{
  Entry *tab;
  int size;
  int numElem;
} HashTable;

HashTable *createHashTable(int size);
int hashCalculate(char name[], int tabDim);
int insertHashTable(HashTable *ht, char nome[], char network[]);
char *searchHashTableByIndex(HashTable *ht, int pos); 
int searchHashTableByName(HashTable *ht, char nome[]);
char *searchHashTableByIndexReturnWithNetwork(HashTable *ht, int index);
#endif
