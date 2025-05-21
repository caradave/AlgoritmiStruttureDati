#include <stdio.h>
#include <stdlib.h>

#include "esercizio.h"
#include "list.h"

#define DD 10
#define DP 20
#define LEND 3



struct Node *disp_ripetExercise(int pos, Exercise **val, Exercise **sol, int n, int k, struct Node *h);
int disp_ripet(int pos, struct Node **val, struct Node **sol, int n, int k, struct Node **bestSol, float valBestSol);

int main(void){
  FILE *infile = fopen("elementi.txt", "r");
  Exercise **e;
  int lenFile;
  fscanf(infile, "%d", &lenFile);

  e = readFile(infile, lenFile);
  //printExercises(e, lenFile);
  // fino a qui funziona

  Exercise **solExercise = malloc(lenFile * sizeof(Exercise *));
  struct Node *h = NULL;
  for(int i=1; i<6; i++)
    h = disp_ripetExercise(0, e, solExercise, lenFile, i, h);
  // printList(h);

  int lenList;
  lenList = getLenLinkedList(h);
  //printf("lenLinkedList: %d", lenList);
  //fino a qui funziona

  struct Node **vett=allocateVett(lenList);

  vett = createVett(h, vett);
  // printVett(vett, lenList);
  // fino a qui il vettore e giusto

  struct Node **solVett = allocateVett(lenList);
  struct Node **bestSol = allocateVett(LEND);
  int valueBestSol=0;
  int maxVal = disp_ripet(0, vett, solVett, lenList, LEND, bestSol, valueBestSol);

  return 0;
}




struct Node *disp_ripetExercise(int pos, Exercise **val, Exercise **sol, int n, int k, struct Node *h) {
  int i;
  if (pos >= k) {
    int diff = countDiffDiag(sol, pos);
    if(diff < DD && checkAcro(sol, pos) > 0)
      h = newNode(sol, pos, diff, h);
    return h;
  }
  for (i = 0; i < n; i++) 
    if((pos == 0 && getEntry(val[i]) == 1) || (pos > 0 && getOut(sol[pos-1]) == getEntry(val[i]))){
      sol[pos] = val[i];
      h = disp_ripetExercise(pos+1, val, sol, n, k, h);
    }
  return h;
}

int disp_ripet(int pos, struct Node **val, struct Node **sol, int n, int k, struct Node **bestSol, float valBestSol) {
  int i;
  if (pos >= k) {
    float valSol=countValueDiag(sol);
    if(checkProgDiff(sol) > 0 && valSol>valBestSol && checkAcroProg(sol) > 0 && checkAcroSeq(sol) > 0 ){
      for(int i=0; i<LEND; i++)
        bestSol[i] = sol[i];
      valBestSol = valSol;
      printf("value: %f\n", valSol);
      printVett(sol, k);
     }
    return valBestSol;
  }
  for (i = 0; i < n; i++) {
    sol[pos] = val[i];
    valBestSol = disp_ripet(pos+1, val, sol, n, k, bestSol, valBestSol);
  }
  return valBestSol;
}

