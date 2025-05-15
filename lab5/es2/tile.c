#include "tile.h"

typedef struct Tile{
  char c1, c2;
  int v1, v2;
  int posX, posY;
  int taken;
} Tile;

struct Tile *createTile(char c1, int v1, char c2, int v2){
  struct Tile *t = malloc(sizeof(struct Tile));
  t->c1 = c1;
  t->v1 = v1;
  t->c2 = c2;
  t->v2 = v2;
  t->taken = 0;
  t->posX = -1;
  t->posY = -1;
  return t;
}

void ReadTile(FILE *infile, Tile **t, int len){
  int v1, v2;
  char c1, c2;
  for(int i=0; i<len; i++){
    fscanf(infile, "%c %d %c %d\n", &c1, &v1, &c2, &v2);
    t[i] = createTile(c1, v1, c2, v2);
  }
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

void setPos(Tile *t, int x, int y){
  t->posX = x;
  t->posY = y;
}

int getPosX(Tile *t){
  return t->posX;
}

int getPosY(Tile *t){
  return t->posY;
}

void setTaken(Tile *t, int value){
  t->taken = value;
}

int getTaken(Tile *t){
  return t->taken;
}

char getColor(Tile *t, int rot, int orien){
  if(rot == 0 && orien == 1)
    return t->c1;
  if(rot == 0 && orien == 2)
    return t->c2;
  if(rot == 1 && orien == 1)
    return t->c2;
  if(rot == 1 && orien == 2)
    return t->c1;

}

int getValue(Tile *t, int rot, int orien){
  if(rot == 0 && orien == 1)
    return t->v1;
  if(rot == 0 && orien == 2)
    return t->v2;
  if(rot == 1 && orien == 1)
    return t->v2;
  if(rot == 1 && orien == 2)
    return t->v1;
}

void freeTile(struct Tile *t){
  free(t);
}

void freeTiles(struct Tile **t, int len){
  for(int i=0; i<len; i++)
    freeTile(t[i]);
  free(t);
}

