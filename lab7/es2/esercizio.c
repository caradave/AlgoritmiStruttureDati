#include "esercizio.h"

typedef struct Exercise{
  char name[100];
  int type, entry, out, prec, final, diff;
  float val;
} Exercise;

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
struct Exercise **readFile(FILE *infile, struct Exercise **e, int lenFile){
  *e = malloc(lenFile*sizeof(struct Exercise));

  char name[100];
  for(int i=0; i<lenFile; i++){
    fscanf(infile, "%s %d %d %d %d %d %f %d", name, &e[i]->type, &e[i]->entry, &e[i]->out, &e[i]->prec, &e[i]->final, &e[i]->val, &e[i]->diff);
    strcpy(e[i]->name, name);
  }
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
struct Exercise *createExercise(char *name, int type, int entry, int out, int prec, int final, int diff, float val){
  struct Exercise *e = malloc(sizeof(struct Exercise));

  strcpy(e->name, name);
  e->type = type;
  e->entry = entry;
  e->out = out;
  e->prec = prec;
  e->final = final;
  e->diff = diff;
  e->val = val;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

  return e;
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
void printExercise(struct Exercise *e){
  printf("%s %d %d %d %d %d %f %d\n", e->name, e->type, e->entry, e->out, e->prec, e->final, e->val, e->diff);
}

int getType(struct Exercise *e){
  return e->type;
}

int getEntry(struct Exercise *e){
  return e->entry;
}

int getOut(struct Exercise *e){
  return e->out;
}
=======
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
struct Exercise **readFile(FILE *infile, int lenFile){
  struct Exercise **v;
  char name[100];

  v = malloc(lenFile*sizeof(struct Exercise));

  for(int i=0; i<lenFile; i++){
    v[i] = malloc(sizeof(struct Exercise));
    fscanf(infile, "%s %d %d %d %d %d %f %d", name, &v[i]->type, &v[i]->entry, &v[i]->out, &v[i]->prec, &v[i]->final, &v[i]->val, &v[i]->diff);
    strcpy(v[i]->name, name);
  }

  return v;
}

void printExercises(Exercise **e, int len){
  for(int i=0; i<len; i++){
    if(e[i] == NULL){
      printf("impossibile stampare, trovato NULL");
    }else
      printf("%s %d %d %d %d %d %.2f %d\n", e[i]->name, e[i]->type, e[i]->entry, e[i]->out, e[i]->prec, e[i]->final, e[i]->val, e[i]->diff);
  }
}

int getEntry(Exercise *e){
  if(e == NULL){
    printf("null");
    return -1;
  }
  return e->entry;
}

int getOut(Exercise *e){
  if(e == NULL){
    printf("null");
    return -1;
  }
  return e->out;
}

int getDifficulty(Exercise *e){
  return e->diff;
}

int getAcro(Exercise *e){
  return e->type;
}

int checkAcro(Exercise **e, int len){
  int count=0;
  
  if(e == NULL)
    return -1;

  for(int i=0; i<len; i++)
    if(getAcro(e[i]) != 0)
      count += 1;

  if(count == 0)
    return -1;
  return 1;
}

int countMinDiffDiag(Exercise **e, int len){
  int sum=0;
  for(int i=0; i<len; i++){
    sum += getDifficulty(e[i]);
  }
  return sum;
}
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
