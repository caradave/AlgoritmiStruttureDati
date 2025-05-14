#ifndef TILE_H
#define TILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tile Tile;
struct Tile *createTile(char c1, int v1, char c2, int v2);
  void ReadTile(FILE *infile, Tile **t, int len);
void printTile(struct Tile *t, int rot);
void printTiles(Tile **t, int len);
void freeTile(struct Tile *t);
void freeTiles(struct Tile **t, int len);

#endif
