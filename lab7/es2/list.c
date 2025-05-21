#include "list.h"

struct Node *newNode(Exercise **e, int lenE, int diff, struct Node *h){
  struct Node *x = malloc(sizeof(struct Node));

  if(x == NULL){
    return NULL;
  }

  x->e = malloc(lenE*sizeof(Exercise *));

  for(int i=0; i<lenE; i++)
    x->e[i] = e[i];
  x->lenE = lenE;
  x->diff = diff;
  x->mark = 0;
  x->next = h;
  return x;
}

int getLenLinkedList(struct Node *h){
  int count=0;
  for(struct Node *x=h; x!=NULL; x=x->next)
    count++;
  return count;
}

void printList(struct Node *h){
  for(struct Node *x=h; x!=NULL; x = x->next){
    printf("%d\n", x->lenE);
      printExercises(x->e, x->lenE);
  }
}

struct Node **allocateVett(int len){
  struct Node **v = malloc(len*sizeof(struct Node *));
  for(int i=0; i<len; i++)
    v[i] = malloc(sizeof(struct Node));
  return v;
}

struct Node **createVett(struct Node *h, struct Node **vett){
  int count=0;
  for(struct Node *x=h; x!=NULL; x=x->next, count++){
    if(checkDiffDiag(x) <= DD && getPrec(x->e[0]) == 1)
    // printExercises(x->e, x->lenE);
    vett[count] = x;
  }
  return vett;
}

void printVett(struct Node **vett, int len){
  for(int i=0; i<len; i++){
    printf("diag %d\n", i);
    printExercises(vett[i]->e, vett[i]->lenE);
  }
  printf("\n");
}

int checkDiffDiag(struct Node *n){
  int count=0;

  for(int i=0; i<n->lenE; i++)
    count += getDifficulty(n->e[i]);

  if(count<DD)
    return 1;
  return 0;
}

int checkProgDiff(struct Node **vett){
  int diff=0;
  
  for(int i=0; i<LEND; i++)
    diff += vett[i]->diff;

  if(diff<DP)
    return 1;
  return -1;
}

float countValueDiag(struct Node **vett){
  float val=0;
  float valLast=0;
  int checkMultiplier=0;

  for(int i=0; i<LEND; i++){
    if(i != LEND-1)
      for(int j=0; j<vett[i]->lenE; j++)
        val += getValue(vett[i]->e[j]);
    else
      for(int j=0; j<vett[i]->lenE; j++){
        if(getDifficulty(vett[i]->e[j]) >= 8)
          checkMultiplier = 1;
        valLast += getValue(vett[i]->e[j]);
      }    
  }
  if(checkMultiplier == 0)
    return val+valLast;
  return val+(1.5*valLast);
}

int checkAcroProg(struct Node **vett){
  int checkFront=0;
  int checkBack=0;

  for(int i=0; i<LEND; i++)
    for(int j=0; j<vett[i]->lenE; j++){
      if(getAcro(vett[i]->e[j]) == 1)
        checkBack = 1;
      if(getAcro(vett[i]->e[j]) == 2)
        checkFront = 1;
    }
  if(checkBack == 1 && checkFront == 1)
    return 1;
  return 0;
}

int checkAcroSeq(struct Node **vett){
  int acro=0;
  for(int i=0; i<LEND; i++){
    acro = 0;
    for(int j=0; j<vett[i]->lenE; j++)
      if(getAcro(vett[i]->e[j]) == 1 || getAcro(vett[i]->e[j]) == 2){
        acro++;
        if(acro == 2)
          return 1;
      }else
        acro = 0;
  }
  return -1;
}
