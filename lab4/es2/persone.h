#ifndef PERSONE_H
#define PERSONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persone Persone;

struct Persone *createPersone(struct Persone *p, char *string);
void freePerona(struct Persone *persona);
void printPersona(struct Persone *persona);
int comparaDataNascita(struct Persone *p1, struct Persone *p2);
int comparaCodice(struct Persone *p1, char *cod);
#endif
