#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 5
#define MAXLEN 255

typedef struct Brani{
  char brani[MAXNUM][MAXLEN];
} Brani;

typedef struct Amico{
  int numeroBrani;
  struct Brani brani;
} Amico;

void readFile(FILE *infile, int lenFile, struct Amico *amici);
void combinazioniR(struct Amico *amici, char **sol, int lenFile, int posAmico, int posCanzone, int posSol);
void combinazioni(struct Amico *amici, int lenFile);
void printSol(char **sol, int lenSol);

int main(void){
  FILE *infile = fopen("brani.txt", "r");
  
  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  int lenFile;
  fscanf(infile, "%d\n", &lenFile);
  
  struct Amico *amici = malloc(lenFile*sizeof(struct Amico));
  readFile(infile, lenFile, amici);

  combinazioni(amici, lenFile);

  free(amici);
  return 0;
}

void readFile(FILE *infile, int lenFile, struct Amico *amici){
  for(int i=0; i<lenFile; i++){
    fscanf(infile, "%d\n", &amici[i].numeroBrani);
    for(int k=0; k<amici[i].numeroBrani; k++){
      fscanf(infile, "%s\n", amici[i].brani.brani[k]);
      //printf("%s\n", amici[i].brani.brani[i]);
    }
  } 
}

void combinazioni(struct Amico *amici, int lenFile){
  char **sol = malloc(lenFile*sizeof(char *));
  for(int i=0; i<lenFile; i++)
    sol[i] = malloc(MAXLEN*sizeof(char));

  int posAmico=0, posCanzone=0;

  combinazioniR(amici,sol, lenFile, posAmico, posCanzone, 0);

  //for(int i=0; i<lenFile; i++)
  //  free(sol[i]);
  //free(sol);
}

void printSol(char **sol, int lenSol){
  for(int i=0; i<lenSol; i++)
    printf("%s ", sol[i]);
  printf("\n");
}

void combinazioniR(struct Amico *amici, char **sol, int lenFile, int posAmico, int posCanzone, int posSol){
  if(posAmico == lenFile){
    printSol(sol, lenFile);
    return;
  }
  
  for(int i=0; i<amici[posAmico].numeroBrani; i++){
    sol[posAmico] = amici[posAmico].brani.brani[i];
    combinazioniR(amici, sol, lenFile, posAmico+1, posCanzone, posSol);
  }
  return;
}
