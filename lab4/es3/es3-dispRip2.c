
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOUND 0;

typedef struct Pietra{
  char tipoPietra;
  int *numPietre;
} Pietra;

int disp_ripet(int pos, struct Pietra *val, char *sol, int n, int k, int count);
int check(char *sol, int lenSol);
int promising(char *sol, char add, int pos);
int checkNext(char *sol, struct Pietra *p, int pos);

int main(void){
  FILE *infile = fopen("hard_test_set.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  int lenFile;
  fscanf(infile, "%d\n", &lenFile);


  struct Pietra *forEach = malloc(4*sizeof(struct Pietra));
  for(int i=0; i<4; i++){
    forEach[i].numPietre = malloc(sizeof(int));
  }

  forEach[0].tipoPietra = 'z';
  forEach[1].tipoPietra = 'r';
  forEach[2].tipoPietra = 't';
  forEach[3].tipoPietra = 's';

  for(int i=0; i<lenFile; i++){
    printf("test %d\n", i+1);
    int maxLen = 0;
    for(int k=0; k<4; k++){
      fscanf(infile, "%d", forEach[k].numPietre);
      maxLen += *forEach[k].numPietre;
      printf("%d ", *(forEach[k].numPietre));
    }
  
    char *sol = malloc(maxLen*sizeof(char));
    
    printf("\n");
    int check=1, k, lenSol;
    char *finalSol = malloc(maxLen*sizeof(char));
    printf("max len: %d \n", maxLen);
    for(k=0; k<=maxLen && check == 1; k++){
      check = 0;
            check = disp_ripet(0, forEach, sol, 4, k, 0);
      if(check == 1){
        lenSol = k;
        strcpy(finalSol, sol);
      }
    }

    printf("len sol: %d - ", lenSol);
    for (int i=0; i<lenSol; i++)
      printf("%c ", finalSol[i]);
    printf("\n");
    printf("\n");

    free(sol);
  }
  
  for(int i=0; i<4; i++)
    free(forEach[i].numPietre);
  free(forEach);
  fclose(infile);
  return 0;
}

int check(char *sol, int lenSol){
  for(int i=0; i<lenSol-1; i++){
    switch (sol[i]){
    case 'z':
      if(sol[i+1] != 'z' && sol[i+1] != 'r')
        return -1;
    break;
    case 's':
      if(sol[i+1] != 's' && sol[i+1] != 't')
        return -1;
    break;
    case 'r':
      if(sol[i+1] != 's' && sol[i+1] != 't')
        return -1;
    break;
    case 't':
      if(sol[i+1] != 'z' && sol[i+1] != 'r')
        return -1;
    break;
    default:
      return -1;
    }
  }
  return 1;
}

int disp_ripet(int pos, struct Pietra *val, char *sol, int n, int k, int count) {

  if (pos >= k) {
    if(check(sol, k) == 1){
      return 1;
    }
    return 0;
  }
  for (int i = 0; i < n && count<1; i++) {
    if(*(val[i].numPietre) > 0 && (pos == 0 || promising(sol, val[i].tipoPietra, pos-1) == 1)){
      (*(val[i].numPietre))--;
      sol[pos] = val[i].tipoPietra;
      if(checkNext(sol, val, pos) == 1)
        count = disp_ripet(pos+1, val, sol, n, k, count);
      (*(val[i].numPietre))++;
      
    }
  }
  return count;
}

int checkNext(char *sol, struct Pietra *p, int pos){
  switch (sol[pos]){
    case 'z':
      if(*(p[0].numPietre) == 0 && *(p[1].numPietre) == 0)
        return -1;
    break;
    case 's':
      if(*(p[1].numPietre) == 0 && *(p[3].numPietre) == 0)
        return -1;
    break;
    case 'r':
      if(*(p[1].numPietre) == 0 && *(p[3].numPietre) == 0)
        return -1;
    break;
    case 't':
      if(*(p[0].numPietre) == 0 && *(p[2].numPietre) == 0)
        return -1;
    break;
    default:
    return -1;
  }
  return 1;
}

int promising(char *sol, char add, int pos){
    switch (sol[pos]){
    case 'z':
      if(add != 'z' && add != 'r')
        return -1;
    break;
    case 's':
      if(add != 's' && add != 't')
        return -1;
    break;
    case 'r':
      if(add != 's' && add != 't')
        return -1;
    break;
    case 't':
      if(add != 'z' && add != 'r')
        return -1;
    break;
    default:
      return -1;
    }
  return 1;
}
