#include "SimbolTable.h"

struct ST *createST(int dim, int maxc){
  ST *st = malloc(sizeof(ST));

  st->vett = malloc(dim*sizeof(char *));
  for(int i=0; i<dim; i++)
    st->vett[i] = malloc(maxc*sizeof(char));

  st->lenVett = dim;
  st->pos = 0;
  st->MAXlen = maxc;

  return st;
}

void insertInTab(ST *t, char *nome){
  strcpy(t->vett[t->pos], nome);
  t->pos++;

  for(int i=t->pos-1; i>0; i--){
    if(strcmp(t->vett[i-1], t->vett[i]) > 0){
      char temp[t->MAXlen];
      strcpy(temp, t->vett[i-1]);
      strcpy(t->vett[i-1], t->vett[i]);
      strcpy(t->vett[i], temp);
    }else
      break;
  }
}


static int getIndexR(char **vett, int l, int r, char *nome) {
  if (l > r)
    return -1;

  int m = l + (r - l) / 2;
  int cmp = strcmp(vett[m], nome);

  if (cmp == 0) 
    return m;
  else if (cmp > 0)
    return getIndexR(vett, l, m - 1, nome);
  else
    return getIndexR(vett, m + 1, r, nome);
}

int getIndex(ST *t, char *nome){
  if(t->pos == 0)
    return -1;
  // printST(t);
  return getIndexR(t->vett, 0, t->pos-1, nome);
}

void printST(ST *t){
  for(int i=0; i<t->pos; i++)
    printf("%d %s\n", i, t->vett[i]);
  printf("\n");
}

char *getName(ST *t, int pos){
  return t->vett[pos];
}
