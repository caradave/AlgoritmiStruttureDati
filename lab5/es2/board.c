#include "board.h"

struct Board **allocBoard(struct Board **b, int nr, int nc){
  b = malloc(nr*sizeof(struct Board *));
  for(int i=0; i<nr; i++)
    b[i] = malloc(nc*sizeof(struct Board));
  return b;
}

struct Board **ReadBoard(FILE *infile, int nr, int nc, Tile **t){
  struct Board **b = allocBoard(b, nr, nc);
  if(b == NULL){
    printf("impossibile allocare b");
    return NULL;
  }
  int tilePos;
  for(int i=0; i<nr; i++)
    for(int k=0; k<nc; k++){
      b[i][k].t = malloc(sizeof(Tile *));
      fscanf(infile, "%d/%d", &tilePos, &b[i][k].rot);
      b[i][k].tilePos = tilePos;
      if(b[i][k].tilePos != -1){
        setTaken(t[tilePos], 1);
        setPos(t[tilePos], k, i);
        b[i][k].t = t[tilePos];
      }
  }
  return b;
}

void printBoard(struct Board **b, int nr, int nc){
  for(int i=0; i<nr; i++){
    for(int k=0; k<nc; k++){
      printTile(b[i][k].t, b[i][k].rot);
      printf("rot:%d ", b[i][k].rot);
      printf(" |");
    }
    printf("\n");
    printf("----------------------------------");
    printf("\n");
  }
}

void boardCopy(struct Board **copy, struct Board **b, int nr, int nc){
  for(int i=0; i<nr; i++)
    for(int j=0; j<nr; j++)
      copy[i][j] = b[i][j];
}

void freeBoard(struct Board **b, int nr, int nc){
  for(int i=0; i<nr; i++)
      free(b[i]);
  free(b);
}
