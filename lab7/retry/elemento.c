#include "elemento.h"

struct Elemento{
  char name[MAXC];
  int type, entry, exit, prec, ending, val, diff;
};

Elemento **allocaVettore(int numElem){
  return malloc(numElem*sizeof(Elemento));
}

Elemento *creaElemento(char nome[MAXC], int type, int entry, int exit, int prec, int ending, int val, int diff){
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
