#include <stdio.h>
#include <stdlib.h>

int **malloc2dR(int nc, int nr);
void freeMat(int **mat, int nc, int nr);
void readFile(FILE *infile, int **mat, int nc, int nr);
void printMat(int **mat, int nc, int nr);
void printVet(int *vet, int len);
void separa(int **mat, int nc, int nr, int *bianchi, int *neri);

int main(void){
  int nr, nc;
  FILE *infile = fopen("mat.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  fscanf(infile, "%d %d\n", &nr, &nc);

  int **mat = malloc2dR(nc, nr);
  readFile(infile, mat, nc, nr);
  //printMat(mat, nc, nr);

  int *bianchi, *neri, lenB, lenN;

  if(nr*nc%2 == 0){
    lenB = (nc*nr)/2;
    lenN = (nc*nr)/2;
  }else{
    lenB = (nc*nr)/2+1;
    lenN = (nc*nr)/2;
  }


  neri = malloc(lenB*sizeof(int)); 
  bianchi = malloc(lenN*sizeof(int)); 
  separa(mat, nc, nr, bianchi, neri);

  printVet(bianchi, lenB);
  printVet(neri, lenN);

  free(bianchi);
  free(neri);
  freeMat(mat, nc, nr);
  return 0;
}

int **malloc2dR(int nc, int nr){
  int **mat = (int **)malloc(nr*sizeof(int *));

  for(int i=0; i<nr; i++)
    mat[i] = malloc(nc * sizeof(int));

  return mat;
}

void freeMat(int **mat, int nc, int nr){
  for(int i=0; i<nr; i++)
    free(mat[i]);
  free(mat);
}

void readFile(FILE *infile, int **mat, int nc, int nr){
  for(int i=0; i<nr; i++)
    for(int k=0; k<nc; k++)
      fscanf(infile, "%d", &mat[i][k]);
}

void printMat(int **mat, int nc, int nr){
  for(int i=0; i<nr; i++){
    for(int k=0; k<nc; k++)
      printf("%d ", mat[i][k]);
    printf("\n");
  }
}

void separa(int **mat, int nc, int nr, int *bianchi, int *neri){
  int tot=0;
  for(int i=0; i<nr; i++){
    for(int k=0; k<nc; k++){
      if((i+k)%2 == 0)
        bianchi[tot/2] = mat[i][k];
      else
        neri[tot/2] = mat[i][k];
      tot+=1;
    }
  }
}


void printVet(int *vet, int len){
  for(int i=0; i<len; i++)
    printf("%d ", vet[i]);
  printf("\n");
}
