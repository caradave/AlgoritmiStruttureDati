#ifndef ESERCIZIO_H
#define ESERCIZIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Exercise Exercise;

struct Exercise *createExercise(char *name, int type, int entry, int out, int prec, int final, int diff, float val);
struct Exercise **readFile(FILE *infile, int lenFile);
void printExercises(Exercise **e, int len);
struct Exercise *exerciseCopy(Exercise *e1, Exercise *e2);
int getEntry(Exercise *e);
int getOut(Exercise *e);
int getDifficulty(Exercise *e);
int getAcro(Exercise *e);
int checkAcro(Exercise **e, int len);
int countDiffDiag(Exercise **e, int len);
float getValue(Exercise *e);
int getFinal(struct Exercise *e);
int getPrec(struct Exercise *e);

#endif
