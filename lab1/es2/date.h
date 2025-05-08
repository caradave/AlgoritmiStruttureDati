#ifndef DATE_H 
#define DATE_H 

#include <stdio.h>

typedef struct {
    int yy, mm, dd;
} Date;

int compareDate(Date d1, Date d2);

#endif
