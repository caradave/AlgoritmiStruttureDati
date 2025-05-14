#include <stdio.h>
#include <stdlib.h>
#include "tile.h"

typedef struct Board{
  Tile *t;
  int rotation;
} Board;

void ReadTile(FILE *infile, Tile **t, int len);
void printTiles(Tile **t, int len);

int main(void){
  FILE *tile = fopen("tiles.txt", "r");
  int lenFile;
  Tile **t;

  fscanf(tile, "%d\n", &lenFile);
  t = malloc(lenFile*sizeof(Tile *));
  ReadTile(tile, t, lenFile);
  printTiles(t, lenFile);

  fclose(tile);

  FILE *board = fopen("board.txt", "r");
  int nr, nc;
  fscanf(board, "%d %d\n", &nr, &nc);

  struct Board **b = malloc(nr * sizeof(struct Board *));
  for(int i=0; i<nr; i++)
    b[i] = malloc(nc * sizeof(struct Board));

  return 0;
}

void ReadTile(FILE *infile, Tile **t, int len){
  int v1, v2;
  char c1, c2;
  for(int i=0; i<len; i++){
    fscanf(infile, "%c %d %c %d\n", &c1, &v1, &c2, &v2);
    t[i] = createTile(c1, v1, c2, v2);
  }
}

void printTiles(Tile **t, int len){
  for(int i=0; i<len; i++){
    printTile(t[i]);
    printf("\n");
  }
}
