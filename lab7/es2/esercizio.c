#include "esercizio.h"

typedef struct Exercise{
  char name[100];
  int type, entry, out, prec, final, diff;
  float val;
} Exercise;

struct Exercise *createExercise
