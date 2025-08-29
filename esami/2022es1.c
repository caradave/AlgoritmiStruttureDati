#include <stdio.h>
#include <stdlib.h>

// per leggere un vettore come una matrice: mat[pos/nr][pos%nr]

typedef struct Tile{
  int posX, posY, colore, dim;
} Tile;

typedef struct Board{
  int nr, nc;
  int **b;
} Board;

void readFile(FILE *infile, Board *b){
  int pos=0;
  fscanf(infile, "%d %d", &b->nr, &b->nc);

  b->b = malloc(b->nr*sizeof(int *));
  for(int i=0; i<b->nr; i++)
    b->b[i] = malloc(b->nc*sizeof(int));

  for(int i=0; i<b->nr; i++){
    for(int k=0; k<b->nc; k++){
      fscanf(infile, "%d", &b->b[i][k]);
    }
  }
}

int **readPossibility(FILE *inF){
  int nc, nr;
  int **mat;

  fscanf(inF, "%d %d\n", &nc, &nr);

  mat = malloc(nr*sizeof(int *));
  for(int i=0; i<nr; i++)
    mat[i] = malloc(nc*sizeof(int));

  for(int i=0; i<nr; i++)
    for(int k=0; k<nc; k++)
      fscanf(inF, "%d", &mat[i][k]);

  return mat;
}

int checkValid(int **pos, Board *b){
  for(int i=0; )
}
