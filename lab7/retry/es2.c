#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "diagonale.h"

typedef struct DiagonaliFinali{
  Diagonale **d;
  int numDiagonali;
  int maxDiagonaliDisp;
} DiagonaliFinali;

Elemento **readFile(FILE *inF);
int disp_ripet(int pos, Elemento **val, Diagonale *sol, int n, int k, int count, int dd, DiagonaliFinali *dFin);

int main(void){
  FILE *infile = fopen("elementi.txt", "r");
  
  Elemento **e = readFile(infile);
  // printVettoreElementi(e, 19);
  DiagonaliFinali *dFin = malloc(sizeof(DiagonaliFinali));
  dFin->d = malloc(300*sizeof(Diagonale *));
  for(int i=0; i<300; i++)
    dFin->d[i] = creaDiag();
  dFin->maxDiagonaliDisp = 300;
  dFin->numDiagonali = 0;

  Diagonale *d = creaDiag();
  for(int i=1; i<=5; i++)
    disp_ripet(0, e, d, 19, i, 0, 10, dFin);

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

int disp_ripet(int pos, Elemento **val, Diagonale *sol, int n, int k, int count, int dd, DiagonaliFinali *dFin){
  if(pos >= k  /*pos > 0 && checkEnding(sol->e[pos-1]) == 1*/){
    sol->numElem = k;
    if(checkAcro(sol) && checkLast(sol) == 1){

      dFin->numDiagonali += 1;
      if(dFin->maxDiagonaliDisp == dFin->numDiagonali){
        dFin->d = realloc(dFin->d, (dFin->maxDiagonaliDisp*2+dFin->numDiagonali)* sizeof(Diagonale *));

        if(dFin == NULL){
          printf("impossibile riallocare\n");
          exit -1;
        }
      }

      dFin->d[dFin->numDiagonali - 1] = creaDiag();
      dFin->d[dFin->numDiagonali-1]->numElem = k;

      for(int i=0; i<sol->numElem; i++){
        dFin->d[dFin->numDiagonali-1][i] = sol[i];
      }

      printf("numDiagonali: %d\n", dFin->numDiagonali);
      printDiagonale(dFin->d[dFin->numDiagonali -1]);
      printf("difficolta: %d", calcolaDiff(dFin->d[dFin->numDiagonali -1]));
      printf("\n\n\n");
    }
    return count;
  }

  for(int i=0; i<n; i++){
    sol->numElem = pos;
    if(((pos == 0 && checkFirstEntry(val[i]) && checkPrec(val[i])) || (pos != 0 && checkEntryOut(sol->e[pos-1], val[i]))) && (calcolaDiff(sol) + getDiff(val[i])) <= dd){
      sol->e[pos] = val[i];
      count = disp_ripet(pos+1, val, sol, n, k, count, dd, dFin);
    }
  }

  return count;
}
