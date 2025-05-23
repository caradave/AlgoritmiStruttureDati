#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "tile.h"

typedef struct Board{
  Tile *t;
  int tilePos;
  int rot;
} Board;

void printBoard(struct Board **b, int nr, int nc);
struct Board **ReadBoard(FILE *infile, int nr, int nc, Tile **t);
void freeBoard(struct Board **b, int nr, int nc);
struct Board **allocBoard(struct Board **b, int nr, int nc);
void boardCopy(struct Board **copy, struct Board **b, int nr, int nc);
#endif
