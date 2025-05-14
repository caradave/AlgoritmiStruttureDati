#include <stdio.h>
#include <stdlib.h>

#include "tile.h"
#include "board.h"

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

  Board **b = ReadBoard(board, nr, nc, t);
  printBoard(b, nr, nc);
  fclose(board);
  
  

  freeTiles(t, lenFile);
  freeBoard(b, nr, nc);
  return 0;
}




