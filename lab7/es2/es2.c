#include <stdio.h>
#include <stdlib.h>

#include "esercizio.h"

#define DD 10
#define DG 20

typedef struct Node{
  Exercise **e;
  int lenE;
  int minDiff;
  struct Node *next;
} Node;

struct Node *newNode(Exercise **e, int lenE, struct Node *h);
struct Node *powerset_div_conq(int pos, Exercise **val, Exercise **sol, int n, int start, struct Node *h);
Exercise **perm_sempl(int pos, Exercise **val, Exercise **sol, int *mark, int n, Exercise **result);
void printList(struct Node *h);

struct Node *disp_ripet(int pos, Exercise **val, Exercise **sol, int n, int k, struct Node *h);


int main(void){
  FILE *infile = fopen("elementi.txt", "r");
  Exercise **e;
  int lenFile;
  fscanf(infile, "%d", &lenFile);

  e = readFile(infile, lenFile);
  // printExercises(e, lenFile);

  Exercise **sol = malloc(lenFile * sizeof(Exercise *));
  struct Node *h = NULL;
  for(int i=1; i<6; i++)
    h = disp_ripet(0, e, sol, lenFile, i, h);
  printList(h);
  int *mark = malloc(5*sizeof(int));
  Exercise **result = malloc(5*sizeof(Exercise *));

  //for(struct Node *x=h; x!=NULL; x=x->next){
  //  if(countMinDiffDiag(x->e, x->lenE) <= DD){
  //    perm_sempl(0, x->e, sol, mark, x->lenE, result);
  //  }
  //}


  return 0;
}

struct Node *newNode(Exercise **e, int lenE, struct Node *h){
  struct Node *x = malloc(sizeof(struct Node));

  if(x == NULL){
    return NULL;
  }

  x->e = malloc(lenE*sizeof(Exercise *));

  for(int i=0; i<lenE; i++)
    x->e[i] = e[i];
  x->lenE = lenE;
  x->next = h;
  return x;
}

void printList(struct Node *h){
  for(struct Node *x=h; x!=NULL; x = x->next){
    printf("%d\n", x->lenE);
    printExercises(x->e, x->lenE);
  }
}


Exercise **perm_sempl(int pos, Exercise **val, Exercise **sol, int *mark, int n, Exercise **result) {
  int i;
  if (pos >= n) {
     printExercises(sol, pos);
     printf("\n");
    return result;
  }

  for (i=0; i<n; i++)
    if (mark[i] == 0){
      if((pos == 0 && getEntry(val[i]) == 1) || (pos > 0 && getOut(sol[pos-1]) == getEntry(val[i]))){
        mark[i] = 1;
        sol[pos] = val[i];
        result = perm_sempl(pos+1, val, sol, mark, n, result);
        mark[i] = 0;
      }
    }
  return result;
}

struct Node *disp_ripet(int pos, Exercise **val, Exercise **sol, int n, int k, struct Node *h) {
  int i;
  if (pos >= k) {
    if(countMinDiffDiag(sol, pos) < DD && checkAcro(sol, pos) > 0)
      h = newNode(sol, pos, h);
    return h;
  }
  for (i = 0; i < n; i++) 
    if((pos == 0 && getEntry(val[i]) == 1) || (pos > 0 && getOut(sol[pos-1]) == getEntry(val[i]))){
      sol[pos] = val[i];
      h = disp_ripet(pos+1, val, sol, n, k, h);
    }
  return h;
}
