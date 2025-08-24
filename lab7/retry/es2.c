#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "diagonale.h"

Elemento **readFile(FILE *inF);
int disp_ripet(int pos, Elemento **val, Diagonale *sol, int n, int k, int count, int dd);

int main(void){
  FILE *infile = fopen("elementi.txt", "r");
  
  Elemento **e = readFile(infile);
  // printVettoreElementi(e, 19);

  Diagonale *d = creaDiag();
  for(int i=1; i<=5; i++)
    disp_ripet(0, e, d, 19, i, 0, 10);

  fclose(infile);
  return 0;
}

Elemento **readFile(FILE *inF){
  int numElem;
  fscanf(inF, "%d\n", &numElem);

  Elemento **e = allocaVettore(numElem);
  char nome[100];
  int type, entry, exit, prec, ending, diff;
  float val;

  for(int i=0; i<numElem && fscanf(inF, "%s %d %d %d %d %d %f %d\n", nome, &type, &entry, &exit, &prec, &ending, &val, &diff)!=EOF; i++)
    e[i] = creaElemento(nome, type, entry, exit, prec, ending, val, diff);

  return e;
}

int disp_ripet(int pos, Elemento **val, Diagonale *sol, int n, int k, int count, int dd){
  if(pos >= k || (pos > 0 && checkEnding(sol->e[pos-1]) == 1)){
    sol->numElem = k;
    if(checkAcro(sol)){
      printDiagonale(sol);
      printf("difficolta: %d", calcolaDiff(sol));
      printf("\n\n\n");
    }
    return count;
  }

  for(int i=0; i<n; i++){
    sol->numElem = pos;
    if(((pos == 0 && checkFirstEntry(val[i]) && checkPrec(val[i])) || (pos != 0 && checkEntryOut(sol->e[pos-1], val[i]))) && (calcolaDiff(sol) + getDiff(val[i])) < dd){
      sol->e[pos] = val[i];
      count = disp_ripet(pos+1, val, sol, n, k, count, dd);
    }
  }

  return count;
}
