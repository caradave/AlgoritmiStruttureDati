#include <stdio.h>

typedef struct Heap{
  ITEM *item;
  int len;
} Heap;

typedef struct BT{
  ITEM *node;
  struct BT *sx, *dx;
} BT;

void heapToBT(int heap, int pos, int lenHeap, BT *t){
  if()
}



editoriADT EditoriDup(editori_Adt e){
  editori_adt *editori = malloc(sizeof(editori_adt));
  editori->editori = malloc(e->n_editori *sizeof(editori_adt));
  editori->numEditori = e->numEditori;

  for(int i=0; i<e->numEditori; i++){
    editori->editori[i]->editori->nome = strdup(e->editori[i]->nome);

  }

}





typedef struct BST_wrapper{
  struct BST *root;
  int len;
  struct BST *end;
} BST_wrapper;

typedef struct BST{
  ITEM *item;
  struct BST *sx, *dx;
  BST *end;
} BST;

int checkBalancedW(BST_wrapper *b){
  int bool = checkBalanced(BST->root, BST->end, 0);
  if(bool == -1)
    return 0;
  return 1;
}

int checkBalanced(BST *root, BST *end, int *countR, int *countL){
  if(root == end){
    return 0;
  }
  countR += checkBalanced(root->dx, end);
  countL += checkBalanced(root->sx, end);

  if(countR == countL)
    return countR+countL;
  return 0;
  
}


typedef struct parola{
  char *parola;
  parola *next;

}






void matNoZero(int **mat, int nr, int nc){
  int *zeriC=malloc(nc*sizeof(int)), *zeriR=malloc(nr*sizeof(int));
  int c=nc, r=nr;

  for(int i=0; i<nr; i++)
    zeriR[i] = 1;
  for(int i=0; i<nc; i++)
    zeriC[i] = 1;

  for(int i=0; i<nr; i++){
    for(int k=0; k<nc; k++){
      if(mat[i][k] == 0){
        if(zeriC[k] == 1){
          c--;
          r--;
        }
        zeriC[k] = 0;
        zeriR[i] = 0;
      }
    }
  }

  int **mat2 = malloc(r*sizeof(int*));
  for(int i=0; i<r; i++)
    mat2[i] = malloc(c*sizeof(int));

  int countR=0, countC=0;
  for(int i=0; i<nr; i++){
    countC = 0;
    if(zeriR[i] != 0){
      for(int k=0; k<nc, k++){
        if(zeriC[k] != 0){
          mat2[countR][countC] = mat[i][k];
          countC++;
        }
      }
      countR++;
    }
  }
}

void checkCorrect(ITEM *t, int *c){
  if(t == NULL)
    return;

  int *dx = checkCorrect(t->dx, c);
  int *sx = checkCorrect(t->sx, c);

  if(dx == NULL && sx == NULL)
    return t->val;
  if(dx == NULL && sx>t->val)
    return t->val;
  if(dx < t->val && sx == NULL)
    return t->val;
  if(dx < t->val && sx > t->val)
    return t->val;
  *c = 0;
  return -1;
  
}

int f(BST t){
  int *checkCorrect = 1;
  checkCorrect(t->item, check);
  if(*check == 1)
    return 1;
  return 0;
}
