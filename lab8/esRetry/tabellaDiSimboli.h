#ifndef TABELLADISIMBOLI_H
#define TABELLADISIMBOLI_H

#include <stdlib.h>
#include <string.h>

#define MAXC 30

typedef struct Entry{
  char nome[MAXC];
  int state;
} Entry;

typedef struct HashTable{
  Entry *tab;
  int size;
  int numElem;
} HashTable;

HashTable *createHashTable(int size);
void insertHashTable(HashTable *ht, char nome[]);

#endif
