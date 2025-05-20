#ifndef ESERCIZIO_H
#define ESERCIZIO_H

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
#include <stdlib.h>
#include <stdio.h>
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> Stashed changes
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> Stashed changes
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> Stashed changes
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
int countMinDiffDiag(Exercise **e, int len);

#endif
