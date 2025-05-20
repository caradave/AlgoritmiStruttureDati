#include "esercizio.h"

typedef struct Exercise{
  char name[100];
  int type, entry, out, prec, final, diff;
  float val;
} Exercise;

struct Exercise **readFile(FILE *infile, struct Exercise **e, int lenFile){
  *e = malloc(lenFile*sizeof(struct Exercise));

  char name[100];
  for(int i=0; i<lenFile; i++){
    fscanf(infile, "%s %d %d %d %d %d %f %d", name, &e[i]->type, &e[i]->entry, &e[i]->out, &e[i]->prec, &e[i]->final, &e[i]->val, &e[i]->diff);
    strcpy(e[i]->name, name);
  }

  return e;
}

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
