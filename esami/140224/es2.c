#include <stdio.h>
#include <stdlib.h>

typedef struct square{
  int pos, val;
  struct square *next;
} square;

typedef struct matr_t{
  int nr, nc;
  struct square **vett;
} matr_t;

void populateMat(struct matr_t *m, int r, int c, float val);

int main(void){
  
  return 0;
}


void populateMat(struct matr_t *m, int r, int c, float val){
  if(m->vett[r] == NULL){
    struct square *s = malloc(sizeof(struct square));

    if(s == NULL)
      return;

    s->pos = c;
    s->val = val;

    s->next = m->vett[r];
    m->vett[r] = s;
  }
  struct square *x=m->vett[r];
  for( struct square *y=x->next; y!= NULL; x=y, y=y->next)
    if(y->pos>c)
      break;
  struct square *s = malloc(sizeof(struct square));

  if(s == NULL)
    return;

  s->pos = c;
  s->val = val;

  s->next = x->next->next;
  x->next=s;
}
