#include "date.h"


typedef struct Date{
  int dd, mm, yy;
} Date;

Date *createData(struct Date *date, int dd, int mm, int yy){
  date = malloc(sizeof(struct Date));
  
  date->dd = dd;
  date->mm = mm;
  date->yy = yy;
  
  return date;
}

void freeDate(struct Date *date){
  free(date);
}

char *returnData(struct Date *date){
  char *string = malloc(10*sizeof(char));
  sprintf(string, "%02d/%02d/%d", date->dd, date->mm, date->yy);
  return string;
}

int compareDate(struct Date *d1, struct Date *d2){
  if((d1->yy*10000 + d1->mm*100 + d1->dd) > (d2->yy*10000 + d2->mm*100 + d2->dd))
    return 1;

  if((d1->yy*10000 + d1->mm*100 + d1->dd) < (d2->yy*10000 + d2->mm*100 + d2->dd))
    return -1;

  return 0;
}
