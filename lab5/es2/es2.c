#include <stdio.h>
#include <stdlib.h>

#include "tile.h"
#include "board.h"
#include "powerset.h"

int perm_sempl(int pos, int *val, int *sol, int *mark, int n,  Board **b, Board **finalSol, Tile **t, int value, int nc, int nr, struct SubVect *h);
int createVettNotUsed(Tile **t, int len, int *v);
int checkValue(Board **b, int nc, int nr);
Board **setBoard(Board **b, int nc, int nr, int *sol, Tile **t);

int main(void){
  FILE *tile = fopen("tiles.txt", "r");
  if(tile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }
  int lenTile;
  Tile **t;

  fscanf(tile, "%d\n", &lenTile);
  t = malloc(lenTile*sizeof(Tile *));
  ReadTile(tile, t, lenTile);
  //printTiles(t, lenTile);

  fclose(tile);

  FILE *board = fopen("board.txt", "r");
  if(board == NULL){
    printf("impossibile aprire il file\n");
    return -1;
  }
  int nr, nc;
  fscanf(board, "%d %d\n", &nr, &nc);

  Board **b = ReadBoard(board, nr, nc, t);
  Board **finalSol = allocBoard(finalSol, nr, nc);
  //printBoard(b, nr, nc);
  fclose(board);
  
  int *freePos = malloc((nr*nc) *sizeof(int));
  int lenFree = createVettNotUsed(t, lenTile, freePos);

  int *sol = malloc(lenFree*sizeof(int));
  int *mark = malloc(lenFree*sizeof(int));
  for(int i=0; i<lenFree; i++)
    mark[i] = 0;

  struct SubVect *h;
  h = powerset_div_conq(0, freePos, sol, lenFree, 0, h);
  // printPowerset(h);

  int val = perm_sempl(0, freePos, sol, mark, lenFree, b, finalSol, t, 0, nc, nr, h);
  printBoard(finalSol, nr, nc);
  printf("value: %d\n", val);

  freeTiles(t, lenTile);
  freeBoard(b, nr, nc);
  return 0;
}

int createVettNotUsed(Tile **t, int len, int *v){
  int free=0;
  for(int i=0; i<len; i++)
    if(getTaken(t[i]) == 0){
      v[free] = i;
      free++;
    }
  return free;
}

int perm_sempl(int pos, int *val, int *sol, int *mark, int n, Board **b, Board **finalSol, Tile **t,  int value, int nc, int nr, struct SubVect *h) {
  if (pos >= n) {
    Board **bsol = setBoard(b, nc, nr, sol, t);
    int val;
    for(struct SubVect *x=h; x != NULL; x=x->next){
      for(int i=0; i<x->lenV; i++){
        bsol[getPosY(t[x->v[i]])][getPosX(t[x->v[i]])].rot = 1;
      }
      val = checkValue(bsol, nr, nc);

      if(val > value){
        value = val;
        boardCopy(finalSol, bsol, nr, nc);
      }
      for(int i=0; i<x->lenV; i++){
        bsol[getPosY(t[x->v[i]])][getPosX(t[x->v[i]])].rot = 0;
      }    
    }

    return value;
  }

  for (int i=0; i<n; i++)
    if (mark[i] == 0) {
      mark[i] = 1;
      sol[pos] = val[i];
      value = perm_sempl(pos+1, val, sol, mark, n, b, finalSol, t, value, nc, nr, h);
      mark[i] = 0;
    }
  return value;
}

Board **setBoard(Board **b, int nc, int nr, int *sol, Tile **t){
  Board **copy = allocBoard(copy, nc, nr);
  int used=0; 
  
  for(int i=0; i<nr; i++)
    for(int j=0; j<nr; j++)
      copy[i][j] = b[i][j];

  for(int i=0; i<nr; i++)
    for(int j=0; j<nc; j++){
      if(copy[i][j].tilePos == -1){
        copy[i][j].t = t[sol[used]];
        setPos(t[sol[used]], j, i);
        copy[i][j].rot = 0;
        used++;
      }
    }
  return copy;
}

int checkValue(Board **b, int nc, int nr){
  int value=0;
  char color;
  for(int i=0; i<nr; i++){
    color = getColor(b[i][0].t, b[i][0].rot, 1);
    int sameColor = 1;
    for(int j=0; j<nc && sameColor==1; j++)
      if(getColor(b[i][j].t, b[i][j].rot, 1) != color)
        sameColor = 0;
    for(int j=0; j<nc && sameColor == 1; j++)
      value = value + getValue(b[i][j].t, b[i][j].rot, 1);
  }

  for(int i=0; i<nr; i++){
    color = getColor(b[0][i].t, b[0][i].rot, 2);
    int sameColor = 1;
    for(int j=0; j<nc && sameColor==1; j++)
      if(getColor(b[j][i].t, b[j][i].rot, 2) != color)
        sameColor = 0;
    for(int j=0; j<nc && sameColor == 1; j++)
      value = value + getValue(b[j][i].t, b[j][i].rot, 2);

  }
  return value;
}

