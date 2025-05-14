#include "board.h"

struct Board **ReadBoard(FILE *infile, int nr, int nc, Tile **t){
  struct Board **b = malloc(nr*sizeof(struct Board *));
  for(int i=0; i<nr; i++)
    b[i] = malloc(nc*sizeof(struct Board));
  int tilePos;
  for(int i=0; i<nr; i++)
    for(int k=0; k<nc; k++){
      fscanf(infile, "%d/%d", &tilePos, &b[i][k].rot);
      printf("%d\n", tilePos);
      if(tilePos == -1)
        b[i][k].t == NULL;
      else
        b[i][k].t = t[tilePos];
  }
  return b;
}

void printBoard(struct Board **b, int nr, int nc){
  for(int i=0; i<nr; i++){
    for(int k=0; k<nc; k++){
      printTile(b[i][k].t, b[i][k].rot);
      printf(" ");
    }
    printf("\n");
  }
}

void freeBoard(struct Board **b, int nr, int nc){
  for(int i=0; i<nr; i++)
      free(b[i]);
  free(b);
}
