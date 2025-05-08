#include <stdio.h>
#include <stdlib.h>

typedef struct Arco{
  int vert1, vert2;
} Arco;

void readFile(FILE *infile, int numArchi, int numVertici, int *vertivi, struct Arco *archi);
void vertexCover(struct Arco *archi, int *vertici, int numArchi, int numVertici);
void powerset_div_conq(int pos, int *val, int *sol, int n, int start, struct Arco *archi, int numArchi);
int checkVertexCover(struct Arco *archi, int numArchi, int lenSol, int *sol);

int main(void){
  FILE *infile = fopen("grafo.txt", "r");
  
  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }
  
  int numVertici, numArchi;
  fscanf(infile, "%d %d\n", &numVertici, &numArchi);

  int *vertici = malloc(numVertici * sizeof(int));
  struct Arco *archi = malloc(numArchi * sizeof(struct Arco));

  readFile(infile, numArchi, numVertici, vertici, archi);

  vertexCover(archi, vertici, numArchi, numVertici);

  fclose(infile);
  return 0;
}

void readFile(FILE *infile, int numArchi, int numVertici, int *vertici, struct Arco *archi){
  int count=0, vert1Nop, vert2Nop;

  for(int i=0; i<numArchi; i++){
    vert1Nop = 1;
    vert2Nop = 1;
    fscanf(infile, "%d %d\n", &archi[i].vert1, &archi[i].vert2);

    if(count < numVertici){
      for(int k=0; k<count; k++){
        if(archi[i].vert1 == vertici[k])
          vert1Nop = 0;
        if(archi[i].vert2 == vertici[k])
          vert2Nop = 0;
      }
      if(vert1Nop == 1){
        vertici[count] = archi[i].vert1;
        count++;
      }
      if(vert2Nop == 1){
        vertici[count] = archi[i].vert2;
        count ++;
      }
    }

  }
}

void vertexCover(struct Arco *archi, int *vertici, int numArchi, int numVertici){
  int *sol = malloc(numVertici*sizeof(int));
  powerset_div_conq(0, vertici, sol, numVertici, 0, archi, numArchi);
}

void powerset_div_conq(int pos, int *val, int *sol, int n, int start, struct Arco *archi, int numArchi) {
   int i;
   if (start >= n) {
    if(checkVertexCover(archi, numArchi, pos, sol) == 1){
        printf("{ ");
        for (i = 0; i < pos; i++)
          printf("%d ", sol[i]);
        printf("} \n");
    }
    return;
  }
   for (i = start; i < n; i++) {
      sol[pos] = val[i];
      powerset_div_conq(pos+1, val, sol, n, i+1, archi, numArchi);
   }
   powerset_div_conq(pos, val, sol, n, n, archi, numArchi);
   return;
}

int checkVertexCover(struct Arco *archi, int numArchi, int lenSol, int *sol){
  int check=1;
  
  if(lenSol == 0)
    return 0;

  for(int i=0; i<numArchi && check==1; i++){
    check = 0;
    for(int k=0; k<lenSol; k++){
      if(archi[i].vert1 == sol[k] || archi[i].vert2 == sol[k])
        check = 1;
    }
  }

  if(check == 1)
    return 1;

  return 0;
}
