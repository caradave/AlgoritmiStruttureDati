#include "powerset.h"

struct SubVect *powerset_div_conq(int pos, int *val, int *sol, int n, int start, struct SubVect *h) {
   int i;
   if (start >= n) {
    h = newNode(h, sol, pos);
    return h;
   }
   for (i = start; i < n; i++) {
      sol[pos] = val[i];
      h = powerset_div_conq(pos+1, val, sol, n, i+1, h);
   }
   h = powerset_div_conq(pos, val, sol, n, n, h);
   return h;
}

struct SubVect *newNode(struct SubVect *h, int *vect, int lenV){
  struct SubVect *x = malloc(sizeof(struct SubVect));
  
  x->v = malloc(lenV*sizeof(int));

  if(x == NULL)
    return NULL;
  else{
    for(int i=0; i<lenV; i++)
      x->v[i] = vect[i];
    x->lenV = lenV;
    x->next = h;
  }
  return x;
}

void printPowerset(struct SubVect *h){
  for(struct SubVect *x = h; x != NULL; x=x->next){
    for(int j=0; j< x->lenV; j++)
      printf("%d ", x->v[j]);
    printf("\n");
  }
}
