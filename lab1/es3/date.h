#ifndef DATE_H 
#define DATE_H 

#include <stdio.h>

typedef struct Date{
    int yy, mm, dd;
} Date;

typedef struct Time{
  int hh, min, sec;
} Time;

int compareDate(Date d1, Date d2);
int compareTime(Time t1, Time t2);

#endif
