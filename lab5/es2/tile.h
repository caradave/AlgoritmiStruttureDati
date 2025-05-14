#ifndef TILE_H
#define TILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tile Tile;
struct Tile *createTile(char c1, int v1, char c2, int v2);
void printTile(struct Tile *t);

#endif
