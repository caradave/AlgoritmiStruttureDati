#include "elemento.h"

struct Elemento{
  char name[MAXC];
  int type, entry, exit, prec, ending,diff;
  float val;
};

Elemento **allocaVettore(int numElem){
  return malloc(numElem*sizeof(Elemento));
}

void DistruggiElemento(Elemento **e, int numElem){
  for(int i=0; i<numElem; i++)
    free(e[i]);
  free(e);
}

Elemento *creaElemento(char nome[MAXC], int type, int entry, int exit, int prec, int ending, float val, int diff){
  Elemento *e = malloc(sizeof(Elemento));

  strcpy(e->name, nome);
  e->type = type;
  e->entry = entry;
  e->exit = exit;
  e->prec = prec;
  e->ending = ending;
  e->val = val;
  e->diff = diff;

  return e;
}

void printElemento(Elemento *e){
  printf("%24s %d %d %d %d %d %f %d\n", e->name, e->type, e->entry, e->exit, e->prec, e->ending, e->val, e->diff);
}

void printVettoreElementi(Elemento **e, int len){
  for(int i=0; i<len; i++)
    printf("%24s %d %d %d %d %d %f %d\n", e[i]->name, e[i]->type, e[i]->entry, e[i]->exit, e[i]->prec, e[i]->ending, e[i]->val, e[i]->diff);
}

float getPoints(Elemento *e){
  return e->val;
}

int getDiff(Elemento *e){
  return e->diff;
}

int getAcro(Elemento *e){
  return e->type;
}

int checkEnding(Elemento *e){
  return e->ending;
}

int checkFirstEntry(Elemento *e){
  return (e->entry == 1);
}

int checkEntryOut(Elemento *e1, Elemento *e2){
  if(e1 == NULL || e2 == NULL)
    return 0;
  return (e1->exit == e2->entry);
}

int checkPrec(Elemento *e){
  return (e->prec == 0);
}
