#ifndef DATE_H
#define DATE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Date Date;

Date *createData(struct Date *date, int dd, int mm, int yy);
void freeDate(struct Date *date);
int compareDate(struct Date *d1, struct Date *d2);
char *returnData(struct Date *date);

#endif
