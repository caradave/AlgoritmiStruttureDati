#include "tile.h"

typedef struct Tile{
  char c1, c2;
  int v1, v2;
} Tile;

struct Tile *createTile(char c1, int v1, char c2, int v2){
  struct Tile *t = malloc(sizeof(struct Tile));
  t->c1 = c1;
  t->v1 = v1;
  t->c2 = c2;
  t->v2 = v2;
  return t;
}

void printTile(struct Tile *t){
  if(t == NULL){
    printf("impossibile printare");
    return;
  }
  printf("%c %d %c %d", t->c1, t->v1, t->c2, t->v2);
}
