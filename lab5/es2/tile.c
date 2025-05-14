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

void printTile(struct Tile *t, int rot){
  if(t == NULL){
    printf("impossibile printare");
    return;
  }
  if(rot == 0)
    printf("%c %d %c %d", t->c1, t->v1, t->c2, t->v2);
  else
    printf("%c %d %c %d", t->c2, t->v2, t->c1, t->v1);
}

void printTiles(Tile **t, int len){
  for(int i=0; i<len; i++){
    printTile(t[i], 0);
    printf("\n");
  }
}

void freeTile(struct Tile *t){
  free(t);
}

void freeTiles(struct Tile **t, int len){
  for(int i=0; i<len; i++)
    freeTile(t[i]);
  free(t);
}

void ReadTile(FILE *infile, Tile **t, int len){
  int v1, v2;
  char c1, c2;
  for(int i=0; i<len; i++){
    fscanf(infile, "%c %d %c %d\n", &c1, &v1, &c2, &v2);
    t[i] = createTile(c1, v1, c2, v2);
  }
}
