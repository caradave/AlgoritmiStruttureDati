#include <stdio.h>
#include <stdlib.h>

typedef struct Att{
  int start, end;
} Att;

struct Att *readFile(FILE *infile, int lenFile, struct Att *a);
int powerset_div_conq(int pos, struct Att *val, struct Att *sol, int n, int start, struct Att *finalSol, int lenFinalSol);
int check(struct Att *a, int len);
int checkLenSol(struct Att *a, int len);
void transferSol(struct Att *a, struct Att *b, int len);
void printAtt(struct Att *a, int len);

int main(void){
  FILE *infile = fopen("att.txt", "r");
  int fileLen;
  
  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  fscanf(infile, "%d\n", &fileLen);

  struct Att *att = malloc(fileLen*sizeof(struct Att));
  struct Att *sol = malloc(fileLen*sizeof(struct Att));
  struct Att *finalSol = malloc(fileLen*sizeof(struct Att));

  att = readFile(infile, fileLen, att);
  
  int finalSolLen = powerset_div_conq(0, att, sol, fileLen, 0, finalSol, 0);
  printAtt(finalSol, finalSolLen);

  free(att);
  free(sol);
  free(finalSol);
  fclose(infile);
  return 0;
}

struct Att *readFile(FILE *infile, int lenFile, struct Att *a){
  for(int i=0; i<lenFile; i++)
    fscanf(infile, "%d %d\n", &a[i].start, &a[i].end);

  return a;
}


int powerset_div_conq(int pos, struct Att *val, struct Att *sol, int n, int start, struct Att *finalSol, int lenFinalSol) {
  int i;
  if (start >= n) {
    if(check(sol, pos) == 1){
      if(checkLenSol(sol, pos) > checkLenSol(finalSol, lenFinalSol)){
        transferSol(sol, finalSol, pos);
        lenFinalSol = pos;
      }
    }
    return lenFinalSol;
    
  }
  for (i = start; i < n; i++) {
    sol[pos] = val[i];
    lenFinalSol = powerset_div_conq(pos+1, val, sol, n, i+1, finalSol, lenFinalSol);
  }
  lenFinalSol = powerset_div_conq(pos, val, sol, n, n, finalSol, lenFinalSol);
  return lenFinalSol;
}

int check(struct Att *a, int len){
  for(int i=0; i<len-1; i++)
    for(int k=i+1; k<len; k++)
      if((a[i].start >= a[k].start && a[i].start <= a[k].start) || (a[i].end >= a[k].start && a[i].end <= a[k].end))
        return -1;
  return 1;
}

int checkLenSol(struct Att *a, int len){
  int lenSol=0;

  for(int i=0; i<len; i++)
    lenSol = lenSol + (a[i].end-a[i].start);
  
  return lenSol;
}

void transferSol(struct Att *a, struct Att *b, int len){
  for(int i=0; i<len; i++)
    b[i] = a[i];
}

void printAtt(struct Att *a, int len){
  for(int i=0; i<len; i++)
    printf("%d %d - ", a[i].start, a[i].end);
  printf("\n");
}
